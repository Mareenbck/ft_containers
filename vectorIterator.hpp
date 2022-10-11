/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:50:41 by mbascuna          #+#    #+#             */
/*   Updated: 2022/10/11 18:07:27 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include <iostream>
# include "iteratorTraits.hpp"

namespace ft {
	template <typename Iterator>
	class vectorIterator : public ft::iterator<ft::random_access_iterator_tag, Iterator>
	{

		public:
			// typedef Iterator iterator_type;
			typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
			typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
			typedef typename ft::iterator_traits<Iterator>::reference			reference;
			typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;

		protected:
			Iterator	_value;

		public:
			vectorIterator(void) : _value() {}
			// vectorIterator(reference value) : _value(&value) {}
			// vectorIterator(pointer value) : _value(value) {}
			explicit vectorIterator(const Iterator &i) : _value(i) {}
			vectorIterator(vectorIterator const &src) : _value(src._value) {}
			~vectorIterator(void) {}

			vectorIterator &operator=(vectorIterator const &rhs)
			{
				_value = rhs._value;
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

			vectorIterator & operator[](unsigned int i)
			{
				this->_value[i];
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
			vectorIterator operator-(int n)
			{
				return vectorIterator(_value - n);
			}
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
