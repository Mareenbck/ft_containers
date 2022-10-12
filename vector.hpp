/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:47:39 by mbascuna          #+#    #+#             */
/*   Updated: 2022/10/12 18:37:46 by mbascuna         ###   ########.fr       */
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
		typedef value_type&							reference;
		typedef const value_type&					const_reference;
		typedef value_type*					 		pointer;
		typedef const value_type* 				 	const_pointer;
		typedef ft::vectorIterator<value_type> 		iterator;
		typedef ft::vectorIterator<value_type> 	const_iterator;
		// typedef std::reverse_iterator<iterator> reverse_iterator;
		// typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
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
			this->_arr = this->_alloc.allocate(n);
			for (size_t i = 0; i < n; i++)
				this->_alloc.construct(&this->_arr[i], val);
		}

		// template <class InputIterator>
		// vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
		// {
		// 	this->_alloc = alloc;
		// 	this->_size = last - first;
		// 	this->_capacity = last - first;
		// 	this->_arr = this->_alloc(this->_capacity);
		// 	for (; first != last; first++)
		// 		push_back(*first);
		// }

		vector(const vector& x)
		{
			*this = x;
		}

		vector& operator=(const vector& x)
		{
			this->_alloc = x._alloc;
			this->_capacity = x._capacity;
			this->_size = x._size;
			this->_arr = this->_alloc.allocate(this->_capacity);
			for (size_t i = 0; i < x._size; i++)
				this->_alloc.construct(&this->_arr[i], x._arr[i]);
			return *this;
		}

		virtual ~vector()
		{
			this->_alloc.deallocate(&this->_arr[0], this->_capacity);
			return;
		}

		template <class InputIterator>
		void assign(InputIterator first, InputIterator last)
		{
			// if ((last - first)> max_size())
			// 	return;
			clear();
			// resize(n, u);
			insert(begin(), first, last);
		}

		void assign(size_type n, const T& u)
		{
			if (n > max_size())
				return;
			clear();
			resize(n, u);
			for (size_type i = 0; i < _size; i++)
				_arr[i] = u;
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
			else
			 	return;
		}

		size_type capacity() const
		{
			return this->_capacity;
		}

		bool empty() const
		{
			if (&this->_arr[0] != NULL)
				return false;
			else
				return true;
		}

		void reserve(size_type n)
		{
			pointer newArr;

			if (_capacity <= n)
				return ;
			newArr = _alloc.allocate(n);
			for (size_type i = 0; i < _size; i++)
			{
				_alloc.construct(&newArr[i], _arr[i]);
				_alloc.destroy(&_arr[i]);
			}
			this->_alloc.deallocate(&this->_arr[0], this->_capacity);
			this->_arr = newArr;
			this->_capacity = n;
		}

		//MODIFIERS
		void push_back(const T& x)
		{
			if (_capacity == 0)
				reserve(0);
			if (_size + 1 > _capacity)
				reserve(_capacity * 2);
			_alloc.construct(&_arr[_size], x);
			_size++;
		}

		iterator insert(iterator position, const T& x)
		{
			size_type pos = position - begin();

			if (_capacity == 0)
				reserve(1);
			if (_size + 1 > _capacity)
				reserve(_capacity * 2);
			if (_size > 0)
			{
				this->_alloc.construct(&_arr[_size], _arr[_size - 1]);
				for (size_type i = this->_size - 1; i > pos; i--)
				{
					_arr[i] = _arr[i - 1];
					// this->_alloc.construct(&_arr[i + 1], _arr[i]);
					// this->_alloc.destroy(&_arr[i]);
				}
				_arr[pos] = x;
				// this->_alloc.construct(&_arr[pos], x);
			}
			else
				_alloc.construct(&_arr[0], x);
			this->_size++;
			return (begin() + pos);
		}

		void insert(iterator position, size_type n, const T& x)
		{
			size_type pos = position - begin();

			if (n < 1)
				return ;
			if (_size + n > _capacity)
				reserve(_capacity + n);
			for (size_type i = _size - 1; i < _size + n - 1; ++i)
			{
				_alloc.construct(&_arr[i + 1], _arr[i]);
			}
			_size += n;
			for (size_type i = _size - n; i >= pos + n; i--)
				_arr[i] = _arr[i - n];
			for (; n > 0; n--)
				_arr[pos + n - 1] = x;
		}

		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last)
		{
			//pour avoir la diff (connaitre n )entre deux iterator => faire une boucle for avec un tmp = first qui parcours jusuqi au last
			// if (_size + n > _capacity)
			// 	reserve(_capacity + n);
			//alouer de la mem avec construct de 0 de la fin jusquai taille de la diff
			//la size augmente donc de tmp
			//commencer par decaler les valeurs en allant a la fin du nouveau tableau et collant tant que tmp la fin de lancier
			//mettre les valeur dans l'arr a partir de la position en collant *first
			//si la size etait egale a 0 > commencer au debut
		}

		iterator erase(iterator position)
		{
			size_type pos = position - begin();

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
				erase(last);
				last--;
			}
			return (last);
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
			// if (n > _size)
			// 	return 0;
			return this->_arr[n];
		}
		reference at(size_type n)
		{
			// if (n > _size)
			// 	return 0;
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

	// template <class T, class Allocator>
	// 	bool operator==(const vector<T,Allocator>& x, const vector<T,Allocator>& y);
	// template <class T, class Allocator>
	// 	bool operator< (const vector<T,Allocator>& x, const vector<T,Allocator>& y);
	// template <class T, class Allocator>
	// 	bool operator!=(const vector<T,Allocator>& x,const vector<T,Allocator>& y);
	// template <class T, class Allocator>
	// 	bool operator> (const vector<T,Allocator>& x, const vector<T,Allocator>& y);
	// template <class T, class Allocator>
	// 	bool operator>=(const vector<T,Allocator>& x,const vector<T,Allocator>& y);
	// template <class T, class Allocator>
	// 	bool operator<=(const vector<T,Allocator>& x,const vector<T,Allocator>& y);
	// template <class T, class Allocator>
	// 	void swap(vector<T,Allocator>& x, vector<T,Allocator>& y);

}
#endif
