/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:50:41 by mbascuna          #+#    #+#             */
/*   Updated: 2022/10/12 17:24:31 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include <iostream>
# include "iteratorTraits.hpp"

namespace ft {
	template <class T>
	class vectorIterator : public ft::iterator<ft::random_access_iterator_tag, T>
	{

		public:
			typedef T				value_type;
			typedef std::ptrdiff_t	difference_type;
			typedef T*				pointer;
			typedef T&				reference;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category	iterator_category;

		protected:
			pointer	_value;

		public:
			vectorIterator(void) : _value() {}
			vectorIterator(pointer value) : _value(value) {}
			vectorIterator(vectorIterator const &src) : _value(src._value) {}
			~vectorIterator(void) {}

			vectorIterator &operator=(vectorIterator const &rhs)
			{
				_value = rhs._value;
				return *this;
			}
			vectorIterator	&operator=(pointer rhs)
			{
				_value = rhs;
				return *this;
			}
			reference operator*() const
			{
				return *_value;
			}
			pointer operator->() const
			{
				return _value;
			}

			bool operator==(const vectorIterator& rhs) const	{ return (rhs._value == _value); }
			bool operator!=(const vectorIterator& rhs) const	{ return (rhs._value != _value); }
			bool operator<(const vectorIterator& rhs) const		{ return (rhs._value > this->_value); }
			bool operator>(const vectorIterator& rhs) const		{ return (rhs._value < this->_value); }
			bool operator<=(const vectorIterator& rhs) const	{ return (rhs._value >= this->_value); }
			bool operator>=(const vectorIterator& rhs) const	{ return (rhs._value <= this->_value); }

			vectorIterator & operator[](unsigned int i) const
			{
				return this->_value[i];
			}
			vectorIterator &operator+=(int n)
			{
				_value += n;
				return *this;
			}
			vectorIterator &operator-=(int n)
			{
				_value -= n;
				return *this;
			}
			vectorIterator operator+(int n)
			{
				return vectorIterator(_value + n);
			}
			vectorIterator operator-(difference_type n) const
			{
				return vectorIterator(_value - n);
			}
			difference_type				operator-(const vectorIterator& rhs) const
			{ return (_value - rhs._value); }
			vectorIterator &operator++(void)
			{
				this->_value += 1;
				return *this;
			}
			vectorIterator &operator--(void)
			{
				this->_value -= 1;
				return *this;
			}
			vectorIterator operator++(int)
			{
				vectorIterator temp(*this);
				++(*this);
				return temp;
			}
			vectorIterator operator--(int)
			{
				vectorIterator temp(*this);
				--(*this);
				return temp;
			}
	};

}

# endif
