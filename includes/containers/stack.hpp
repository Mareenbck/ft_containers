/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:39:55 by mbascuna          #+#    #+#             */
/*   Updated: 2022/11/14 13:21:47 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include <iostream>
# include "vector.hpp"

namespace ft {

	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef Container						container_type;
			typedef T value_type;
			// typedef typename Container::value_type	value_type;
			typedef typename Container::size_type	size_type;

		protected:
			container_type	c;

		public:
			explicit stack(const container_type& ctnr = container_type()) : c(ctnr) {};
			~stack(void) {};
			bool empty() const { return c.empty(); }
			size_type size() const { return c.size(); }
			value_type& top() { return c.back(); }
			const value_type& top() const { return c.back(); }
			void push(const value_type& x) { c.push_back(x); }
			void pop() { c.pop_back(); }

		friend bool operator==(const stack<T, Container>& x, const stack<T, Container>& y)
		{
			return (x.c == y.c);
		}

		friend bool operator< (const stack<T, Container>& x, const stack<T, Container>& y)
		{
			return (x.c < y.c);
		}

		friend bool operator!=(const stack<T, Container>& x, const stack<T, Container>& y)
		{
			return (x.c != y.c);
		}

		friend bool operator> (const stack<T, Container>& x, const stack<T, Container>& y)
		{
			return (x.c > y.c);
		}

		friend bool operator>=(const stack<T, Container>& x, const stack<T, Container>& y)
		{
			return (x.c >= y.c);
		}

		friend bool operator<=(const stack<T, Container>& x, const stack<T, Container>& y)
		{
			return (x.c <= y.c);
		}
	};
}

#endif
