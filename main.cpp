/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:54:19 by mbascuna          #+#    #+#             */
/*   Updated: 2022/10/12 18:15:34 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include <iterator>

int main(void)
{
	ft::vector<int> first;
	ft::vector<int> second(5,100);
	ft::vector<int> third(10,50);
	ft::vector<int> fourth(second);

	ft::vector<int>::iterator it1;
	it1 = second.begin();
	it1 = second.insert(it1, 200);
	std::cout << "second contains:";
	for (it1 = second.begin(); it1 < second.end(); it1++)
		std::cout << ' ' << *it1;
	std::cout << '\n';
	// ft::vector<int>::iterator it3;
	// it1 = second.begin();
	// second.reserve(10);
	// second.insert(it1, 2, 300);
	// std::cout << "second contains:";
	// for (it1 = second.begin(); it1 < second.end(); it1++)
	// 	std::cout << ' ' << *it1;
	// std::cout << '\n';

	std::cout << "The capcity of third:";
	std::cout << third.capacity() << std::endl;
	third.reserve(10);
	std::cout << "The new capcity of third:";
	std::cout << third.capacity() << std::endl;

	std::cout << "The contents of second are:";
	for (ft::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "The contents of third are:";
	for (ft::vector<int>::iterator it = third.begin(); it != third.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	third.erase(third.begin(), third.begin()+1);
	std::cout << "The contents of third are:";
	for (ft::vector<int>::iterator it = third.begin(); it != third.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "The contents of fourth are:";
	for (ft::vector<int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';


  return 0;

}
