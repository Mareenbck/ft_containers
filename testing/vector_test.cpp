/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 14:36:54 by mbascuna          #+#    #+#             */
/*   Updated: 2022/11/15 13:15:24 by mbascuna         ###   ########.fr       */
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
	std::cout << YELLOW << "▶️​​  CONSTRUCTORS TESTS " << RESET << std::endl << std::endl;
	std::cout << " " << GREEN << " | " << UL << "default:" << RESET << " vector();" << std::endl;
	{
		NS::vector<int> vec;
		print_vector(vec);
	}
	std::cout << " " << GREEN << " | " << UL << "with size:" << RESET << " vector(5);" << std::endl;
	{
		NS::vector<int> vec(5);
		print_vector(vec);
	}
	std::cout << " " << GREEN << " | " << UL << "with size + value:" << RESET << " vector(5, 42);" << std::endl;
	{
		NS::vector<int> vec(5, 42);
		print_vector(vec);
		std::cout << " " << GREEN << " | " << UL << "with iterator:" << RESET << " vector(vec.begin(), vec.end());" << std::endl;
		NS::vector<int> vec1(vec.begin(), vec.end());
		print_vector(vec1);
		std::cout << " " << GREEN << " | " << UL << "with range:" << RESET << " vct_range(it, --(--ite));" << std::endl;
		NS::vector<int>::iterator it = vec.begin(), ite = vec.end();
		NS::vector<int> vct_range(it, --(--ite));
		print_vector(vct_range);
		std::cout << " " << GREEN << " | " << UL << "copy:" << RESET << " vct_copy(vct);" << std::endl;
		NS::vector<int> vct_copy(vec);
		print_vector(vct_copy);
		std::cout << " " << GREEN << " | " << UL << "operator = " << RESET << " vct_range = vec;" << std::endl;
		vct_range = vec;
		print_vector(vct_range);
	}
}

void ft_check_assign(void)
{
	std::cout << YELLOW << "▶️​  ASSIGN TESTS " << RESET << std::endl;

	std::cout << " " << GREEN << " | " << UL << "assign:" << RESET << " vct(4, /"" Ola !/"");" << std::endl;
	NS::vector<std::string> vec3;
	vec3.assign(4, "Ola !");
	print_vector(vec3);

	std::cout << " " << GREEN << " | " << UL << "assign w/ iterator:" << RESET << " vec1.assign(lst.begin(), lst.end());" << std::endl;
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
	std::cout << YELLOW << "▶️​​  CAPACITY TESTS " << RESET << std::endl;
	std::cout << " " << GREEN << " | " << UL << "size empty:" << RESET << " vector()" << std::endl;
	NS::vector<int> vct;
	std::cout << "   size : " << vct.size() << " | capacity : " << vct.capacity() << " | max_size : " << vct.max_size() << std::endl << std::endl;
	std::cout << " " << GREEN << " | " << UL << "size 10000:" << RESET << " vct1(10000)" << std::endl;
	NS::vector<int> vct1(10000);
	std::cout << "   size : " << vct1.size() << " | capacity : " << vct1.capacity() << " | max_size : " << vct1.max_size() << std::endl << std::endl;
	std::cout << " " << GREEN << " | " << UL << "size 1:" << RESET << " vct2(1)" << std::endl;
	NS::vector<int> vct2(1);
	std::cout << "   size : " << vct2.size() << " | capacity : " << vct2.capacity() << " | max_size : " << vct2.max_size() << std::endl << std::endl;

	std::cout << YELLOW << "​▶️​​  RESIZE TESTS " << RESET << std::endl;
	std::cout << " " << GREEN << " | " << UL << "resize():" << RESET << " vct1.resize(5, 42)" << std::endl;
	vct1.resize(5, 42);
	print_vector(vct1);
	std::cout << " " << GREEN << " | " << UL << "resize():" << RESET << " vct.resize(42)" << std::endl;
	vct.resize(42);
	print_vector(vct);
	std::cout << " " << GREEN << " | " << UL << "resize():" << RESET << " vct2.resize(0)" << std::endl;
	vct2.resize(0);
	print_vector(vct2);

	std::cout << YELLOW << "▶️​​  EMPTY TESTS " << RESET << std::endl;
	std::cout << " " << GREEN << " | " << UL << "vct:" << RESET << " " << vct.size() << std::endl;
	std::cout << "   bool :" << vct.empty() << std::endl;
	std::cout << " " << GREEN << " | " << UL << "vct1:" << RESET << " " << vct1.size() << std::endl;
	std::cout << "   bool :" << vct1.empty() << std::endl;
	std::cout << " " << GREEN << " | " << UL << "vct2:" << RESET << " " << vct2.size() << std::endl;
	std::cout << "   bool :" << vct2.empty() << std::endl << std::endl;

	std::cout << YELLOW << "▶️​​  RESERVE TESTS " << RESET << std::endl;
	std::cout << " " << GREEN << " | " << UL << "reserve:" << RESET << " vct.reserve(10)" << std::endl;
	vct.reserve(10);
	print_vector(vct);
	std::cout << " " << GREEN << " | " << UL << "reserve:" << RESET << " vct1.reserve(100)" << std::endl;
	vct1.reserve(100);
	print_vector(vct1);
	std::cout << " " << GREEN << " | " << UL << "reserve:" << RESET << " vct2.reserve(0)" << std::endl;
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
	// int myint;

	// std::cout << "Please enter some integers (enter 0 to end):\n";
	myvector.push_back(1);
	myvector.push_back(2);
	myvector.push_back(3);
	myvector.pop_back();

	std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
	for (int i = 0; i < int(myvector.size()); i++)
		std::cout << myvector[i] << " ";
	std::cout << std::endl;

	NS::vector<int> vct;
	std::cout << YELLOW << "▶️​  PUSH_BACK TESTS " << RESET << std::endl;
	std::cout << " " << GREEN << " | " << UL << "push_back:" << RESET << " vct.push_back(42)" << std::endl;
	vct.push_back(42);
	print_vector(vct);
	std::cout << " " << GREEN << " | " << UL << "push_back in loop:" << RESET << " vct.push_back(54)" << std::endl;
		for (int i = 0; i < 3;  i++)
			vct.push_back(54);
	print_vector(vct);

	std::cout << YELLOW << "▶️​  POP_BACK TESTS " << RESET << std::endl;

	// std::cout << SPACE << BOLD << ORANGE << UL << "--> push_back():" << RESET << " vec1.push_back();" << std::endl << std::endl;
	// 	std::cout << TAB << "-> push_back 42 in vec1 : vec1.push_back(42);" << std::endl;
	// 	vec1.push_back(42);
	// 	printVec(vec1, 1);
	// 	std::cout << TAB << "-> push_back 3 times 42 in vec1 : vec1.push_back(42);" << std::endl;
	// 	for (int i = 0; i < 3;  i++)
	// 		vec1.push_back(42);
	// 	printVec(vec1, 1);
	// 	std::cout << TAB << "-> push_back 42 in an empty vector : vec2.push_back(42);" << std::endl;
	// 	{
	// 		NS::vector<T1> vec2;
	// 		vec2.push_back(42);
	// 		printVec(vec2, 1);
	// 	}
	// 	std::cout << SPACE << BOLD << ORANGE << UL << "--> pop_back():" << RESET << " vec1.pop_back();" << std::endl << std::endl;
	// 	std::cout << TAB << "-> pop_back vec1 : vec1.pop_back();" << std::endl;
	// 	vec1.pop_back();
	// 	printVec(vec1, 1);
	// 	std::cout << TAB << "-> pop_back 3 times vec1 : vec1.pop_back();" << std::endl;
	// 	for (int i = 0; i < 3;  i++)
	// 		vec1.pop_back();
	// 	printVec(vec1, 1);
	// 	std::cout << TAB << "-> pop_back 4 times vec1 : vec1.pop_back();" << std::endl;
	// 	for (int i = 0; i < 4;  i++)
	// 		vec1.pop_back();
	// 	printVec(vec1, 1);
}

