/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:24:11 by mbascuna          #+#    #+#             */
/*   Updated: 2022/10/24 20:01:43 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils/pair.hpp"
#include "../includes/containers/map.hpp"
#include <utility>
#include <string>
#include <iostream>

/********************************CONSTRUCTORS**********************************/

void ft_check_map_constructor(void)
{
	ft::map<char,int> mymap;

  // first insert function version (single parameter):
	mymap.insert( ft::pair<char,int>('a',100) );
	mymap.insert( ft::pair<char,int>('z',200) );

	ft::pair<ft::map<char,int>::iterator,bool> ret;
	ret = mymap.insert ( ft::pair<char,int>('z',500) );
	if (ret.second==false) {
		std::cout << "element 'z' already existed";
		std::cout << " with a value of " << ret.first->second << '\n';
  }

//   second insert function version (with hint position):
	// ft::map<char,int>::iterator it = mymap.begin();
	// mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
	// mymap.insert (it, ft::pair<char,int>('c',400));  // no max efficiency inserting

//   third insert function version (range insertion):
	// ft::map<char,int> anothermap;
	// anothermap.insert(mymap.begin(),mymap.find('c'));

//   showing contents:
//    ft::map<char,int>::iterator it = mymap.begin();
// 	std::cout << "mymap contains:\n";
// 	for (it=mymap.begin(); it!=mymap.end(); ++it)
// 		std::cout << it->first << " => " << it->second << '\n';

	// std::cout << "anothermap contains:\n";
	// for (it=anothermap.begin(); it!=anothermap.end(); ++it)
	// 	std::cout << it->first << " => " << it->second << '\n';
}

void map_tests(void)
{
	/**CONSTRUCTORS**/
		ft_check_map_constructor();

	/**CAPACITY**/

	/**MODIFIERS**/

	/**ELEMENT ACCESS**/

}
