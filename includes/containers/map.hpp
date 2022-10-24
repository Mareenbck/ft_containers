/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 09:34:52 by mbascuna          #+#    #+#             */
/*   Updated: 2022/10/24 19:59:52 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <cstddef>
# include <functional>
# include <stdexcept>
# include "../iterators/treeIterator.hpp"
# include "../iterators/reverseIterator.hpp"
// # include "../utils/pair.hpp"
# include "../utils/rb_tree.hpp"

namespace ft {

template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<Key, T> > >
class map {

	public:
		typedef Key 								key_type;
		typedef T 									mapped_type;
		typedef ft::pair<key_type, mapped_type> 		value_type;
		typedef Compare 							key_compare;
		typedef Allocator 							allocator_type;
		typedef std::size_t 						size_type;

		class value_compare : public std::binary_function<value_type, value_type, bool>
		{
			protected:
				Compare _comp;
			public:
				value_compare() : _comp(Compare()) {}
				value_compare(Compare c) : _comp(c) {}
				~value_compare(void) {}
				value_compare& operator=(const value_compare& rhs)
				{
					_comp = rhs._comp;
					return *this;
				}
				//operator pour comparaison seulement des keys
				bool operator()(const value_type& x, const value_type& y) const { return _comp(x.first, y.first);}
		};

	private:
		typedef ft::rb_tree<value_type, value_compare> tree;
		typedef typename tree::node Node;

	public:
		typedef typename Allocator::reference		reference;
		typedef typename Allocator::const_reference const_reference;
		typedef typename Allocator::pointer 		pointer;
		typedef typename Allocator::const_pointer 	const_pointer;
		// typedef ft::treeIterator<pointer> 		iterator;
		// typedef ft::treeIterator<const_pointer> 	const_iterator;
		// typedef ft::reverse_iterator<iterator> 		reverse_iterator;
		// typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef typename tree::iterator iterator;
		typedef typename tree::const_iterator const_iterator;
		typedef typename tree::reverse_iterator reverse_iterator;
		typedef typename tree::const_reverse_iterator const_reverse_iterator;

		// typedef std::ptrdiff_t 						difference_type;

		// typedef typename tree::pointer_node pointer_node;
		typedef typename allocator_type::template rebind<Node>::other node_allocator;


	private:
		tree			_tree;
		value_compare	_value_comp;
		key_compare 	_key_comp;
		allocator_type 	_alloc;

/***************************************CONSTRUCTORS****************************************/
	public:
		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		{
			_key_comp = comp;
			_alloc = alloc;
			_value_comp = value_compare();
			_tree = tree();
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
		iterator rbegin() {return (_tree.rbegin());}
		const_iterator rbegin() const {return _tree.rbegin();}
		iterator rend() {return (_tree.rend());}
		const_iterator rend() const {return _tree.rend();}

/***************************************CAPACITY****************************************/
		bool empty() const
		{
			if (this->_tree.get_size() == 0)
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
			return this->_alloc.max_size();
		}

/***************************************ELEMENT ACCESS****************************************/
		mapped_type& operator[](const key_type& k)
		{
			//se servir de search de tree
			//et renvoyer la key du node, ou creer le node avec value NULL ?
		// (*((insert(make_pair(x, T()))).first)).second.
		// return this->_arr[n];
			return (insert(ft::make_pair<key_type,  mapped_type>(k, T())).first->second);
		}
		// mapped_type& at (const key_type& k)
		// {
		// 	//se servir de search
		// 	//si pas trouve throw exception out of range
		// }
		// mapped_type& at (const key_type& k) const
		// {

		// }

/***************************************MODIFIERS****************************************/
		pair<iterator,bool> insert (const value_type& val)
		{
			//if l'elemet inserer existe deja => return un iterator sur cet element

			//inserer value dans l'arbre
			//creer un pair
			size_type x = size();
			iterator node = _tree.insert(val);
			// pair<iterator, bool>	new_pair;
			//le first du pair = find(val.first)
			// new_pair.first = insert(this->begin(), val);
			//le second du new_pair = bool qui dit si ancienne taille est egale a la nouvelle taile
			// new_pair.second = (x != size());
			//return la new_pair
			return ft::make_pair(node, size() - x);
		}

		iterator insert (iterator position, const value_type& val)
		{
			(void)position;
			return insert(val).first;
			// return (iterator(this->_tree.search(val)));
		}

		template<class InputIterator>
		void insert(InputIterator first, InputIterator last)
		{
			for (; first != last; first++)
				_tree.insert(*first);
		}

		void clear()
		{
			_tree.clear(_tree.get_root());
		}
	};
}


#endif
