/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 09:34:52 by mbascuna          #+#    #+#             */
/*   Updated: 2022/10/19 14:59:28 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <cstddef>
# include <functional>
# include <stdexcept>
# include "../iterators/vectorIterator.hpp"
# include "../iterators/reverseIterator.hpp"

namespace ft {

template <class Key, class T, class Compare = less<Key>, class Allocator = allocator<pair<const Key, T> > >
class map {

	public:
		typedef Key 								key_type;
		typedef T 									mapped_type;
		typedef ft::pair<const Key, T> 				value_type;
		typedef Compare 							key_compare;
		typedef Allocator 							allocator_type;
		typedef typename Allocator::reference		reference;
		typedef typename Allocator::const_reference const_reference;
		typedef typename Allocator::pointer 		pointer;
		typedef typename Allocator::const_pointer 	const_pointer;
		// typedef ft::mapIterator<pointer> 		iterator;
		// typedef ft::mapIterator<const_pointer> 	const_iterator;
		typedef ft::reverse_iterator<iterator> 		reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef std::size_t 						size_type;
		typedef std::ptrdiff_t 						difference_type;

	class value_compare: public binary_function<value_type,value_type,bool> {
		friend class map;
			protected:
				Compare comp;
				value_compare(Compare c) : comp(c) {}
			public:
				bool operator()(const value_type& x, const value_type& y) const { return comp(x.first, y.first);

	private:
		key_type	_key;
		mapped_type	_map;
		key_compare _compare;
		allocator_type _alloc;

/***************************************CONSTRUCTORS****************************************/
	public:
		explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		{
			this->_alloc = alloc;
			this->_map = _alloc.allocate(0);
		}

		template <class InputIterator>
		map(InputIterator first, InputIterator last, const Compare& comp = Compare(), const Allocator& = Allocator());

		map(const map<Key,T,Compare,Allocator>& x);
		~map();
		map<Key,T,Compare,Allocator>&
		operator=(const map<Key,T,Compare,Allocator>& x);
}

#endif
