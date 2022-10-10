/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:54:19 by mbascuna          #+#    #+#             */
/*   Updated: 2022/10/10 18:09:11 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Vector.hpp"
#include <vector>

int main(void)
{
	ft::vector<int> first;
	ft::vector<int> second(4,100);
	ft::vector<int> fourth(second);

	 std::cout << "The contents of second are:";
	 for (std::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		 std::cout << ' ' << *it;
	 std::cout << '\n';
		std::cout << "The contents of fourth are:";
	 for (std::vector<int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
		 std::cout << ' ' << *it;
	std::cout << '\n';
}
