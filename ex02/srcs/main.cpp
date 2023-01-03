/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 00:31:25 by nfukuma           #+#    #+#             */
/*   Updated: 2023/01/04 00:59:51 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

#include <iostream>
#include <list>
#include <vector>

#include "MutantStack.hpp"

int	main(void)
{
	std::cout << "/ ***** MutantStack ***** /" << std::endl;

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();
	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	/* -------------------------------------------------------------------- */

	std::cout << std::endl;
	std::cout << "/ ***** List ***** /" << std::endl;

	std::list<int> list;

	list.push_back(5);
	list.push_back(17);

	std::cout << list.back() << std::endl;

	list.pop_back();
	std::cout << list.size() << std::endl;

	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	//[...]
	list.push_back(0);

	std::list<int>::iterator list_it = list.begin();
	std::list<int>::iterator list_ite = list.end();
	++it;
	--it;
	while (list_it != list_ite)
	{
		std::cout << *list_it << std::endl;
		++list_it;
	}
	std::list<int> l(list);


	/* -------------------------------------------------------------------- */

	std::cout << std::endl;
	std::cout << "/ ***** Deque ***** /" << std::endl;

	std::deque<int> deq;

	deq.push_back(5);
	deq.push_back(17);

	std::cout << deq.back() << std::endl;

	deq.pop_back();
	std::cout << deq.size() << std::endl;

	deq.push_back(3);
	deq.push_back(5);
	deq.push_back(737);
	//[...]
	deq.push_back(0);

	std::deque<int>::iterator deq_it = deq.begin();
	std::deque<int>::iterator deq_ite = deq.end();
	++it;
	--it;
	while (deq_it != deq_ite)
	{
		std::cout << *deq_it << std::endl;
		++deq_it;
	}
	std::deque<int> d(deq);

	/* -------------------------------------------------------------------- */

	std::cout << std::endl;
	std::cout << "/ ***** Vector ***** /" << std::endl;

	std::vector<int> vec;

	vec.push_back(5);
	vec.push_back(17);

	std::cout << vec.back() << std::endl;

	vec.pop_back();
	std::cout << vec.size() << std::endl;

	vec.push_back(3);
	vec.push_back(5);
	vec.push_back(737);
	//[...]
	vec.push_back(0);

	std::vector<int>::iterator vec_it = vec.begin();
	std::vector<int>::iterator vec_ite = vec.end();
	++it;
	--it;
	while (vec_it != vec_ite)
	{
		std::cout << *vec_it << std::endl;
		++vec_it;
	}
	std::vector<int> v(vec);
}
