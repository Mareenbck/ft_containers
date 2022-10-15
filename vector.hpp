/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:47:39 by mbascuna          #+#    #+#             */
/*   Updated: 2022/10/15 17:19:47 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <iostream>
# include "vectorIterator.hpp"
# include "reverseIterator.hpp"
# include "enable_if.hpp"
# include "is_integral.hpp"
# include "algorithms.hpp"

namespace ft{

template <class T, class Allocator = std::allocator<T> >
class vector
{
	public:
		typedef T 									value_type;
		typedef Allocator 							allocator_type;
		// typedef value_type&							reference;
		// typedef const value_type&					const_reference;
		// typedef value_type*					 		pointer;
		// typedef const value_type* 				 	const_pointer;
		typedef typename Allocator::reference  		reference;
		typedef typename Allocator::const_reference 	const_reference;
		typedef typename Allocator::pointer 		pointer;
		typedef typename Allocator::const_pointer 	const_pointer;
		typedef ft::vectorIterator<pointer> 		iterator;
		typedef ft::vectorIterator<const_pointer> 	const_iterator;
		typedef ft::reverse_iterator<iterator> 		reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef std::size_t 						size_type;
		typedef std::ptrdiff_t 						difference_type;

	private:
			size_type _size;
			size_type _capacity;
			value_type *_arr;
			allocator_type _alloc;

	public:
	//CONSTRUCTEURS
		explicit vector(const allocator_type& alloc = allocator_type())
		{
			this->_alloc = alloc;
			this->_arr = _alloc.allocate(0);
			this->_size = 0;
			this->_capacity = 0;
		}

		explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		{
			this->_size = n;
			this->_capacity = n;
			this->_alloc = alloc;
			this->_arr = _alloc.allocate(n);
			for (size_t i = 0; i < n; i++)
				this->_alloc.construct(&this->_arr[i], val);
		}

		template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),  typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
			{
				this->_alloc = alloc;
				InputIterator tmp = first;
				size_t n = 0;
				while (tmp++ != last)
					n++;
				this->_size = n;
				this->_capacity = n;
				this->_arr = _alloc.allocate(n);
				for (size_t i = 0; i <= n; i++)
				{
					this->_alloc.construct(&this->_arr[i], *first);
					first++;
				}
			}

		vector(const vector& x)
		{
			_size = x._size;
			_capacity = _size;
			_alloc = x._alloc;
			_arr = _alloc.allocate(_capacity);
			for (size_type i = 0; i < _capacity; i++)
			{
				_alloc.construct(&_arr[i], x._arr[i]);
			}
		}

		vector& operator=(const vector& x)
		{
			if (this != &x)
			{
				_alloc = x._alloc;
				assign(x.begin(), x.end());
			}
			return *this;
		}

		~vector()
		{
			for (size_type i = 0; i < size(); i++)
				_alloc.destroy(&_arr[i]);
			_alloc.deallocate(_arr, capacity());
		}

		template <class InputIterator>
		void assign(InputIterator first, InputIterator last,  typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
		{
			pointer newArray;
			size_type n = 0;

			for (InputIterator it = first; it != last; ++it)
					n++;
			if (n > max_size())
				return ;
			if (n > capacity())
				newArray = _alloc.allocate(n);
			else
				newArray = _alloc.allocate(capacity());
			size_t	i = 0;
			for (InputIterator it = first; it != last; ++it)
				_alloc.construct(&newArray[i++], *it);
			for (iterator it = begin(); it != end(); ++it)
				_alloc.destroy(&(*it));
			_alloc.deallocate(_arr, capacity());
			if (n > capacity())
				_capacity = n;
			_arr = newArray;
			_size = n;
		}

		void assign(size_type n, const T& u)
		{
			if (n > max_size())
				return;
			clear();
			insert(begin(), n, u);
		}

		allocator_type get_allocator() const
		{
			return this->_alloc;
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

		const_iterator begin(void) const
		{
			return const_iterator(_arr);
		}

		const_iterator end(void) const
		{
			return const_iterator(_arr + _size);
		}

		reverse_iterator rbegin(void)
		{
			return reverse_iterator(end());
		}
		reverse_iterator rend(void)
		{
			return reverse_iterator(begin());
		}
		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(end());
		}
		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(begin());
		}
		//CAPACITY
		size_type size() const
		{
			return this->_size;
		}

		size_type max_size() const
		{
			return this->_alloc.max_size();
		}

		void resize(size_type n, value_type val = value_type())
		{
			if (n > size())
				insert(end(), n-size(), val);
			else if (n < size())
				erase(begin()+n, end());
			_size = n;
		}

		size_type capacity() const
		{
			return this->_capacity;
		}

		bool empty() const
		{
			if (begin() == end())
				return true;
			else
				return false;
		}

		void reserve(size_type n)
		{
			pointer newArr;

			if (n <= _capacity)
				return ;
			if (n > _alloc.max_size())
				throw std::length_error("vector::reserve");
			newArr = _alloc.allocate(n);
			for (size_type i = 0; i < size(); i++)
				_alloc.construct(&newArr[i], _arr[i]);
			for (size_type i = 0; i < size(); i++)
				_alloc.destroy(&_arr[i]);

			this->_alloc.deallocate(_arr, capacity());
			this->_arr = newArr;
			this->_capacity = n;
		}

		//MODIFIERS
		void push_back(const T& x)
		{
			if (_capacity == 0)
				reserve(1);
			if (_size + 1 > _capacity)
				reserve(_capacity * 2);
			_alloc.construct(&_arr[_size], x);
			_size++;
			// _capacity++;
		}

		void pop_back(void)
		{
			_alloc.destroy(&_arr[_size]);
			_size--;
		}

		iterator insert(iterator position, const T& x)
		{
			// PROBLEME SUR CE TEST vct2.insert(vct2.end() - 2, 42);
			size_type pos = position - begin();
			if (_capacity == 0)
				reserve(1);
			if (_size >= _capacity)
				reserve(_capacity * 2);
			if (!empty())
			{
				this->_alloc.construct(&_arr[_size], _arr[_size - 1]);
				for (size_type i = _size - 1; i > pos; i--)
					_arr[i] = _arr[i - 1];
				// _arr[pos] = x;
				// _alloc.construct(&(*position), x);
			}
			else
				_alloc.construct(&_arr[0], x);
			_size++;
			_capacity++;
			return (position);
		}

		void insert(iterator position, size_type n, const T& x)
		{
			size_type pos = position - begin();

			if (n < 1)
				return ;
			if (_size + n > _capacity)
				reserve(_capacity + n + 1);
			for (size_type i = _size -1; i < _size + n; i++)
			{
				// std::cout << "arr " << _arr[i] << std::endl;
				_alloc.construct(&_arr[i + 1], _arr[i]);
			}
			// for (size_type i = _size + n; i > 0; i--)
			// {
			// 	_arr[i] = _arr[i - 1];
			// 	std::cout << i << " " << _arr[i] << std::endl;
			// }
			_size += n;
			for (size_type i = _size - n; i >= pos + n; i--)
				_arr[i] = _arr[i - n];
			for (; n > 0; n--)
				_arr[pos + n - 1] = x;
			_capacity = _size;

		}

		template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last,  typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
			{
			//*********************************
				size_type n = 0;
				size_type pos = position - begin();
				// pointer newArray;
				for (InputIterator it = first; it != last; it++)
					n++;
				if (n == 1)
					insert(position, *first);
				if (_size == 0)
				{
					while (first++ != last)
						_alloc.construct(&_arr[0], *first);
				}
				if (_size + n > _capacity)
					reserve(_size + n);
				// 	// newArray = _alloc.allocate(_size + n);
				// 	// size_t	i = 0;
				// 	// for (iterator it = begin(); i < pos; i++)
				// 	// 	_alloc.construct(&newArray[i], *it++);
				// 	// for (InputIterator it = first; it != last; it++)
				// 	// 	_alloc.construct(&newArray[i++], *it);
				// 	// if (i < (_size + n))
				// 	// {
				// 	// 	for (iterator it = begin() + i; it != end(); it++)
				// 	// 		_alloc.construct(&newArray[i++], *it);
				// 	// }
				// 	// for (iterator it = begin(); it != end(); ++it)
				// 	// 	_alloc.destroy(&(*it));
				// 	// _alloc.deallocate(_arr, capacity());
				// 	// if (n > capacity())
				// 	// 	_capacity = n;
				// 	// _arr = newArray;
				// 	// _size = n;
				// }

				for (size_type i = _size - 1; i < (_size + n); i++)
				{
					_alloc.construct(&_arr[i + 1], _arr[i]);
				}
				_size += n;
				//FONCTIONNE PORU BIDIRECT MAIS PAS POUR INSERT
				for (InputIterator it = first; it != last; it++)
				{
					_alloc.construct(&_arr[pos], *it);
					pos++;
				}
				//FONCTIONNE POUR INSERT 2 MAIS PAS POUR BIDIRECT
				// for(InputIterator it = first; pos <= n; pos++)
				// {
				// 		_alloc.construct(&_arr[pos], *it);
				// 		it++;
				// }
				_arr[pos] = *last;
				_capacity = _size;
			}

		iterator erase(iterator position)
		{
			size_type pos = position - begin();
			if (pos + 1 >= _size)
			{
				pop_back();
				return end();
			}
			this->_alloc.destroy(&_arr[pos]);
			this->_alloc.construct(&_arr[pos], _arr[pos + 1]);
			for (size_type i = pos + 1; i < _size - 1; i++)
				_arr[i] = _arr[i + 1];
			this->_alloc.destroy(&_arr[_size - 1]);
			this->_size--;
			return (begin() + pos);
		}

		iterator erase(iterator first, iterator last)
		{
			while (first != last)
			{
				erase(--last);
				// last--;
			}
			return (last);
		}

		void swap (vector& x)
		{
			pointer tmpArr = _arr;
			_arr = x._arr;
			x._arr = tmpArr;

			size_type tmpCapacity = _capacity;
			_capacity = x._capacity;
			x._capacity = tmpCapacity;

			size_type	tmpSize = _size;
			_size = x._size;
			x._size = tmpSize;
		}

		void clear()
		{
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(&_arr[i]);
			_size = 0;
		}

		//ELEMENT ACCESS
		reference operator[](size_type n)
		{
			return this->_arr[n];
		}

		const_reference operator[](size_type n) const
		{
			return this->_arr[n];
		}
		const_reference at(size_type n) const
		{
			if (n >= _size)
				throw std::out_of_range("vector : out_of_range");
			return this->_arr[n];
		}
		reference at(size_type n)
		{
			if (n >= _size)
				throw std::out_of_range("vector : out_of_range");
			return this->_arr[n];
		}
		reference front()
		{
			return this->_arr[0];
		}
		const_reference front() const
		{
			return this->_arr[0];
		}
		reference back()
		{
			return this->_arr[_size - 1];
		}
		const_reference back() const
		{
			return this->_arr[_size - 1];
		}

};

	template <class T, class Allocator>
		bool operator==(const vector<T,Allocator>& x, const vector<T,Allocator>& y) {
			if (x.size() != y.size())
				return false;
			for (size_t i = 0; i < x.size(); i++)
			{
				if (x[i] != y[i])
					return false;
			}
			return true;
		}

	template <class T, class Allocator>
		bool operator!=(const vector<T,Allocator>& x,const vector<T,Allocator>& y){
			return !(x == y);
		}
	template <class T, class Allocator>
		bool operator<(const vector<T,Allocator>& x, const vector<T,Allocator>& y) {
			return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
		}
	template <class T, class Allocator>
		bool operator>(const vector<T,Allocator>& x, const vector<T,Allocator>& y){
			return ft::lexicographical_compare(y.begin(), y.end(), x.begin(), x.end());
		}
	template <class T, class Allocator>
		bool operator>=(const vector<T,Allocator>& x,const vector<T,Allocator>& y) {
			return !(x < y);
		}
	template <class T, class Allocator>
		bool operator<=(const vector<T,Allocator>& x,const vector<T,Allocator>& y) {
			return !(x > y);
		}
	template <class T, class Allocator>
		void swap(vector<T,Allocator>& x, vector<T,Allocator>& y) {
			x.swap(y);
		}

}
#endif
