/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 14:36:54 by mbascuna          #+#    #+#             */
/*   Updated: 2022/11/15 18:24:26 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.hpp"
#include <list>

void print_vector(NS::vector<int> &vct)
{
	int i = 0;
	std::cout << "     ";
	for (NS::vector<int>::iterator it = vct.begin(); it != vct.end(); ++it)
		std::cout << "vct[" << i++ << "] : " << *it << " | ";
	std::cout << '\n';
	std::cout << "     " << BOLD << "size :" << RESET << vct.size() << "  |  " << BOLD << "capacity :" << RESET << vct.capacity() << std::endl << std::endl;
}

void print_vector(NS::vector<std::string> &vct)
{
	int i = 0;
	std::cout << "     ";
	for (NS::vector<std::string>::iterator it = vct.begin(); it != vct.end(); ++it)
		std::cout << "vct[" << i++ << "] : " << *it << " | ";
	std::cout << '\n';
	std::cout << "     " << BOLD << "size :" << RESET << vct.size() << "  |  " << BOLD << "capacity :" << RESET << vct.capacity() << std::endl << std::endl;
}

/********************************CONSTRUCTORS**********************************/

void check_constructor(void)
{
	std::cout << PINK << ULL << "▶️​​  CONSTRUCTORS TESTS " << RESET << std::endl << std::endl;
	std::cout << " " << YELLDARK << BOLD  << " | " << UL << "default:" << RESET << " vector();" << std::endl;
	{
		NS::vector<int> vec;
		print_vector(vec);
	}
	std::cout << " " << YELLDARK << BOLD  << " | " << UL << "with size:" << RESET << " vector(5);" << std::endl;
	{
		NS::vector<int> vec(5);
		print_vector(vec);
	}
	std::cout << " " << YELLDARK << BOLD  << " | " << UL << "with size + value:" << RESET << " vector(5, 42);" << std::endl;
	{
		NS::vector<int> vec(5, 42);
		print_vector(vec);
		std::cout << " " << YELLDARK << BOLD  << " | " << UL << "with iterator:" << RESET << " vector(vec.begin(), vec.end());" << std::endl;
		NS::vector<int> vec1(vec.begin(), vec.end());
		print_vector(vec1);
		std::cout << " " << YELLDARK << BOLD  << " | " << UL << "with range:" << RESET << " vct_range(it, --(--ite));" << std::endl;
		NS::vector<int>::iterator it = vec.begin(), ite = vec.end();
		NS::vector<int> vct_range(it, --(--ite));
		print_vector(vct_range);
		std::cout << " " << YELLDARK << BOLD  << " | " << UL << "copy:" << RESET << " vct_copy(vct);" << std::endl;
		NS::vector<int> vct_copy(vec);
		print_vector(vct_copy);
		std::cout << " " << YELLDARK << BOLD  << " | " << UL << "operator = " << RESET << " vct_range = vec;" << std::endl;
		vct_range = vec;
		print_vector(vct_range);
	}
}

void ft_check_assign(void)
{
	std::cout << PINK << ULL << "▶️​  ASSIGN TESTS " << RESET << std::endl;

	std::cout << " " << YELLDARK << BOLD << " | " << UL << "assign:" << RESET << " vct(4, /"" Ola !/"");" << std::endl;
	NS::vector<std::string> vec3;
	vec3.assign(4, "Ola !");
	print_vector(vec3);

	std::cout << " " << YELLDARK << BOLD << " | " << UL << "assign w/ iterator:" << RESET << " vec1.assign(lst.begin(), lst.end());" << std::endl;
	NS::vector<int> vec1;
	std::list<int> lst;
	for (int i = 0; i < 10; i++)
		lst.insert(lst.end(), i * 3);
	vec1.assign(lst.begin(), lst.end());
	print_vector(vec1);
}

/*********************************ITERATORS************************************/

/**********************************CAPACITY************************************/

