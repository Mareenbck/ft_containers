/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:28:33 by mbascuna          #+#    #+#             */
/*   Updated: 2022/10/14 14:27:20 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSEITERATOR_HPP
# define REVERSEITERATOR_HPP

# include "iteratorTraits.hpp"
#include <iterator>

namespace ft {
	template <class Iterator>
	class reverse_iterator
	{
		protected:
			Iterator _value;

		public:
			typedef Iterator iterator_type;
			typedef typename ft::iterator_traits<Iterator>::difference_type 	difference_type;
			typedef typename ft::iterator_traits<Iterator>::value_type 			value_type;
			typedef typename ft::iterator_traits<Iterator>::pointer 			pointer;
			typedef typename ft::iterator_traits<Iterator>::reference 			reference;
			typedef typename ft::iterator_traits<Iterator>::iterator_category 	iterator_category;

		reverse_iterator(void) : _value(iterator_type()) {}
		explicit reverse_iterator(Iterator value) : _value(value) {}
		reverse_iterator(reverse_iterator const &src) : _value(src.base()) {}
		virtual ~reverse_iterator(void) {}

		template <typename U>
			reverse_iterator(const reverse_iterator<U>& u)
			{
				*this = u;
			}

		reverse_iterator	&operator=(reverse_iterator const &src)
		{
			if (*this != src)
				_value = src.base();
			return *this;
		}

		iterator_type base() const
		{
			return _value;
		} // explicit
		reference operator*() const
		{
			Iterator tmp = _value;
			return *--tmp;
		}
		pointer operator->() const
		{
			iterator_type tmp = _value;
			return (&(*(--tmp)));
		}
		reverse_iterator& operator++()
		{
			this->_value -= 1;
			return *this;
		}
		reverse_iterator operator++(int)
		{
			reverse_iterator tmp(*this);
			(*this)--;
			return tmp;
		}
		reverse_iterator& operator--()
		{
			this->_value += 1;
			return *this;

		}
		reverse_iterator operator--(int)
		{
			reverse_iterator tmp(*this);
			(*this)++;
			return tmp;
		}
		reverse_iterator operator+(difference_type n) const
		{
			return reverse_iterator(_value - n);
		}
		reverse_iterator& operator+=(difference_type n)
		{
			_value -= n;
			return *this;
		}
		reverse_iterator operator-(difference_type n) const
		{
			return reverse_iterator(_value + n);
		}
		reverse_iterator& operator-=(difference_type n)
		{
			_value += n;
			return *this;
		}
		reference operator[](difference_type n) const
		{
			return  _value[-n - 1];
			// return *(*this + n);
		}
};

template <class It1, class It2 >
	bool operator==( const reverse_iterator<It1>& left, const reverse_iterator<It2>& right){
		return left.base() == right.base();
	}

template <class It1, class It2 >
	bool operator<(const reverse_iterator<It1>& left, const reverse_iterator<It2>& right){
		return left.base() > right.base();
	}

template <class It1, class It2 >
	bool operator!=(const reverse_iterator<It1>& left, const reverse_iterator<It2>& right){
		return left.base() != right.base();
	}

template <class It1, class It2 >
	bool operator>(const reverse_iterator<It1>& left, const reverse_iterator<It2>& right){
		return left.base() < right.base();
	}
template <class It1, class It2 >
	bool operator>=(const reverse_iterator<It1>& left, const reverse_iterator<It2>& right){
		return left.base() <= right.base();
	}

template <class It1, class It2 >
	bool operator<=(const reverse_iterator<It1>& left, const reverse_iterator<It2>& right){
		return left.base() >= right.base();
	}


template< class Iter >
reverse_iterator<Iter>	operator+( typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& it )
{
	return(reverse_iterator<Iter>(it.base() - n));
}

template< typename lIter, typename rIter>
	typename reverse_iterator<lIter>::difference_type operator-(const reverse_iterator<lIter> &left, const reverse_iterator<rIter> &right) {
		return right.base() - left.base();
	}


}

#endif
