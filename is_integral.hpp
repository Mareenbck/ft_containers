/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 13:54:37 by mbascuna          #+#    #+#             */
/*   Updated: 2022/10/14 14:14:32 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

namespace ft {

	template <class T, T v>
	struct integral_constant {
		const static T value = v;
		typedef T value_type;
		typedef integral_constant<T, v>	type;
		operator T() {return v;}
	};

	typedef integral_constant<bool,true> true_type;
	typedef integral_constant<bool,false> false_type;

	template <typename>
		struct is_integral : public false_type {};
	template <>
		struct is_integral<bool> : public true_type {};
	template <>
		struct is_integral<char> : public true_type {};
	template <>
		struct is_integral<signed char> : public true_type {};
	template <>
		struct is_integral<short> : public true_type {};
	template <>
		struct is_integral<int> : public true_type {};
	template <>
		struct is_integral<long> : public true_type {};
	template <>
		struct is_integral<unsigned char> : public true_type {};
	template <>
		struct is_integral<unsigned short> : public true_type {};
	template <>
		struct is_integral<unsigned int> : public true_type {};
	template <>
		struct is_integral<unsigned long> : public true_type {};
}

#endif
