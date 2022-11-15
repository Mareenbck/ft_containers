/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:02:29 by mbascuna          #+#    #+#             */
/*   Updated: 2022/11/15 13:45:06 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_HPP
# define INCLUDES_HPP

#include <iostream>
#include <string>
#include <deque>

#ifndef NS
#define NS ft
#endif

#include <map>
#include <stack>
#include <vector>
#include <../includes/containers/map.hpp>
#include <../includes/containers/stack.hpp>
#include <../includes/containers/vector.hpp>

#include <stdlib.h>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
	int idx;
	char buff[BUFFER_SIZE];
};


#define COUNT (MAX_RAM / (int)sizeof(Buffer))

template<typename T>
class MutantStack : public NS::stack<T>
{
public:
	MutantStack() {}
	MutantStack(const MutantStack<T>& src) { *this = src; }
	MutantStack<T>& operator=(const MutantStack<T>& rhs)
	{
		this->c = rhs.c;
		return *this;
	}
	~MutantStack() {}

	typedef typename NS::stack<T>::container_type::iterator iterator;

	iterator begin() { return this->c.begin(); }
	iterator end() { return this->c.end(); }
};

#define BOLD "\033[1m"
#define RESET "\033[0m"
#define UL "\033[4m"
#define ULL "\033[7m"
#define TAB "\t"
// #define SPACE "  "
#define YELLOW "\033[93m"
#define RED "\033[91m"
#define REDARK "\033[0;31;2m"
#define BLUE "\033[96m"
#define BLUEDARK "\033[0;34;2m"
#define GREEN "\033[92m"
#define GREENDARK "\033[0;32;2m"
#define YELLDARK "\033[0;33;2m"
#define PINK "\033[95m"
#define STAR "\033[92m * \033[0m"

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
void 	map_tests(void);
// void	stack_tests(void);


#endif
