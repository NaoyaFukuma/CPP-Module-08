/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:13:52 by nfukuma           #+#    #+#             */
/*   Updated: 2023/01/02 17:20:21 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <deque>
# include <iostream>
# include <list>
# include <vector>

class NotFoundException : public std::exception
{
  public:
	const char *what() const throw()
	{
		return ("Error: Value not found!");
	}
};

template <typename T>
typename T::iterator easyfind(T &input, int value)
{
	typename T::iterator iter = std::find(input.begin(), input.end(), value);
	if (iter == input.end())
		throw NotFoundException();
	return (iter);
}

#endif
