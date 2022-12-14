/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 09:34:52 by mbascuna          #+#    #+#             */
/*   Updated: 2022/11/14 16:36:33 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <cstddef>
# include <functional>
# include <stdexcept>
# include <limits>
# include "../iterators/reverseIterator.hpp"
# include "../utils/pair.hpp"
# include "../utils/rb_tree.hpp"
# include "../utils/algorithms.hpp"

namespace ft {

template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<Key, T> > >
class map {

	public:
		typedef Key 								key_type;
		typedef T 									mapped_type;
		typedef ft::pair<key_type, mapped_type> 	value_type;
		typedef Compare 							key_compare;
		typedef Allocator 							allocator_type;

	public:
		class value_compare
		{
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
		//Alloue de la memoire pour des types differents a celui du container
		typedef typename allocator_type::template rebind<value_type>::other		pair_allocator_type;
		typedef rb_tree<value_type, value_compare, pair_allocator_type> 		tree;
		typedef Node<value_type> 												node;
		typedef typename tree::pointer_node 									pointer_node;

	public:
		typedef value_type &								reference;
		typedef const value_type &							const_reference;
		typedef typename Allocator::pointer 				pointer;
		typedef typename Allocator::const_pointer 			const_pointer;
		typedef typename tree::iterator						iterator;
		typedef typename tree::const_iterator				const_iterator;
		typedef typename tree::reverse_iterator 			reverse_iterator;
		typedef typename tree::const_reverse_iterator		const_reverse_iterator;
		typedef std::ptrdiff_t								difference_type;
		typedef std::size_t 								size_type;

	private:
		tree			_tree;
		value_compare	_value_comp;
		key_compare 	_key_comp;
		allocator_type 	_alloc;

/***************************************CONSTRUCTORS****************************************/
	public:
		explicit map(void) : _tree(tree()), _value_comp(value_compare()), _key_comp(key_compare()), _alloc(allocator_type()) {}

		template <class InputIterator>
		map(InputIterator first, InputIterator last, const Compare& comp = Compare(), const allocator_type& alloc = allocator_type())
		{
			_key_comp = comp;
			_alloc = alloc;
			_value_comp = value_compare();
			_tree = tree();
			insert(first, last);
		}

		map(const map& x) { *this = x; }

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

		size_type size() const { return (_tree.get_size()); }

		size_type max_size() const
		{
			if (sizeof(T) == 8)
				return static_cast<size_type>(std::numeric_limits<size_type>::max() / (sizeof(ft::Node<value_type>) + sizeof(T)) / 2);
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
			size_type size_before = this->_tree.get_size();
			ft::pair<iterator, bool> res;
			res = ft::make_pair<iterator, bool>( insert(this->begin(), value), size_before != _tree.get_size());
			return (res);
		}

		iterator insert(iterator position, const_reference value)
		{
			(void)position;
			_tree.insert(value);
			return (iterator(_tree.search(value)));
		}

		template<class InputIterator>
		void insert(InputIterator first, InputIterator last)
		{
			for (; first != last; first++)
				_tree.insert(*first);
		}

		void erase(iterator position) { _tree.erase(position.base()); }

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

		size_type erase (const key_type& k)
		{
			size_type old_size = this->_tree.get_size();
			pointer_node p = _tree.search(ft::make_pair(k, mapped_type()));
			this->_tree.erase(p);
			return (old_size - this->_tree.get_size());
		}

		void swap(map& x) { _tree.swap(x._tree); }

		void clear() { _tree.clear(_tree.get_root()); }


/***************************************OBSERVERS****************************************/

		key_compare	  key_comp() const { return (this->_key_comp); }

		value_compare value_comp() const { return (value_compare(this->_key_comp)); }


/***************************************OPERATIONS****************************************/

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
			pointer_node n = _tree.search(ft::make_pair(k, mapped_type()));
			if (n)
				return (iterator(n));
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

/***************************************NON MEMBERS****************************************/

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
