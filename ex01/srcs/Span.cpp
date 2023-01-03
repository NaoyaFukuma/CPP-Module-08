/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:11:59 by nfukuma           #+#    #+#             */
/*   Updated: 2023/01/03 21:46:29 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

Span::Span(unsigned int n)
	: n_(n)
{
}

Span::Span(const Span &src)
{
	*this = src;
}

Span &Span::operator=(Span const &rhs)
{
	if (this != &rhs)
	{
		this->n_ = rhs.n_;
		this->vector_ = rhs.vector_;
	}
	return (*this);
}

Span::~Span()
{
}

void Span::addNumber(int n)
{
	if (this->vector_.size() >= this->n_)
		throw AlreadyFullException();
	this->vector_.push_back(n);
}

void Span::addNumber(std::vector<int>::const_iterator src_begin,
						std::vector<int>::const_iterator src_end)
{
	// if ((this->n_ - static_cast<unsigned int>(this->vector_.size())) < std::distance(src_begin, src_end))
	if ((this->n_ - static_cast<unsigned int>(this->vector_.size())) < src_end - src_begin)
		throw AlreadyFullException();
	this->vector_.insert(vector_.end(), src_begin, src_end);
}

void Span::setNum(std::vector<int>::size_type posi, int num)
{
	try
	{
		this->vector_.at(posi) = num;
	}
	catch(const std::out_of_range& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int Span::getNum(std::vector<int>::size_type posi)
{
	return (this->vector_[posi]);
}

std::vector<int>::iterator Span::begin()
{
	return(this->vector_.begin());
}

const std::vector<int>::const_iterator Span::begin() const
{
	return(this->vector_.begin());
}

std::vector<int>::iterator Span::end()
{
	return(this->vector_.end());
}

const std::vector<int>::const_iterator Span::end() const
{
	return(this->vector_.end());
}

const std::vector<int> *Span::getList(void) const
{
	return (&this->vector_);
}

unsigned int Span::longestSpan(void) const
{
	if (this->vector_.size() < 2)
		throw NoSpanException();
	return (*std::max_element(this->vector_.begin(), this->vector_.end())
		- *std::min_element(this->vector_.begin(), this->vector_.end()));
}

unsigned int Span::shortestSpan(void) const
{
	if (this->vector_.size() < 2)
		throw NoSpanException();
	unsigned int min = Span::longestSpan();
	for (std::vector<int>::const_iterator it = this->vector_.begin(); it != this->vector_.end(); ++it)
	{
		for (std::vector<int>::const_iterator it2 = this->vector_.begin(); it2 != this->vector_.end(); ++it2)
		{
			if (it == it2)
				continue ;
			if (std::abs(*it2 - *it) < static_cast<int>(min))
				min = std::abs(*it2 - *it);
		}
	}
	return (min);
}

std::ostream &operator<<(std::ostream &os, const Span &span)
{
	for (std::vector<int>::const_iterator it = span.getList()->begin(); it != span.getList()->end(); ++it)
		os << *it << " ";
	return (os);
}

const char *Span::AlreadyFullException::what() const throw()
{
	return ("Error: Already full");
}

const char *Span::NoSpanException::what() const throw()
{
	return ("Error: No Span");
}
