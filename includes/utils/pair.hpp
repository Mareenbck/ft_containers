/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:29:16 by mbascuna          #+#    #+#             */
/*   Updated: 2022/11/14 16:41:46 by mbascuna         ###   ########.fr       */
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

			pair(void) : first(), second() {}
			template<class U, class V>
			pair(const pair<U, V> &p) : first(p.first), second(p.second) {}
			pair(const T1& x, const T2& y) : first(x), second(y) {}
			~pair(void){};

			pair &operator=(const pair &other)
			{
				if (this != &other)
				{
					this->first = other.first;
					this->second = other.second;
				}
				return (*this);
			}

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
	pair<T1,T2>	make_pair(T1 t, T2 u)
	{
		return pair<T1, T2>(t, u);
	}
}

#endif