int	ft_check_pushback_bis(void)
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
	return (0);
}

void push_pop_back_tests(void)
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

void ft_check_insert()
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

void ft_check_insert_bis()
{
	std::cout << std::endl << "INSERT TESTS" << std::endl;
	NS::vector<int> test(1, 1);
	NS::vector<int> test2(5, 5);

	test.insert(test.begin(), 200, 12);
	std::cout << "size : " << test.size() << "  |  capacity : " << test.capacity() << std::endl;
	test.insert(test.begin() + 12, 200, 30);
	std::cout << "size : " << test.size() << "  |  capacity : " << test.capacity() << std::endl;
	test.insert(test.end(), 10, 50);
	std::cout << "size : " << test.size() << "  |  capacity : " << test.capacity() << std::endl;
	test.insert(test.end() - 1, 0, 60);
	std::cout << "size : " << test.size() << "  |  capacity : " << test.capacity() << std::endl;
	test.insert(test.end() - 1, 1, 70);
	std::cout << "size : " << test.size() << "  |  capacity : " << test.capacity() << std::endl;
	test.insert(test.begin() + 412, test2.begin(), test2.end());
	std::cout << "size : " << test.size() << "  |  capacity : " << test.capacity() << std::endl;
	test.insert(test.begin() + 6, test2.begin(), test2.end());
	std::cout << "size : " << test.size() << "  |  capacity : " << test.capacity() << std::endl;
	test.insert(test.end(), test2.begin(), test2.end());
	std::cout << "size : " << test.size() << "  |  capacity : " << test.capacity() << std::endl;
}

