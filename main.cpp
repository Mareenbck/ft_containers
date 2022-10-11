/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:54:19 by mbascuna          #+#    #+#             */
/*   Updated: 2022/10/11 17:37:14 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include <iterator>

int main(void)
{
	ft::vector<int> first;
	ft::vector<int> second(4,100);
	ft::vector<int> fourth(second);

	 std::cout << "The contents of second are:";
	 for (ft::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		 std::cout << ' ' << *it;
	 std::cout << '\n';
		std::cout << "The contents of fourth are:";
	 for (ft::vector<int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
		 std::cout << ' ' << *it;
	std::cout << '\n';
}