void check_capacity(void)
{
	std::cout << PINK << ULL << "▶️​​  CAPACITY TESTS " << RESET << std::endl;
	std::cout << " " << YELLDARK << BOLD << " | " << UL << "size empty:" << RESET << " vector()" << std::endl;
	NS::vector<int> vct;
	std::cout << "   size : " << vct.size() << " | capacity : " << vct.capacity() << " | max_size : " << vct.max_size() << std::endl << std::endl;
	std::cout << " " << YELLDARK << BOLD << " | " << UL << "size 10000:" << RESET << " vct1(10000)" << std::endl;
	NS::vector<int> vct1(10000);
	std::cout << "   size : " << vct1.size() << " | capacity : " << vct1.capacity() << " | max_size : " << vct1.max_size() << std::endl << std::endl;
	std::cout << " " << YELLDARK << BOLD << " | " << UL << "size 1:" << RESET << " vct2(1)" << std::endl;
	NS::vector<int> vct2(1);
	std::cout << "   size : " << vct2.size() << " | capacity : " << vct2.capacity() << " | max_size : " << vct2.max_size() << std::endl << std::endl;

	std::cout << PINK << ULL << "​▶️​​  RESIZE TESTS " << RESET << std::endl;
	std::cout << " " << YELLDARK << BOLD << " | " << UL << "resize():" << RESET << " vct1.resize(5, 42)" << std::endl;
	vct1.resize(5, 42);
	print_vector(vct1);
	std::cout << " " << YELLDARK << BOLD << " | " << UL << "resize():" << RESET << " vct.resize(42)" << std::endl;
	vct.resize(42);
	print_vector(vct);
	std::cout << " " << YELLDARK << BOLD << " | " << UL << "resize():" << RESET << " vct2.resize(0)" << std::endl;
	vct2.resize(0);
	print_vector(vct2);

	std::cout << PINK << ULL << "▶️​​  EMPTY TESTS " << RESET << std::endl;
	std::cout << " " << YELLDARK << BOLD << " | " << UL << "vct:" << RESET << " " << vct.size() << std::endl;
	std::cout << "   bool :" << vct.empty() << std::endl;
	std::cout << " " << YELLDARK << BOLD << " | " << UL << "vct1:" << RESET << " " << vct1.size() << std::endl;
	std::cout << "   bool :" << vct1.empty() << std::endl;
	std::cout << " " << YELLDARK << BOLD << " | " << UL << "vct2:" << RESET << " " << vct2.size() << std::endl;
	std::cout << "   bool :" << vct2.empty() << std::endl << std::endl;

	std::cout << PINK << ULL << "▶️​​  RESERVE TESTS " << RESET << std::endl;
	std::cout << " " << YELLDARK << BOLD << " | " << UL << "reserve:" << RESET << " vct.reserve(10)" << std::endl;
	vct.reserve(10);
	print_vector(vct);
	std::cout << " " << YELLDARK << BOLD << " | " << UL << "reserve:" << RESET << " vct1.reserve(100)" << std::endl;
	vct1.reserve(100);
	print_vector(vct1);
	std::cout << " " << YELLDARK << BOLD << " | " << UL << "reserve:" << RESET << " vct2.reserve(0)" << std::endl;
	vct2.reserve(100);
	print_vector(vct2);
}

void reserve_ref(void)
{
	NS::vector<int>::size_type sz;

	NS::vector<int> foo;
	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		foo.push_back(i);
		if (sz != foo.capacity())
		{
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}

	NS::vector<int> bar;
	sz = bar.capacity();
	bar.reserve(100); // this is the only difference with foo above
	std::cout << "making bar grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		bar.push_back(i);
		if (sz != bar.capacity())
		{
			sz = bar.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}
}

void check_resize_ref(void)
{
	std::cout << std::endl << "RESIZE TESTS" << std::endl;
	NS::vector<int> test(12, 12);

	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
	test.resize(72);
	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
	test.resize(100);
	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
	test.resize(4170);
	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
	test.resize(171, 12);
	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
	test.resize(62);
	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;

	std::cout << "------------------------------" << std::endl;

	NS::vector<int> myvector;
	for (int i=1;i<10;i++)
		myvector.push_back(i);

	myvector.resize(5);
	myvector.resize(8,100);
	myvector.resize(12);

	std::cout << "myvector contains:";
	for (size_t i=0;i<myvector.size();i++)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
}

