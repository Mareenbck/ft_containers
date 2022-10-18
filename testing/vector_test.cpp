/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_test.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <mbascuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 14:36:54 by mbascuna          #+#    #+#             */
/*   Updated: 2022/10/18 16:57:17 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/containers/vector.hpp"
#include <vector>
#include <iterator>
#include <iostream>

/********************************CONSTRUCTORS**********************************/

void std_check_constructor (void)
{
	std::vector<int> vct(5);
	std::vector<int>::iterator it = vct.begin(), ite = vct.end();

	std::cout << "len: " << (ite - it) << std::endl;
	for (; it != ite; ++it)
		*it = (ite - it);

	it = vct.begin();
	std::vector<int> vct_range(it, --(--ite));
	for (int i = 0; it != ite; ++it)
		*it = ++i * 5;

	it = vct.begin();
	std::vector<int> vct_copy(vct);
	for (int i = 0; it != ite; ++it)
		*it = ++i * 7;
	vct_copy.push_back(42);
	vct_copy.push_back(21);

	std::cout << "\t-- PART ONE --" << std::endl;
	std::cout << "The contents of VCT are:";
	for (std::vector<int>::iterator it = vct.begin(); it != vct.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << " size " << vct.size() << std::endl;


	std::cout << "The contents of vct_range are:";
	for (std::vector<int>::iterator it = vct_range.begin(); it != vct_range.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << " size " << vct_range.size() << std::endl;


	std::cout << "The contents of vct_copy are:";
	for (std::vector<int>::iterator it = vct_copy.begin(); it != vct_copy.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << " size " << vct_copy.size() << std::endl;


	vct = vct_copy;
	vct_copy = vct_range;
	vct_range.clear();

	std::cout << "\t-- PART TWO --" << std::endl;
	std::cout << "The contents of VCT are:";
	for (std::vector<int>::iterator it = vct.begin(); it != vct.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << " size " << vct.size() << std::endl;


	std::cout << "The contents of vct_range are:";
	for (std::vector<int>::iterator it = vct_range.begin(); it != vct_range.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << " size " << vct_range.size() << std::endl;


	std::cout << "The contents of vct_copy are:";
	for (std::vector<int>::iterator it = vct_copy.begin(); it != vct_copy.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << " size " << vct_copy.size() << std::endl;
}

void ft_check_constructor_tester(void)
{
	ft::vector<int> vct(5);
	ft::vector<int>::iterator it = vct.begin(), ite = vct.end();
	std::cout << " ****************** FT ****************** " << std::endl;
	std::cout << "len: " << (ite - it) << std::endl;
	for (; it != ite; ++it)
		*it = (ite - it);

	it = vct.begin();
	ft::vector<int> vct_range(it, --(--ite));
	for (int i = 0; it != ite; ++it)
		*it = ++i * 5;

	it = vct.begin();
	ft::vector<int> vct_copy(vct);
	for (int i = 0; it != ite; ++it)
		*it = ++i * 7;
	vct_copy.push_back(42);
	vct_copy.push_back(21);

	std::cout << "\t-- PART ONE --" << std::endl;
	std::cout << "The contents of VCT are:";
	for (ft::vector<int>::iterator it = vct.begin(); it != vct.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << " size " << vct.size() << std::endl;


	std::cout << "The contents of vct_range are:";
	for (ft::vector<int>::iterator it = vct_range.begin(); it != vct_range.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << " size " << vct_range.size() << std::endl;


	std::cout << "The contents of vct_copy are:";
	for (ft::vector<int>::iterator it = vct_copy.begin(); it != vct_copy.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << " size " << vct_copy.size() << std::endl;


	vct = vct_copy;
	std::cout << " OLA " << std::endl;
	vct_copy = vct_range;
	vct_range.clear();

	std::cout << "\t-- PART TWO --" << std::endl;
	std::cout << "The contents of VCT are:";
	for (ft::vector<int>::iterator it = vct.begin(); it != vct.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << " size " << vct.size() << std::endl;


	std::cout << "The contents of vct_range are:";
	for (ft::vector<int>::iterator it = vct_range.begin(); it != vct_range.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << " size " << vct_range.size() << std::endl;


	std::cout << "The contents of vct_copy are:";
	for (ft::vector<int>::iterator it = vct_copy.begin(); it != vct_copy.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << " size " << vct_copy.size() << std::endl;

}

void ft_check_constructor(void)
{
  // constructors used in the same order as described above:
	ft::vector<int> first;                                // empty vector of ints
	ft::vector<int> second (4,100);                       // four ints with value 100
	ft::vector<int> third (second.begin(),second.end());  // iterating through second
	ft::vector<int> fourth (third);                       // a copy of third

	std::cout << "The contents of second are:";
	for (ft::vector<int>::iterator it = second.begin(); it != second.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "The contents of third are:";
	for (ft::vector<int>::iterator it = third.begin(); it != third.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "The contents of fourth are:";
	for (ft::vector<int>::iterator it = fourth.begin(); it != fourth.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
  // the iterator constructor can also be used to construct from arrays:
	int myints[] = {16,2,77,29};
	ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

	std::cout << "The contents of fifth are:";
	for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

int ft_check_assign(void)
{
	ft::vector<int> first;
	ft::vector<int> second;
	ft::vector<int> third;

	first.assign (7,100);             // 7 ints with a value of 100

	ft::vector<int>::iterator it;
	it=first.begin()+1;

	second.assign (it,first.end()-1); // the 5 central values of first

	int myints[] = {1776,7,4};
	third.assign (myints,myints+3);   // assigning from array.

	std::cout << "Size of first: " << int (first.size()) << '\n';
	std::cout << "Size of second: " << int (second.size()) << '\n';
	std::cout << "Size of third: " << int (third.size()) << '\n';
	return 0;
}

int	ft_check_assign_bis(void)
{
	std::vector<int> vct(7);
	std::vector<int> vct_two(4);
	std::vector<int> vct_three;
	std::vector<int> vct_four;

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 3;
	for (unsigned long int i = 0; i < vct_two.size(); ++i)
		vct_two[i] = (vct_two.size() - i) * 5;
	std::cout << "size : " << vct.size() << " | capacity : " << vct.capacity() << std::endl;
	std::cout << "size : " << vct_two.size() << " | capacity : " << vct_two.capacity() << std::endl;

	vct_three.assign(vct.begin(), vct.end());
	vct.assign(vct_two.begin(), vct_two.end());
	vct_two.assign(2, 42);
	vct_four.assign(4, 21);

	std::cout << "\t### After assign(): ###" << std::endl;

	std::cout << "size : " << vct.size() << " | capacity : " << vct.capacity() << std::endl;
	std::cout << "size : " << vct_two.size() << " | capacity : " << vct_two.capacity() << std::endl;
	std::cout << "size : " << vct_three.size() << " | capacity : " << vct_three.capacity() << std::endl;
	std::cout << "size : " << vct_four.size() << " | capacity : " << vct_four.capacity() << std::endl;

	vct_four.assign(6, 84);
	std::cout << "size : " << vct_four.size() << " | capacity : " << vct_four.capacity() << std::endl;


	std::cout << "\t### assign() on enough capacity and low size: ###" << std::endl;

	vct.assign(5, 53);
	vct_two.assign(vct_three.begin(), vct_three.begin() + 3);

	std::cout << "size : " << vct.size() << " | capacity : " << vct.capacity() << std::endl;
	std::cout << "size : " << vct_two.size() << " | capacity : " << vct_two.capacity() << std::endl;

	return (0);
}

void copy_swap_tests(void)
{
	std::cout << std::endl << "COPY && SWAP TESTS" << std::endl;
	ft::vector<int> test;
	std::cout << "size : " << test.size() << " | capacity : " << test.capacity() << std::endl;

	for (size_t i = 0; i < 50; i++) { test.push_back(i); }
	std::cout << "size : " << test.size() << " | capacity : " << test.capacity() << std::endl;
	std::cout << std::endl;
	ft::vector<int> test_copy(test);
	for (size_t i = 0; i < test_copy.size(); i++) { test_copy[i] += 100; }
	std::cout << "size : " << test_copy.size() << " | capacity : " << test_copy.capacity() << std::endl;
	ft::vector<int> test_range(test.begin() + 20, test.begin() + 30);
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

/*********************************ITERATORS************************************/

/**********************************CAPACITY************************************/

void ft_reserve(void)
{
	ft::vector<int>::size_type sz;

	ft::vector<int> foo;
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

	ft::vector<int> bar;
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

void ft_check_resize(void)
{
	std::cout << std::endl << "RESIZE TESTS" << std::endl;
	ft::vector<int> test(12, 12);

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

	ft::vector<int> myvector;
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
	ft::vector<int> myvector;
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
}

int	ft_check_pushback_bis(void)
{
	ft::vector<std::string> vct(8);
	ft::vector<std::string> vct2;
	ft::vector<std::string>::iterator it = vct.begin();

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
	ft::vector<int> test;

	std::cout << "Empty ? " << test.empty() << " / Capacity : " << test.capacity() << " / Size : " << test.size() << std::endl;
	for (size_t i = 0; i < 51; i++)
	{
		test.push_back(i);
		std::cout << test.size() << ": " << test.capacity() << " - ";
		if (!(i % 10) && i != 0)
			std::cout << std::endl;
	}

	for (ft::vector<int>::iterator it = test.begin(); it != test.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << " size " << test.size() << " | capacity : " << test.capacity() << std::endl;
	test.pop_back();
	test.pop_back();
	test.pop_back();
	test.pop_back();
	for (ft::vector<int>::iterator it = test.begin(); it != test.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << " size " << test.size() << " | capacity : " << test.capacity() << std::endl;
}

void ft_check_insert()
{
	ft::vector<int> myvector (3,100);
	ft::vector<int>::iterator it;
	ft::vector<int>::iterator ite = myvector.end();

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

	ft::vector<int> anothervector (2,400);
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
	ft::vector<int> test(1, 1);
	ft::vector<int> test2(5, 5);

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

void ft_check_erase_bis(void)
{
	ft::vector<int> myvector;

  // set some values (from 1 to 10)
	for (int i=1; i<=10; i++) myvector.push_back(i);
	std::cout << " my vector :";
	for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << " size " << myvector.size() << std::endl;

  // erase the 6th element
	myvector.erase(myvector.begin()+5);
	std::cout << "erase the 6th element :";
	for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
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
	std::vector<std::string> myvector(10);

  // set some values (from 1 to 10)
	for (unsigned long i = 0; i< myvector.size(); ++i)
		myvector[i] = std::string((myvector.size() - i), i + 65);
	std::cout << " my vector :";
	for (std::vector<std::string>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << " | " << *it;
	std::cout << '\n';
	std::cout << " size " << myvector.size() << std::endl;

  // erase the 6th element
	myvector.erase(myvector.begin()+2);
	std::cout << "erase the 2th element :";
	for (std::vector<std::string>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << " | " << *it;
	std::cout << '\n';
	std::cout << " size " << myvector.size() << std::endl;

	myvector.erase(myvector.begin());
	std::cout << "erase the 1rst element :";
	for (std::vector<std::string>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << " | " << *it;
	std::cout << '\n';
	std::cout << " size " << myvector.size() << std::endl;

	myvector.erase(myvector.end() - 1);
	std::cout << "erase the end -1 element :";
	for (std::vector<std::string>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << " | " << *it;
	std::cout << '\n';
	std::cout << " size " << myvector.size() << std::endl;

	myvector.erase(myvector.begin(), myvector.begin() + 3);
	std::cout << "erase the begin to begin + 3 element :";
	for (std::vector<std::string>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << " | " << *it;
	std::cout << '\n';
	std::cout << " size " << myvector.size() << std::endl;

	myvector.erase(myvector.end() - 3, myvector.end() - 1);
	std::cout << "erase the end -3 to end element :";
	for (std::vector<std::string>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << " | " << *it;
	std::cout << '\n';
	std::cout << " size " << myvector.size() << std::endl;
}

/*******************************ELEMENT ACCESS*********************************/

void std_check_comparaison(void)
{
	std::vector<int> vct(4);
	std::vector<int> vct2(4);

	ft::vector<int> ftvct(4);
	ft::vector<int> ftvct2(4);

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
	/**CONSTRUCTORS**/
		// ft_check_constructor();
		// ft_check_constructor_tester();
		// std_check_constructor();
		// ft_check_assign();
		// copy_swap_tests();
		ft_check_assign_bis();

	/**CAPACITY**/
		// ft_reserve();
		// ft_check_resize();

	/**MODIFIERS**/
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
