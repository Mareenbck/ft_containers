/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteratorTraits.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:47:51 by mbascuna          #+#    #+#             */
/*   Updated: 2022/10/13 16:55:17 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

# include <iostream>
# include <memory>
# include <iostream>
# include <cstddef>

namespace ft {

	struct input_iterator_tag { };
	struct output_iterator_tag { };
	struct forward_iterator_tag : public input_iterator_tag { };
	struct bidirectional_iterator_tag : public forward_iterator_tag { };
	struct random_access_iterator_tag : public bidirectional_iterator_tag { };

	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	class iterator
	{
		public :
			typedef T			value_type;
			typedef Distance	difference_type;
			typedef Pointer		pointer;
			typedef Reference	reference;
			typedef Category	iterator_category;
	};

	template <class Iterator>
	class iterator_traits
	{
		public :
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::pointer				pointer;
			typedef typename Iterator::reference			reference;
			typedef typename Iterator::iterator_category	iterator_category;
	};

	template <class T>
	class iterator_traits<T*>
	{
		public :
			typedef  T							value_type;
			typedef  std::ptrdiff_t				difference_type;
			typedef  T*							pointer;
			typedef  T&							reference;
			typedef  random_access_iterator_tag	iterator_category;
	};

	template <class T>
	class iterator_traits<const T*>
	{
		public :
			typedef  T							value_type;
			typedef  std::ptrdiff_t				difference_type;
			typedef  const T*					pointer;
			typedef  const T&					reference;
			typedef  random_access_iterator_tag	iterator_category;
	};

	// template<typename L, typename R>
	// bool operator==(const vectorIterator<L> &left, const vectorIterator<R> &right)
	// {
	// 	return left.operator->() == right.operator->();
	// }
}

#endif
