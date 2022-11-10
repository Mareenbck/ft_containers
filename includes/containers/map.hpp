/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 09:34:52 by mbascuna          #+#    #+#             */
/*   Updated: 2022/11/10 19:30:45 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <cstddef>
# include <functional>
# include <stdexcept>
// # include "../iterators/treeIterator.hpp"
# include "../iterators/reverseIterator.hpp"
# include "../utils/pair.hpp"
# include "../utils/rb_tree.hpp"
# include "../utils/algorithms.hpp"

namespace ft {

template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
class map {

	public:
		typedef Key 								key_type;
		typedef T 									mapped_type;
		typedef ft::pair<const key_type, mapped_type> 		value_type;
		typedef Compare 									key_compare;
		typedef Allocator 									allocator_type;

	public:
		class value_compare
		{
			// friend class map<Key, T, Compare, Allocator>;
			protected:
				Compare _comp;
			public:
				typedef bool		result_type;
				typedef value_type	first_argument_type;
				typedef value_type	second_argument_type;
				value_compare() : _comp(Compare()) {}
				value_compare(Compare c) : _comp(c) {}
				~value_compare(void) {}
				value_compare& operator=(const value_compare& rhs)
				{
					_comp = rhs._comp;
					return *this;
				}
				//operator pour comparaison seulement des keys
				result_type operator()(const value_type& x, const value_type& y) const { return this->_comp(x.first, y.first);}
		};

	private:
		typedef typename allocator_type::template rebind<value_type>::other pair_allocator_type;
		typedef rb_tree<value_type, value_compare, pair_allocator_type> tree;
		typedef Node<value_type> node;
		typedef typename tree::pointer_node pointer_node;

	public:
		typedef std::size_t 								size_type;
		typedef std::ptrdiff_t								difference_type;
		typedef value_type &								reference;
		typedef const value_type &							const_reference;
		typedef typename Allocator::pointer 				pointer;
		typedef typename Allocator::const_pointer 			const_pointer;
		typedef typename tree::iterator						iterator;
		typedef typename tree::const_iterator				const_iterator;
		typedef typename tree::reverse_iterator 			reverse_iterator;
		typedef typename tree::const_reverse_iterator		 const_reverse_iterator;

	private:
		tree			_tree;
		value_compare	_value_comp;
		key_compare 	_key_comp;
		allocator_type 	_alloc;

/***************************************CONSTRUCTORS****************************************/
	public:
		map(void) : _tree(tree()), _value_comp(value_compare()), _key_comp(key_compare()), _alloc(allocator_type())
		{
		}
		explicit map(const Compare& comp, const allocator_type& alloc = allocator_type())
		{
			_tree = tree();
			_value_comp = value_compare();
			_key_comp = comp;
			_alloc = alloc;
		}

		template <class InputIterator>
		map(InputIterator first, InputIterator last, const Compare& comp = Compare(), const allocator_type& alloc = allocator_type())
		{
			_key_comp = comp;
			_alloc = alloc;
			_value_comp = value_compare();
			_tree = tree();
			insert(first, last);
		}

		map(const map& x)
		{
			*this = x;
		}

		~map() {}

		map& operator=(const map& x)
		{
			_alloc = x._alloc;
			_value_comp = x._value_comp;
			_key_comp = x._key_comp;
			if (_tree.get_size())
				clear();
			_tree.insert(x.begin(), x.end());
			return *this;
		}

/***************************************ITERATOR****************************************/

		iterator begin() {return (_tree.begin());}
		const_iterator begin() const {return _tree.begin();}
		iterator end() {return (_tree.end());}
		const_iterator end() const {return _tree.end();}
		reverse_iterator rbegin() { return (_tree.rbegin()); }
		const_reverse_iterator rbegin() const { return _tree.rbegin(); }
		reverse_iterator rend() { return (_tree.rend()); }
		const_reverse_iterator rend() const { return _tree.rend(); }

		/***************************************CAPACITY****************************************/
		bool empty() const
		{
			if (_tree.get_size() == 0)
				return true;
			else
				return false;
		}
		size_type size() const
		{
			return (_tree.get_size());
		}
		size_type max_size() const
		{
			return _tree.max_size();
		}

/***************************************ELEMENT ACCESS****************************************/
		mapped_type& operator[](const key_type& key)
		{
			iterator it = lower_bound(key);
			it = insert(it, ft::make_pair(key, T()));
			return (*it).second;
		}
		mapped_type& at(const key_type& key)
		{
			iterator it = lower_bound(key);
				if (it->first != key)
					throw std::out_of_range("map::at::out_of_range");
			return it->second;
		}

		mapped_type& at(const key_type& key) const
		{
			const_iterator it = lower_bound(key);
				if (it->first != key)
					throw std::out_of_range("map::at::out_of_range");
			return it->second;
		}

