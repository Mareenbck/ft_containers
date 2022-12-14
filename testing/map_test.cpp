/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 15:24:11 by mbascuna          #+#    #+#             */
/*   Updated: 2022/11/07 13:14:26 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils/pair.hpp"
#include "../includes/utils/rb_tree.hpp"
#include "../includes/containers/map.hpp"
#include <utility>
#include <string>
#include <iostream>
#include <list>

/********************************CONSTRUCTORS**********************************/

void ft_check_map_constructor(void)
{
	ft::map<char,int> first;

	first['a']=10;
	first['b']=30;
	first['c']=50;
	first['d']=70;

//   first insert function version (single parameter):
	ft::map<char,int> mymap;
	mymap.insert( ft::pair<char,int>('a',100) );
	mymap.insert( ft::pair<char,int>('z',200) );

	ft::pair<ft::map<char,int>::iterator,bool> ret;
	ret = mymap.insert ( ft::pair<char,int>('z',500) );
	if (ret.second==false) {
		std::cout << "element 'z' already existed";
		std::cout << " with a value of " << ret.first->second << '\n';
  }

//   second insert function version (with hint position):
	ft::map<char,int>::iterator it = mymap.begin();
	mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
	mymap.insert (it, ft::pair<char,int>('c',400));  // no max efficiency inserting

//   third insert function version (range insertion):
	// ft::map<char,int> anothermap;
	// anothermap.insert(mymap.begin(),mymap.find('c'));

//   showing contents:
//    ft::map<char,int>::iterator it = mymap.begin();
	std::cout << "mymap contains:\n";
	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	// std::cout << "anothermap contains:\n";
	// for (it=anothermap.begin(); it!=anothermap.end(); ++it)
	// 	std::cout << it->first << " => " << it->second << '\n';
}

void ft_check_clear()
{
	ft::map<char,int> mymap;

	mymap['x']=100;
	mymap['y']=200;
	mymap['z']=300;

	std::cout << "mymap contains:\n";
	for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	mymap.clear();
	mymap['a']=1101;
	mymap['b']=2202;

	std::cout << "mymap contains:\n";
	for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}

/********************************MODIFIERS**********************************/

void ft_check_erase_map(void)
{
	ft::map<char, int> mymap;
	ft::map<char, int>::iterator it;

	// insert some values:
	mymap['a'] = 10;
	mymap['b'] = 20;
	mymap['c'] = 30;
	mymap['d'] = 40;
	mymap['e'] = 50;
	mymap['f'] = 60;

	it = mymap.find('b');
	std::cout << "found b\n";
	mymap.erase(it); // erasing by iterator
	std::cout << "erase iterator to b\n";
	mymap.erase('c'); // erasing by key
	std::cout << "erase by key 'c'\n";
	it = mymap.find('e');
	std::cout << "erase by range 'e' to end\n";
	mymap.erase(it, mymap.end()); // erasing by range

	std::cout << " display :\n";
	// show content:
	for (it = mymap.begin(); it != mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}
/********************************ELEMENT ACCESS**********************************/

void ft_check_at(void)
{
	ft::map<std::string,int> mymap;

	mymap["alpha"]=0;
	mymap["beta"]=0;
	mymap["gamma"]=0;

	mymap.at("alpha") = 10;
	mymap.at("beta") = 20;
	mymap.at("gamma") = 30;

	ft::map<std::string,int>::iterator it = mymap.begin();

	for (it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << ": " << it->second << '\n';
}

void ft_check_empty(void)
{
	ft::map<char,int> mymap;

	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;

	std::cout << "mymap contains:\n";
	for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "mymap contains:\n";
	while (!mymap.empty())
	{
		std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
		mymap.erase(mymap.begin());
	}
}

void ft_check_operator(void)
{
	ft::map<char,int> first;
	ft::map<char,int> second;

	first['x']=8;
	first['y']=16;
	first['z']=32;

	second=first;                // second now contains 3 ints
	first=ft::map<char,int>();  // and first is now empty

	std::cout << "Size of first: " << first.size() << '\n';
	std::cout << "Size of second: " << second.size() << '\n';
}

/********************************OPERATIONS**********************************/

void ft_check_lowerbound(void)
{
	ft::map<char,int> mymap;
	ft::map<char,int>::iterator itlow,itup;

	mymap['a']=20;
	mymap['b']=40;
	mymap['c']=60;
	mymap['d']=80;
	mymap['e']=100;

	itlow=mymap.lower_bound ('b');  // itlow points to b
	itup=mymap.upper_bound ('d');   // itup points to e (not d!)

	// mymap.erase(itlow,itup);        // erases [itlow,itup)
    std::cout << itlow->first << " => " << itlow->second << '\n';
    std::cout << itup->first << " => " << itup->second << '\n';

  // print content:
//   for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    // std::cout << it->first << " => " << it->second << '\n';

}

void ft_check_find(void)
{
	ft::map<char,int> mymap;
	ft::map<char,int>::iterator it;

	mymap['a']=50;
	mymap['b']=100;
	mymap['c']=150;
	mymap['d']=200;

	it = mymap.find('b');
	// if (it != mymap.end())
	// 	mymap.erase (it);

  // print content:
	std::cout << "elements in mymap:" << '\n';
	std::cout << "a => " << mymap.find('a')->second << '\n';
	std::cout << "c => " << mymap.find('c')->second << '\n';
	std::cout << "d => " << mymap.find('d')->second << '\n';
}

void ft_check_count(void)
{
	ft::map<char,int> mymap;
	char c;

	mymap['a']=101;
	mymap['c']=202;
	mymap['f']=303;

	for (c='a'; c<'h'; c++)
	{
		std::cout << c;
		if (mymap.count(c)>0)
			std::cout << " is an element of mymap.\n";
		else
			std::cout << " is not an element of mymap.\n";
	}
}

void map_tests(void)
{
	/**CONSTRUCTORS**/
		// ft_check_map_constructor();
		// ft_check_clear();
		// ft_constructor_tester();

	/**CAPACITY**/

	/**MODIFIERS**/
		ft_check_erase_map();

	/**ELEMENT ACCESS**/
		// ft_check_at();
		// ft_check_empty();
		// ft_check_operator();

	/**OPERATIONS*/
		// ft_check_lowerbound();
		// ft_check_find();
		// ft_check_count();

}
