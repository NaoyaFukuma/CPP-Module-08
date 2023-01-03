/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:23:07 by nfukuma           #+#    #+#             */
/*   Updated: 2023/01/03 14:07:08 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
# include <deque>
# include <list>
# include <vector>

int	main(void)
{
	std::vector<int> vec;
	std::list<int> list;
	std::deque<int> deque;
	std::vector<int>::iterator v_iter;
	std::list<int>::iterator l_iter;
	std::deque<int>::iterator d_iter;


	std::cout << "Create containers. vector<int>, list<int>, deque<int>.\n" << std::endl;

	for (int i = 1; i < 6; i++)
	{
		vec.push_back(i);
		list.push_back(i * 3);
		deque.push_back(i * 11);
	}
	std::cout << "vector<int>" << std::endl;
	for (v_iter = vec.begin(); v_iter != vec.end(); v_iter++)
		std::cout << *v_iter << " " << std::flush;
	std::cout << std::endl;
	std::cout << "" << std::endl;
	std::cout << "list<int>" << std::endl;
	for (l_iter = list.begin(); l_iter != list.end(); l_iter++)
		std::cout << *l_iter << " " << std::flush;
	std::cout << std::endl;
	std::cout << "" << std::endl;
	std::cout << "deque<int>" << std::endl;
	for (d_iter = deque.begin(); d_iter != deque.end(); d_iter++)
		std::cout << *d_iter << " " << std::flush;
	std::cout << std::endl;
	std::cout << "" << std::endl;

	try
	{
		std::cout << "test vector<int> target value 2\n -> result " << std::flush;
		v_iter = easyfind(vec, 2);
		std::cout << "hit!! *v_iter print " << *v_iter << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "" << std::endl;

	try
	{
		std::cout << "test list<int> target value 10\n -> result " << std::flush;
		l_iter = easyfind(list, 10);
		std::cout << "hit!! *l_iter print " << *l_iter << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "" << std::endl;

	try
	{
		std::cout << "test deque<int> target value 11\n -> result " << std::flush;
		d_iter = easyfind(deque, 11);
		std::cout << "hit!! *d_iter print " << *d_iter << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
