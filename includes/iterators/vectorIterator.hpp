/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:50:41 by mbascuna          #+#    #+#             */
/*   Updated: 2022/11/14 15:59:58 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include <iostream>
# include "iteratorTraits.hpp"

namespace ft {
	template <class Iterator>
	class vectorIterator : public ft::iterator<ft::random_access_iterator_tag, Iterator>
	{
		public:
			typedef Iterator		iterator_type;
			typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
			typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
			typedef typename ft::iterator_traits<Iterator>::reference			reference;
			typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;

		protected:
			Iterator	_value;

		public:
			vectorIterator(void) : _value() {}
			explicit vectorIterator(const Iterator& value) : _value(value) {}
			vectorIterator(vectorIterator &src) : _value(src.base()) {}
			~vectorIterator(void) {}

			template<typename Iter>
				vectorIterator(const vectorIterator<Iter> &i) : _value(i.base()) {}

			reference operator*() const
			{
				return *_value;
			}
			pointer operator->() const
			{
				return _value;
			}
			vectorIterator &operator++(void)
			{
				++_value;
				return *this;
			}
			vectorIterator operator++(int)
			{
				vectorIterator tmp(*this);
				++(*this);
				return tmp;
			}

			vectorIterator &operator--(void)
			{
				--_value;
				return *this;
			}
			vectorIterator operator--(int)
			{
				vectorIterator tmp(*this);
				--(*this);
				return tmp;
			}

			reference operator[](const difference_type& n) const
			{
				return this->_value[n];
			}
			vectorIterator &operator+=(const difference_type& n)
			{
				_value += n;
				return *this;
			}
			vectorIterator operator+(const difference_type& n) const
			{
				return vectorIterator(_value + n);
			}
			vectorIterator &operator-=(const difference_type& n)
			{
				_value -= n;
				return *this;
			}
			vectorIterator operator-(const difference_type& n) const
			{
				return vectorIterator(_value - n);
			}

			iterator_type base() const
			{
				return _value;
			}

			vectorIterator	&operator=(const vectorIterator &rhs)
			{
				_value = rhs._value;
				return *this;
			}

			// bool operator==(const vectorIterator& rhs) const	{ return (rhs._value == _value); }
			// bool operator!=(const vectorIterator& rhs) const	{ return (rhs._value != _value); }
			// bool operator<(const vectorIterator& rhs) const		{ return (rhs._value > this->_value); }
			// bool operator>(const vectorIterator& rhs) const		{ return (rhs._value < this->_value); }
			// bool operator<=(const vectorIterator& rhs) const	{ return (rhs._value >= this->_value); }
			// bool operator>=(const vectorIterator& rhs) const	{ return (rhs._value <= this->_value); }
	};

	template <typename L, typename R>
		bool operator==(const vectorIterator<L> &left, const vectorIterator<R> &right) {
			return left.base() == right.base();
		}

	template<typename L, typename R>
		bool operator!=(const vectorIterator<L> &left, const vectorIterator<R> &right) {
			return left.base() != right.base();
	}

	template<typename L, typename R>
		bool operator<(const vectorIterator<L> &left, const vectorIterator<R> &right) {
			return (left.base() < right.base());
		}

	template<typename L, typename R>
		bool operator>(const vectorIterator<L> &left, const vectorIterator<R> &right) {
			return left.base() > right.base();
		}

	template<typename L, typename R>
		bool operator<=(const vectorIterator<L> &left, const vectorIterator<R> &right) {
			return left.base() <= right.base();
		}

	template<typename L, typename R>
		bool operator>=(const vectorIterator<L> &left, const vectorIterator<R> &right) {
			return left.base() >= right.base();
		}

	template<typename Iter>
		vectorIterator<Iter> operator+(typename vectorIterator<Iter>::difference_type n, const vectorIterator<Iter> &right) {
			return vectorIterator<Iter>(right.base() + n);
		}

	template< typename L, typename R>
		typename vectorIterator<L>::difference_type operator-(const vectorIterator<L> &left, const vectorIterator<R> &right) {
			return (left.base() - right.base());
		}


}

# endif
