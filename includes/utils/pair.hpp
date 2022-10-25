/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:29:16 by mbascuna          #+#    #+#             */
/*   Updated: 2022/10/25 14:50:37 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

# include <iostream>
# include <utility>
# include <string>

namespace ft {

	template <class T1, class T2>
	class pair
	{
		public:
			typedef T1 first_type;
			typedef T2 second_type;

			T1 first;
			T2 second;

			pair() : first(), second() {}
			pair(const T1& x, const T2& y) : first(x), second(y) {}

			template<class U, class V>
			pair(const pair<U, V> &p) : first(p.first), second(p.second) {}

			pair& operator=( const pair& src )
			{
				// if (*this == src)
				// 	return *this;
				this->first = src.first;
				this->second = src.second;
				return (*this);
			};

			~pair(){};
			// template<class _U1, class _U2>
			// pair& operator=(const pair<_U1, _U2>& __p)
			// {
			// 	first = __p.first;
			// 	second = __p.second;
			// 	return *this;
			// }
	};

	template <class T1, class T2>
		bool operator==(const ft::pair<T1, T2>& x, const ft::pair<T1, T2>& y)
		{
			return (x.first == y.first && x.second == y.second);
		}
	template <class T1, class T2>
		bool operator!= (const ft::pair<T1,T2>& x, const ft::pair<T1,T2>& y)
		{
			return (!(x == y));
		}
	template <class T1, class T2>
		bool operator<(const ft::pair<T1, T2>& x, const ft::pair<T1, T2>& y)
		{
			return (x.first < y.first || (!(y.first < x.first) && x.second < y.second));
		}
	template <class T1, class T2>
		bool operator<=(const ft::pair<T1,T2>& x, const ft::pair<T1,T2>& y)
		{
			return !(y < x);
		}
	template <class T1, class T2>
		bool operator>(const ft::pair<T1,T2>& x, const ft::pair<T1,T2>& y)
		{
			return (y < x);
		}
	template <class T1, class T2>
		bool operator>=(const ft::pair<T1,T2>& x, const ft::pair<T1,T2>& y)
		{
			return !(x < y);
		}

	template<class T1, class T2>
	ft::pair<T1,T2>	make_pair(T1 t, T2 u)
	{
		return ft::pair<T1, T2>(t, u);
	}
}

#endif
