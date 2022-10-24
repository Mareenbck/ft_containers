/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:29:16 by mbascuna          #+#    #+#             */
/*   Updated: 2022/10/24 19:10:44 by mbascuna         ###   ########.fr       */
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

			first_type first;
			second_type second;

			pair() : first(), second() {}
			pair(const first_type& x, const second_type& y) : first(x), second(y) {}

			template<class U, class V>
			pair(const pair<U, V> &p) : first(p.first), second(p.second) {}
			~pair(){};

			pair& operator=( const pair& src )
			{
				if (*this == src)
					return *this;
				first = src.first;
				second = src.second;
				return (*this);
			};
	};

	template <class T1, class T2>
		bool operator==(const pair<T1, T2>& x, const pair<T1, T2>& y)
		{
			return (x.first == y.first && x.second == y.second);
		}
	template <class T1, class T2>
		bool operator!= (const pair<T1,T2>& x, const pair<T1,T2>& y)
		{
			return !(x == y);
		}
	template <class T1, class T2>
		bool operator<(const pair<T1, T2>& x, const pair<T1, T2>& y)
		{
			return (x.first < y.first || (!(y.first < x.first) && x.second < y.second));
		}
	template <class T1, class T2>
		bool operator<=(const pair<T1,T2>& x, const pair<T1,T2>& y)
		{
			return !(y < x);
		}
	template <class T1, class T2>
		bool operator>(const pair<T1,T2>& x, const pair<T1,T2>& y)
		{
			return (y < x);
		}
	template <class T1, class T2>
		bool operator>=(const pair<T1,T2>& x, const pair<T1,T2>& y)
		{
			return !(x < y);
		}

	template<class T1, class T2>
	pair<T1,T2>	make_pair(T1 t, T2 u)
	{
		return pair<T1, T2>(t, u);
	}
}

#endif