/*********************************MODIFIERS************************************/

void ft_check_pushback(void)
{
	NS::vector<int> vct;
	std::cout << PINK << ULL << "▶️​  PUSH_BACK TESTS " << RESET << std::endl;
	std::cout << YELLDARK << BOLD << "  | " << UL << "push_back:" << RESET << " vct.push_back(42)" << std::endl;
	vct.push_back(42);
	print_vector(vct);
	std::cout << YELLDARK << BOLD << "  | " << UL << "push_back in loop:" << RESET << " vct.push_back(54)" << std::endl;
		for (int i = 0; i < 3;  i++)
			vct.push_back(54);
	print_vector(vct);

	std::cout << PINK << ULL << "▶️​  POP_BACK TESTS " << RESET << std::endl;
	std::cout << YELLDARK << BOLD << "  | " << UL << "pop_bakc" << RESET << " vct.pop_back()" << std::endl;
	vct.pop_back();
	print_vector(vct);
	std::cout << YELLDARK << BOLD << "  | " << UL << "pop_bakc in loop:" << RESET << " vct.pop_back()" << std::endl;
	for (int i = 0; i < 3;  i++)
		vct.pop_back();
	print_vector(vct);
}

void ft_check_pushback_bis(void)
{
	NS::vector<std::string> vct(8);
	NS::vector<std::string> vct2;
	NS::vector<std::string>::iterator it = vct.begin();

	for (unsigned long int i = 0; i < vct.size(); ++i)
		it[i] = std::string((vct.size() - i), i + 65);
	std::cout << "size : " << vct.size() << " | capacity : " << vct.capacity() << std::endl;


	std::cout << "push_back():\n" << std::endl;

	vct.push_back("One long string");
	vct2.push_back("Another long string");

	std::cout << "size : " << vct.size() << " | capacity : " << vct.capacity() << std::endl;
	std::cout << "size : " << vct2.size() << " | capacity : " << vct2.capacity() << std::endl;

	vct.pop_back();
	vct2.pop_back();

	std::cout << "size : " << vct.size() << " | capacity : " << vct.capacity() << std::endl;
	std::cout << "size : " << vct2.size() << " | capacity : " << vct2.capacity() << std::endl;
}