void ft_check_erase(void)
{
	NS::vector<int> second(5,100);
	NS::vector<int>::iterator it1;

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

	NS::vector<int> first(10,20);
	NS::vector<int>::iterator it;

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

	NS::vector<int> real(10,20);
	NS::vector<int>::iterator itr;

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

void ft_check_erase_bis(void)
{
	NS::vector<int> myvector;

  // set some values (from 1 to 10)
	for (int i=1; i<=10; i++) myvector.push_back(i);
	std::cout << " my vector :";
	for (NS::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << " size " << myvector.size() << std::endl;

  // erase the 6th element
	myvector.erase(myvector.begin()+5);
	std::cout << "erase the 6th element :";
	for (NS::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << " size " << myvector.size() << std::endl;

  // erase the first 3 elements:
	myvector.erase (myvector.begin(),myvector.begin()+3);
	std::cout << "erase the first 3 elements :";
	for (unsigned i=0; i<myvector.size(); ++i)
		std::cout << ' ' << myvector[i];
	std::cout << '\n';
	std::cout << " size " << myvector.size() << std::endl;
}

void std_check_erase_bis(void)
{
	NS::vector<std::string> myvector(10);

  // set some values (from 1 to 10)
	for (unsigned long i = 0; i< myvector.size(); ++i)
		myvector[i] = std::string((myvector.size() - i), i + 65);
	std::cout << " my vector :";
	for (NS::vector<std::string>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << " | " << *it;
	std::cout << '\n';
	std::cout << " size " << myvector.size() << std::endl;

  // erase the 6th element
	myvector.erase(myvector.begin()+2);
	std::cout << "erase the 2th element :";
	for (NS::vector<std::string>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << " | " << *it;
	std::cout << '\n';
	std::cout << " size " << myvector.size() << std::endl;

	myvector.erase(myvector.begin());
	std::cout << "erase the 1rst element :";
	for (NS::vector<std::string>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << " | " << *it;
	std::cout << '\n';
	std::cout << " size " << myvector.size() << std::endl;

	myvector.erase(myvector.end() - 1);
	std::cout << "erase the end -1 element :";
	for (NS::vector<std::string>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << " | " << *it;
	std::cout << '\n';
	std::cout << " size " << myvector.size() << std::endl;

	myvector.erase(myvector.begin(), myvector.begin() + 3);
	std::cout << "erase the begin to begin + 3 element :";
	for (NS::vector<std::string>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << " | " << *it;
	std::cout << '\n';
	std::cout << " size " << myvector.size() << std::endl;

	myvector.erase(myvector.end() - 3, myvector.end() - 1);
	std::cout << "erase the end -3 to end element :";
	for (NS::vector<std::string>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << " | " << *it;
	std::cout << '\n';
	std::cout << " size " << myvector.size() << std::endl;
}

void copy_swap_tests(void)
{
	std::cout << std::endl << "COPY && SWAP TESTS" << std::endl;
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


/*******************************ELEMENT ACCESS*********************************/

void std_check_comparaison(void)
{
	NS::vector<int> vct(4);
	NS::vector<int> vct2(4);

	NS::vector<int> ftvct(4);
	NS::vector<int> ftvct2(4);

	// cmp(vct, vct);  // 0
	std::cout << "************   STD  ************" << std::endl;
	std::cout << "eq: " << (vct == vct) << " | ne: " << (vct != vct) << std::endl;
	std::cout << "lt: " << (vct < vct) << " | le: " << (vct <= vct) << std::endl;
	std::cout << "gt: " << (vct > vct) << " | ge: " << (vct >= vct) << std::endl;

	std::cout << "************   FT  ************" << std::endl;
	std::cout << "eq: " << (ftvct == ftvct) << " | ne: " << (ftvct != ftvct) << std::endl;
	std::cout << "lt: " << (ftvct < ftvct) << " | le: " << (ftvct <= ftvct) << std::endl;
	std::cout << "gt: " << (ftvct > ftvct) << " | ge: " << (ftvct >= ftvct) << std::endl;

	std::cout << "************   STD  ************" << std::endl;
	std::cout << "eq: " << (vct == vct2) << " | ne: " << (vct != vct2) << std::endl;
	std::cout << "lt: " << (vct < vct2) << " | le: " << (vct <= vct2) << std::endl;
	std::cout << "gt: " << (vct > vct2) << " | ge: " << (vct >= vct2) << std::endl;

	std::cout << "************   FT  ************" << std::endl;
	std::cout << "eq: " << (ftvct == ftvct2) << " | ne: " << (ftvct != ftvct2) << std::endl;
	std::cout << "lt: " << (ftvct < ftvct2) << " | le: " << (ftvct <= ftvct2) << std::endl;
	std::cout << "gt: " << (ftvct > ftvct2) << " | ge: " << (ftvct >= ftvct2) << std::endl;
	std::cout << "*************************" << std::endl;
	// cmp(vct, vct2); // 1
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

		// ft_check_pushback();
		// push_pop_back_tests();
		// ft_check_pushback_bis();
		// ft_check_insert();
		// ft_check_erase();
		// ft_check_erase_bis();
		// std_check_erase_bis();
		// ft_check_insert_bis();

	/**ELEMENT ACCESS**/
		// std_check_comparaison();
}
