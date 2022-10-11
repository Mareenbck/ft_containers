/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:47:39 by mbascuna          #+#    #+#             */
/*   Updated: 2022/10/11 18:06:43 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <iostream>
# include "vectorIterator.hpp"

namespace ft{

template <class T, class Allocator = std::allocator<T> >
class vector
{
	public:
		typedef T 									value_type;
		typedef Allocator 							allocator_type;
		typedef typename Allocator::reference 		reference;
		typedef typename Allocator::const_reference const_reference;
		typedef typename Allocator::pointer 		pointer;
		typedef typename Allocator::const_pointer 	const_pointer;
		typedef ft::vectorIterator<pointer> 		iterator;
		typedef ft::vectorIterator<const_pointer> 	const_iterator;
		// typedef std::reverse_iterator<iterator> reverse_iterator;
		// typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef std::ptrdiff_t difference_type;
		typedef std::size_t size_type;

	private:
			size_type _size;
			size_type _capacity;
			value_type *_arr;
			allocator_type _alloc;

	public:
	//CONSTRUCTEURS
		explicit vector(const allocator_type& alloc = allocator_type())
		{
			_alloc = alloc;
			_arr = _alloc.allocate(0);
			_size = 0;
			_capacity = 0;
		}

		explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		{
			_size = n;
			_capacity = n;
			_alloc = alloc;
			_arr = _alloc.allocate(n);
			for (size_t i = 0; i < n; i++)
				_alloc.construct(&_arr[i], val);
		}

		// template <class InputIterator> vector(InputIterator first, InputIterator last, const Allocator& allocator)
		// {

		// }

		vector(const vector& x)
		{
			_alloc = x._alloc;
			_capacity = x._capacity;
			_size = x._size;
			_arr = _alloc.allocate(_capacity);
			for (size_t i = 0; i < x._size; i++)
				_alloc.construct(&_arr[i], x._arr[i]);
		}

		virtual ~vector()
		{
			this->_alloc.deallocate(&_arr[0], this->_capacity);
			return;
		}

		//ITERATOR
		iterator begin(void)
		{
			return iterator(_arr);
		}

		iterator end(void)
		{
			return iterator(_arr + _size);
		}
};


}
#endif