void pop_back_tests(void)
{
	std::cout << std::endl << "PUSH BACK & POP BACK TESTS" << std::endl;
	NS::vector<int> test;

	std::cout << "Empty ? " << test.empty() << " / Capacity : " << test.capacity() << " / Size : " << test.size() << std::endl;
	for (size_t i = 0; i < 51; i++)
	{
		test.push_back(i);
		std::cout << test.size() << ": " << test.capacity() << " - ";
		if (!(i % 10) && i != 0)
			std::cout << std::endl;
	}

	for (NS::vector<int>::iterator it = test.begin(); it != test.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << " size " << test.size() << " | capacity : " << test.capacity() << std::endl;
	test.pop_back();
	test.pop_back();
	test.pop_back();
	test.pop_back();
	for (NS::vector<int>::iterator it = test.begin(); it != test.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << " size " << test.size() << " | capacity : " << test.capacity() << std::endl;
}

void ft_check_insert_ref()
{
	NS::vector<int> myvector (3,100);
	NS::vector<int>::iterator it;
	NS::vector<int>::iterator ite = myvector.end();

	it = myvector.begin();
	for (; it != ite; it++)
		std::cout << " " << *it;
	std::cout << std::endl;

	myvector.insert( myvector.begin() , 200 );
	it = myvector.begin();
	for (; it != myvector.end(); it++)
		std::cout << " " << *it;
	std::cout << std::endl;

	myvector.insert(myvector.begin(),2,300);
	it = myvector.begin();
	for (; it != myvector.end(); it++)
		std::cout << " " << *it;
	std::cout << std::endl;

  // "it" no longer valid, get a new one:
	it = myvector.begin();

	NS::vector<int> anothervector (2,400);
	myvector.insert (it+2,anothervector.begin(),anothervector.end());
	it = myvector.begin();
	for (; it != myvector.end(); it++)
		std::cout << " " << *it;
	std::cout << std::endl;

	int myarray [] = { 501,502,503 };
	myvector.insert (myvector.begin(), myarray, myarray+3);

	std::cout << "myvector contains:";
	for (it=myvector.begin(); it<myvector.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

void ft_check_insert()
{
	std::cout << PINK << ULL << "▶️​  INSERT TESTS " << RESET << std::endl;
	NS::vector<int> vct(5, 5);
	print_vector(vct);
	std::cout << YELLDARK << BOLD << "  | " << UL << "insert(pos, value):" << RESET << " vct.insert(vct.end(), i * 7)" << std::endl;
	for (int i = 0; i < 4; ++i)
		vct.insert(vct.end(), i * 7);
	print_vector(vct);
	std::cout << YELLDARK << BOLD << "  | " << UL << "insert(pos, times, value):" << RESET << " vct.insert(vct.end() - 2, 3, 42)" << std::endl;
	vct.insert(vct.end() - 2, 3, 42);
	print_vector(vct);
	NS::vector<int>::iterator it = vct.begin();
	NS::vector<int> vct2(2,400);
	std::cout << YELLDARK << BOLD << "  | " << UL << "insert(pos, iterator, iterator):" << RESET << " vct.insert(vct.end(), i * 7)" << std::endl;
	vct.insert(it + 3,vct2.begin(),vct2.end());
	print_vector(vct);
}

void ft_check_erase(void)
{
	std::cout << PINK << ULL << "▶️​  ERASE TESTS " << RESET << std::endl;
	NS::vector<int> vct(10, 5);
	print_vector(vct);
	std::cout << YELLDARK << BOLD << "  | " << UL << "erase(pos):" << RESET << " vct.erase(vct.begin())" << std::endl;
	vct.erase(vct.begin());
	print_vector(vct);
	std::cout << YELLDARK << BOLD << "  | " << UL << "erase(pos) in loop:" << RESET << " vct.erase(vct.begin())" << std::endl;
	for (int i = 0; i < 4; i++)
		vct.erase(vct.begin());
	print_vector(vct);
	std::cout << YELLDARK << BOLD << "  | " << UL << "erase(pos, pos):" << RESET << " vct.erase(3)" << std::endl;
	vct.erase(vct.begin() + 2, vct.end() - 2);
	print_vector(vct);

}

void ft_swap_test(void)
{
	std::cout << PINK << ULL << "▶️​  SWAP TESTS " << RESET << std::endl;
	NS::vector<int> vct(10, 5);
	std::cout << "vct :";
	print_vector(vct);

	NS::vector<int> vct2(3, 42);
	std::cout << "vct2 :";
	print_vector(vct2);
	std::cout << YELLDARK << BOLD << "  | " << UL << "swap:" << RESET << " vct.swap(vct2)" << std::endl;
	vct.swap(vct2);
	print_vector(vct);
}

void copy_swap_tests(void)
{

	NS::vector<int> test;
	std::cout << "size : " << test.size() << " | capacity : " << test.capacity() << std::endl;

	for (size_t i = 0; i < 50; i++) { test.push_back(i); }
	std::cout << "size : " << test.size() << " | capacity : " << test.capacity() << std::endl;
	std::cout << std::endl;
	NS::vector<int> test_copy(test);
	for (size_t i = 0; i < test_copy.size(); i++) { test_copy[i] += 100; }
	std::cout << "size : " << test_copy.size() << " | capacity : " << test_copy.capacity() << std::endl;
	NS::vector<int> test_range(test.begin() + 20, test.begin() + 30);
	std::cout << "size : " << test_range.size() << " | capacity : " << test_range.capacity() << std::endl;
	test_copy.swap(test);
	std::cout << "size : " << test.size() << " | capacity : " << test.capacity() << std::endl;
	std::cout << "size : " << test_copy.size() << " | capacity : " << test_copy.capacity() << std::endl;
	test_copy.swap(test_range);
	std::cout << "size : " << test_range.size() << " | capacity : " << test_range.capacity() << std::endl;
	std::cout << "size : " << test_copy.size() << " | capacity : " << test_copy.capacity() << std::endl;
	test.swap(test_copy);
	std::cout << "size : " << test.size() << " | capacity : " << test.capacity() << std::endl;
	std::cout << "size : " << test_copy.size() << " | capacity : " << test_copy.capacity() << std::endl;
}

void ft_clear_test(void)
{
	std::cout << PINK << ULL << "▶️​  CLEAR TESTS " << RESET << std::endl;
	NS::vector<int> vct(10, 5);
	std::cout << "vct :";
	print_vector(vct);
	std::cout << YELLDARK << BOLD << "  | " << UL << "clear:" << RESET << " vct.clear()" << std::endl;
	vct.clear();
	print_vector(vct);
}

/*******************************ELEMENT ACCESS*********************************/

void ft_check_comparaison(void)
{
	NS::vector<int> vct(4);
	NS::vector<int> vct2(4);

	// cmp(vct, vct);  // 0
	std::cout << PINK << ULL << "▶️​  COMPARAISON TESTS " << RESET << std::endl;

	std::cout << "eq: " << (vct == vct) << " | ne: " << (vct != vct) << std::endl;
	std::cout << "lt: " << (vct < vct) << " | le: " << (vct <= vct) << std::endl;
	std::cout << "gt: " << (vct > vct) << " | ge: " << (vct >= vct) << std::endl;

	std::cout << "eq: " << (vct == vct2) << " | ne: " << (vct != vct2) << std::endl;
	std::cout << "lt: " << (vct < vct2) << " | le: " << (vct <= vct2) << std::endl;
	std::cout << "gt: " << (vct > vct2) << " | ge: " << (vct >= vct2) << std::endl;

	// cmp(vct, vct2); // 1
}

void ft_front_back(void)
{
	std::cout << PINK << ULL << "▶️​  FRONT TESTS " << RESET << std::endl;
	NS::vector<int> vct;
	for (int i = 1; i < 10; i++)
		vct.insert(vct.begin(), i * 2);
	std::cout << "vct :";
	print_vector(vct);
	std::cout << YELLDARK << BOLD << "  | " << UL << "front:" << RESET << " vct.front()" << std::endl;
	std::cout << vct.front() << std::endl;
	std::cout << YELLDARK << BOLD << "  | " << UL << "back:" << RESET << " vct.back()" << std::endl;
	std::cout << vct.back() << std::endl;
}

void vector_tests(void)
{
	std::cout << BOLD << BLUE << "****************************************" << std::endl;
	std::cout << "*                                      *" << std::endl;
	std::cout << "*            VECTOR TESTS              *" << std::endl;
	std::cout << "*                                      *" << std::endl;
	std::cout << "****************************************" << RESET << std::endl << std::endl;

	/**CONSTRUCTORS**/
	std::cout << RED << BOLD << "------------- CONSTRUCTORS -------------" << RESET << std::endl << std::endl;
		check_constructor();
		ft_check_assign();
		// copy_swap_tests();

	/**CAPACITY**/
	std::cout << RED << BOLD << "------------- CAPACITY -------------" << RESET << std::endl << std::endl;
		check_capacity();
		// reserve_ref();
		// check_resize_ref();

	/**MODIFIERS**/
	std::cout << RED << BOLD << "------------- MODIFIERS -------------" << RESET << std::endl << std::endl;
		ft_check_pushback();
		// push_pop_back_tests();
		// ft_check_pushback_bis();
		// ft_check_insert_ref();
		ft_check_insert();
		ft_check_erase();
		ft_swap_test();
		ft_clear_test();
		// ft_check_erase_bis();
		// std_check_erase_bis();
		// ft_check_insert_bis();

	/**ELEMENT ACCESS**/
		ft_check_comparaison();
		ft_front_back();
}