/***************************************MODIFIERS****************************************/

		ft::pair<iterator, bool> insert(const_reference value)
		{
			std::cout << " insert value " << value << std::endl;
			size_type size_before = this->_tree.get_size();
			/* bool : true si la pair a ete inseree */
			return (ft::make_pair<iterator, bool>( this->insert(this->begin(), value), size_before != this->_tree.get_size()));
		}

		//ne peut pas fonctionner car insert de tree est en void et ne renvoi pas un iterator
		// ft::pair<iterator, bool>	insert(const_reference value)
		// {
		// 	size_type	pre_size = size();
		// 	iterator node = _tree.insert(value);
		// 	return ft::make_pair(node, size() - pre_size);
		// }

		iterator insert(iterator position, const_reference value)
		{
			(void)position;
			_tree.insert(value);
			return (iterator(_tree.search(value)));
		}

		template<class InputIterator>
		void insert(InputIterator first, InputIterator last)
		{
			std::cout << "first " << first->second << std::endl;
			for (; first != last; first++)
				_tree.insert(*first);
		}

		void clear()
		{
			_tree.clear(_tree.get_root());
			// _tree.clear();
		}

		void erase(iterator position)
		{
			std::cout << "erase iterator\n";
			_tree.erase(position.base());
		}

		size_type erase (const key_type& k)
		{
			std::cout << "erase key type\n";
			size_type old_size = this->_tree.get_size();
			pointer_node p = _tree.search(ft::make_pair(k, mapped_type()));
			this->_tree.erase(p);
			/* Nb of elements erased */
			return (old_size - this->_tree.get_size());
		}

		void erase (iterator first, iterator last)
		{
			iterator tmp;
			while (first != last)
			{
				tmp = first;
				first++;
				erase(tmp);
			}
		}

		void swap(map& x)
		{
			_tree.swap(x._tree);
		}

/***************************************OBSERVERS****************************************/


		key_compare	  key_comp() const { return (this->_key_comp); }

		value_compare value_comp() const { return (value_compare(this->_key_comp)); }


/***************************************OPERATIONS****************************************/
		//preier element de la map dont la key est >= k
		//utilise key_comp(element, k) == false
		iterator lower_bound(const key_type& k)
		{
			for (iterator tmp = begin(); tmp != end(); tmp++)
				if (!(key_comp()(tmp->first, k)))
					return tmp;
			return end();
		}

		const_iterator lower_bound(const key_type& k) const
		{
			for (const_iterator tmp = begin(); tmp != end(); tmp++)
				if (!(key_comp()(tmp->first, k)))
					return tmp;
			return end();
		}

		iterator upper_bound(const key_type& k)
		{
			for (iterator tmp = begin(); tmp != end(); tmp++)
				if ((key_comp()(k, tmp->first)))
					return tmp;
			return end();
		}

		const_iterator upper_bound(const key_type& k) const
		{
			for (const_iterator tmp = begin(); tmp != end(); tmp++)
				if ((key_comp()(k, tmp->first)))
					return tmp;
			return end();
		}

		ft::pair<const_iterator,const_iterator> equal_range(const key_type& k) const
		{
			return ft::make_pair(lower_bound(k), upper_bound(k));
		}

		ft::pair<iterator,iterator>	equal_range(const key_type& k)
		{
			return ft::make_pair(lower_bound(k), upper_bound(k));
		}

		size_type count(const key_type& k) const
		{
			if (find(k) != end())
				return 1;
			return 0;
		}

		iterator find (const key_type& k)
		{
			//cheche dans tree
			pointer_node n = _tree.search(ft::make_pair(k, mapped_type()));
			if (n)
				return (iterator(n));
			//si il y a un node renvoie un iterator du node
			//sinon renvoi end()
			return end();
		}

		const_iterator find (const key_type& k) const
		{
			pointer_node n = _tree.search(ft::make_pair(k, mapped_type()));
			if (n)
				return (const_iterator(n));
			return end();
		}
	};

	template<class Key, class T, class Compare, class Alloc>
	bool operator==(map<Key, T, Compare, Alloc> const& lhs, map<Key, T, Compare, Alloc> const& rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class Key, class T, class Compare, class Allocator>
	bool operator!=(const ft::map<Key, T, Compare, Allocator> &lhs, const ft::map<Key, T, Compare, Allocator> &rhs)
	{
		return !(lhs == rhs);
	}
	template <class Key, class T, class Compare, class Allocator>
	bool operator<(const ft::map<Key, T, Compare, Allocator> &lhs, const ft::map<Key, T, Compare, Allocator> &rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}
	template <class Key, class T, class Compare, class Allocator>
	bool operator<=(const ft::map<Key, T, Compare, Allocator> &lhs, const ft::map<Key, T, Compare, Allocator> &rhs)
	{
		return !(lhs > rhs);
	}
	template <class Key, class T, class Compare, class Allocator>
	bool operator>(const ft::map<Key, T, Compare, Allocator> &lhs, const ft::map<Key, T, Compare, Allocator> &rhs)
	{
		return rhs < lhs;
	}
	template <class Key, class T, class Compare, class Allocator>
	bool operator>=(const ft::map<Key, T, Compare, Allocator> &lhs, const ft::map<Key, T, Compare, Allocator> &rhs)
	{
		return !(lhs < rhs);
	}
	template <class Key, class T, class Compare, class Alloc>
	void swap(map<Key, T, Compare, Alloc> &lhs, map<Key, T, Compare, Alloc> &rhs)
	{
		lhs.swap(rhs);
	}
}


#endif
