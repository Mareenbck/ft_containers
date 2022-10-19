/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:02:29 by mbascuna          #+#    #+#             */
/*   Updated: 2022/10/19 14:43:05 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_HPP
# define INCLUDES_HPP

# include <string>
# include <iostream>
# include <ctime>
# include <cstdlib>
# include <sstream>
# include <algorithm>

// # ifndef FT
// 	#include <map>
// 	#include <stack>
// 	#include <vector>
// 	namespace ft = std;
// # else
// 	#include "../map.hpp"
// 	#include "../stack.hpp"
 # include "../includes/containers/vector.hpp"
 # include "../includes/utils/pair.hpp"
// # endif

// class Awesome {

// 	public:

// 		Awesome() : _n(42) { std::cout << "Default C " << std::endl; }
// 		Awesome(int n) : _n(n) { std::cout << "Int C " << std::endl; (void)n; }
// 		Awesome(Awesome const &rhs) : _n(42) {  std::cout << "Copy C " << std::endl; *this = rhs; }
// 		virtual ~Awesome() { std::cout << "D " << std::endl; }

// 		Awesome &operator=(Awesome const & rhs) { _n = rhs._n; return (*this); }
// 		bool operator==(Awesome const & rhs) const { return (_n == rhs._n); }
// 		bool operator!=(Awesome const & rhs) const { return (_n != rhs._n); }
// 		bool operator>(Awesome const & rhs) const { return (_n > rhs._n); }
// 		bool operator<(Awesome const & rhs) const { return (_n < rhs._n); }
// 		bool operator>=(Awesome const & rhs) const { return (_n >= rhs._n); }
// 		bool operator<=(Awesome const & rhs) const { return (_n <= rhs._n); }
// 		void operator+=(int rhs){ _n += rhs; }
// 		int get() const { return _n; }
// 		friend std::ostream & operator<<(std::ostream & o, Awesome const & rhs) { o << rhs.get(); return o; }

// 	private:

// 		int _n;
// };

void	vector_tests(void);
void 	pair_tests(void);
// void	stack_tests(void);
// void	map_tests(void);

#endif
