/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:47:39 by mbascuna          #+#    #+#             */
/*   Updated: 2022/11/15 17:19:55 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <iostream>
# include "../iterators/vectorIterator.hpp"
# include "../iterators/reverseIterator.hpp"
# include "../utils/enable_if.hpp"
# include "../utils/algorithms.hpp"
# include "../utils/is_integral.hpp"

namespace ft {

template <class T, class Allocator = std::allocator<T> >
class vector
{
	public:
		typedef T 									value_type;
		typedef Allocator 							allocator_type;
		typedef typename Allocator::reference  		reference;
		typedef typename Allocator::const_reference const_reference;
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

/***************************************CONSTRUCTORS****************************************/
	public:
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
			for (size_type i = 0; i < n; i++)
				this->_alloc.construct(&this->_arr[i], val);
		}

		template <class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),  typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
			{
				this->_alloc = alloc;
				size_t n = 0;
				for (InputIterator it = first; it != last; ++it)
					n++;
				this->_size = n;
				this->_capacity = n;
				this->_arr = _alloc.allocate(n);
				for (size_t i = 0; i < _size; i++)
				{
					this->_alloc.construct(&this->_arr[i], *first);
					first++;
				}
			}

		vector(const vector& x)
		{
			_size = x._size;
			_capacity = x._size;
			_alloc = x._alloc;
			_arr = _alloc.allocate(_capacity);
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(&_arr[i], x._arr[i]);
		}

		~vector()
		{
			for (size_type i = 0; i < size(); i++)
				_alloc.destroy(&_arr[i]);
			_alloc.deallocate(_arr, capacity());
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

		template <class InputIterator>
		void assign(InputIterator first, InputIterator last,  typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
		{
			size_type n = 0;

			for (InputIterator it = first; it != last; ++it)
					n++;
			if (n > max_size())
				return ;
			clear();
			if (n > _capacity)
			{
				_alloc.deallocate(_arr, capacity());
				_arr = _alloc.allocate(n);
				_capacity = n;
			}
			_size = n;
			size_type i = 0;
			for (InputIterator it = first; it != last; it++)
				_alloc.construct(&_arr[i++], *it);
		}

		void assign(size_type n, const T& u)
		{
			if (n > max_size())
				return;
			clear();
			insert(begin(), n, u);
		}

		allocator_type get_allocator() const { return this->_alloc; }

/***************************************ITERATOR****************************************/

		iterator begin(void) { return iterator(_arr); }
		iterator end(void) { return iterator(_arr + _size); }

		const_iterator begin(void) const { return const_iterator(_arr); }
		const_iterator end(void) const { return const_iterator(_arr + _size); }

		reverse_iterator rbegin(void) { return reverse_iterator(end()); }
		reverse_iterator rend(void) { return reverse_iterator(begin()); }

		const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }
		const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

/***************************************CAPACITY****************************************/

		size_type size() const { return this->_size; }

		size_type max_size() const { return this->_alloc.max_size(); }

		size_type capacity() const { return this->_capacity; }

		void resize(size_type n, value_type val = value_type())
		{
			if (n > size())
				insert(end(), n-size(), val);
			else if (n < size())
				erase(begin()+n, end());
			_size = n;
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
			if (n > _alloc.max_size())
				throw std::length_error("vector::reserve");
			if (capacity() < n)
			{
				pointer newArr = _alloc.allocate(n);
				for (size_type i = 0; i < size(); i++)
					_alloc.construct(&newArr[i], _arr[i]);
				for (size_type i = 0; i < size(); i++)
					_alloc.destroy(&_arr[i]);
				_alloc.deallocate(_arr, capacity());
				_arr = newArr;
				_capacity = n;
			}
		}

/***************************************MODIFIERS**********************************************/

		void push_back(const T& x)
		{
			if (size() >= capacity())
			{
				size_type	newCap = capacity() * 2;
				if (newCap == 0) newCap = 1;
				pointer newArr = _alloc.allocate(newCap);
				for (size_type i = 0; i < size(); i++)
				{
					_alloc.construct(&newArr[i], _arr[i]);
					_alloc.destroy(&_arr[i]);
				}
				_alloc.construct(&newArr[_size], x);
				_alloc.deallocate(_arr, capacity());
				_capacity = newCap;
				_arr = newArr;
			}
			else
				_alloc.construct(&_arr[_size], x);
			_size++;
		}

		void pop_back(void)
		{
			// if (size() > 0)
			// {
				_alloc.destroy(&back());
				_size--;
			// }
		}

		iterator insert(iterator position, const T& x)
		{
			size_type pos = position - begin();
			if (_size + 1 > _capacity)
			{
				size_type i = 0;
				size_type newSize = _size + 1;
				pointer newArr = _alloc.allocate(capacity() * 2);
				for (; i < pos; i++)
					_alloc.construct(&newArr[i], _arr[i]);
				_alloc.construct(&newArr[pos], x);
				++i;
				for (; i <= size(); i++)
					_alloc.construct(&newArr[i], _arr[i - 1]);
				clear();
				_alloc.deallocate(_arr, capacity());
				_arr = newArr;
				_size = newSize;
				_capacity = capacity() * 2;
				return (pos + begin());
			}
			if (!empty())
			{
				_alloc.construct(&_arr[_size], _arr[_size - 1]);
				for (size_type i = _size; i > pos; i--)
					_arr[i] = _arr[i - 1];
				_arr[pos] = x;
			}
			else
				_alloc.construct(&_arr[0], x);
			_size++;
			return (position);
		}

		void insert(iterator position, size_type n, const T& x)
		{
			if (n < 1)
				return ;
			size_type pos = position - begin();
			size_type i = 0;
 			if (_size + n >= _capacity)
			{
				size_type newCap = _size + n;
				if (newCap <= (2 * _capacity))
				{
					newCap = 2 * _size;
					if (newCap < size() + n)
						newCap = size() + n;
				}
				pointer newArr = _alloc.allocate(newCap);
				for (; i < pos; i++)
					_alloc.construct(&newArr[i], _arr[i]);
				for (size_type j = 0; j < n; j++)
					_alloc.construct(&newArr[i++], x);
				for (; i < _size + n; i++)
					_alloc.construct(&newArr[i], _arr[i - n]);
				size_type newSize = _size + n;
				clear();
				_alloc.deallocate(_arr, capacity());
				_arr = newArr;
				_size = newSize;
				_capacity = newCap;
				return ;
			}
			i = size() + n;
			while (i > pos + n)
			{
				if (i > _size)
					_alloc.construct(&_arr[i - 1], _arr[i - n -1]);
				else
					_arr[i - 1] = _arr[i - n - 1];
				--i;
			}
			while (i > pos)
			{
				if (i > size())
					_alloc.construct(&_arr[i - 1], x);
				else
					_arr[i - 1] = x;
				--i;
			}
			_size += n;
		}

		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last,  typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
		{
			// size_type i = last - first;
			// if (i + size() >= _capacity)
			// {
			// 	size_type newCap = _size + i;
			// 	if (newCap <= (2 * _capacity))
			// 	{
			// 		newCap = 2 * _size;
			// 		if (newCap < size() + i)
			// 			newCap = size() + i;
			// 	}
			// 	_capacity = newCap;
			// }
			for (InputIterator it = first; it != last; it++)
			{
				position = insert(position, *it);
				position++;
			}
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
				erase(--last);
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

/***************************************ELEMENT ACCESS****************************************/

		reference operator[](size_type n) { return this->_arr[n]; }
		const_reference operator[](size_type n) const { return this->_arr[n]; }

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

		reference front() { return this->_arr[0]; }
		const_reference front() const { return this->_arr[0]; }

		reference back() { return this->_arr[_size - 1]; }
		const_reference back() const { return this->_arr[_size - 1]; }
};

/***************************************NON MEMBER****************************************/

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
