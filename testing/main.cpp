/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:54:19 by mbascuna          #+#    #+#             */
/*   Updated: 2022/11/15 10:32:19 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.hpp"

int main(int argc, char **argv)
{
	if(argc < 2)
		std::cout << "USAGE : Enter in lower case names of containers you to test";
	for(int i = 0; i < argc; i++)
	{
		std::string arg(argv[i]);
		if(!arg.compare("vector"))
			vector_tests();
		if(!arg.compare("stack"))
			pair_tests();
		if(!arg.compare("map"))
			map_tests();
	}

/*********************************MY TESTS************************************/
	// vector_tests();
	// pair_tests();
	// map_tests();
	return 0;
}
