/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:03:27 by nfukuma           #+#    #+#             */
/*   Updated: 2023/01/03 21:16:28 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <exception>
# include <vector>

class Span
{
  private:
	std::vector<int> vector_;
	unsigned int n_;

	Span();

  public:
	Span(unsigned int);
	Span(const Span &);
	~Span();

	Span &operator=(const Span &);
	void addNumber(int);
	void addNumber(std::vector<int>::const_iterator src_begin,
					std::vector<int>::const_iterator src_end);
	unsigned int longestSpan() const;
	unsigned int shortestSpan() const;

	void setNum(std::vector<int>::size_type posi, int num);
	int getNum(std::vector<int>::size_type posi);
	std::vector<int>::iterator begin();
	const std::vector<int>::const_iterator begin() const;
	std::vector<int>::iterator end();
	const std::vector<int>::const_iterator end() const;
	const std::vector<int> *getList() const;

	class AlreadyFullException : public std::exception
	{
		public:
		const char *what() const throw();
	};
	class NoSpanException : public std::exception
	{
		public:
		const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &, const Span &);

#endif
