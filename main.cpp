/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:54:19 by mbascuna          #+#    #+#             */
/*   Updated: 2022/10/13 11:39:52 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include <iterator>

void ft_check_erase(void)
{
	ft::vector<int> second(5,100);
	ft::vector<int>::iterator it1;

	second[0] = 1;
	second[1] = 2;
	second[2] = 3;
	second[3] = 4;
	second[4] = 5;
	std::cout << "Vector : " << std::endl;
	for (it1 = second.begin(); it1 < second.end(); it1++)
		std::cout << ' ' << *it1;
	std::cout << '\n';
	std::cout << " ERASE : " << *second.begin()+2 << std::endl;
	second.erase(second.begin()+2);
	for (it1 = second.begin(); it1 < second.end(); it1++)
		std::cout << ' ' << *it1;
	std::cout << '\n';
	second.erase(second.begin()+5);
	for (it1 = second.begin(); it1 < second.end(); it1++)
		std::cout << ' ' << *it1;
	std::cout << '\n';

	std::cout << "______________________________________" << std::endl;

	ft::vector<int> first(10,20);
	ft::vector<int>::iterator it;

	for (int i = 0; i < 10; i++)
		first[i] = i + 1;
	std::cout << "Vector : " << std::endl;
	for (it = first.begin(); it < first.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';
	first.erase(first.begin()+2, first.begin() + 4);


	for (it = first.begin(); it < first.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';
	first.erase(first.begin()+10, first.begin()+20);
	for (it = first.begin(); it < first.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "REALITY " << std::endl;

	std::vector<int> real(10,20);
	std::vector<int>::iterator itr;

	std::cout << "Vector : " << std::endl;
	for (int i = 0; i < 10; i++)
		real[i] = i + 1;
	for (itr = real.begin(); itr < real.end(); itr++)
		std::cout << ' ' << *itr;
	std::cout << '\n';
	real.erase(real.begin()+2, real.begin() + 4);
	for (itr = real.begin(); itr < real.end(); itr++)
		std::cout << ' ' << *itr;
	std::cout << '\n';


}

int main(void)
{
	ft_check_erase();
	// ft::vector<int> first;
	// ft::vector<int> second(5,100);
	// ft::vector<int> third(10,50);
	// ft::vector<int> fourth(second);

	// ft::vector<int>::iterator it1;
	// it1 = second.begin();
	// it1 = second.insert(it1, 200);
	// std::cout << "second contains:";
	// for (it1 = second.begin(); it1 < second.end(); it1++)
	// 	std::cout << ' ' << *it1;
	// std::cout << '\n';
	// ft::vector<int>::iterator it3;
	// it1 = second.begin();
	// // second.reserve(10);
	// second.insert(it1 + 1, third.begin() + 1, third.begin() + 4);
	// std::cout << "second contains:";
	// for (it1 = second.begin(); it1 < second.end(); it1++)
	// 	std::cout << ' ' << *it1;
	// std::cout << '\n';

	// std::cout << "The capcity of third:";
	// std::cout << third.capacity() << std::endl;
	// third.reserve(10);
	// std::cout << "The new capcity of third:";
	// std::cout << third.capacity() << std::endl;

	// // std::cout << "The contents of second are:";
	// // for (ft::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
	// // 	std::cout << ' ' << *it;
	// // std::cout << '\n';
	// std::cout << "The contents of third are:";
	// for (ft::vector<int>::iterator it = third.begin(); it != third.end(); ++it)
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';
	// third.erase(third.begin(), third.begin()+1);
	// std::cout << "The contents of third are:";
	// for (ft::vector<int>::iterator it = third.begin(); it != third.end(); ++it)
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';
	// std::cout << "The contents of fourth are:";
	// for (ft::vector<int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';


  return 0;

}
