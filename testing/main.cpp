/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:54:19 by mbascuna          #+#    #+#             */
/*   Updated: 2022/11/14 19:05:00 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.hpp"

#if NS //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>
	# define NS std
#else
	#include <../includes/containers/map.hpp>
	#include <../includes/containers/stack.hpp>
	#include <../includes/containers/vector.hpp>
	# define NS ft
#endif

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
