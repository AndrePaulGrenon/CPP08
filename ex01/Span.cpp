/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 19:35:17 by samirbouzid       #+#    #+#             */
/*   Updated: 2022/04/03 23:26:16 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <exception>
#include <cstdlib>
#include <iterator>
#include <algorithm>
#include <iostream>

Span::Span(unsigned int n): N(n), vect(0)
{
}

Span::Span(const Span &src)
{
	*this = src;
}

Span::~Span()
{}

Span &Span::operator=(const Span &src)
{
	if (this == &src)
		return (*this);
	N = src.N;
	vect = src.vect;
	return (*this);
}

void Span::addNumber(int n)
{
	if (vect.size() == N)
		throw std::out_of_range("Vector is full");
	vect.push_back(n);
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	std::vector<int> tmp(begin, end);
	if (tmp.size() >= (N - vect.size()))
		throw std::out_of_range("range is too big for the space left");
	copy(tmp.begin(), tmp.end(), std::back_inserter(vect));
}

//sort : trie le vector par ordre croissant.

int	Span::shortestSpan() const
{
	int res;
	std::vector<int> tmp = vect;
	if (vect.size() < 2)
		throw std::logic_error("Need at least 2 numbers in the vector");
	sort(tmp.begin(), tmp.end());
	res = (tmp[1] - tmp[0]);
	for (std::vector<int>::iterator it = tmp.begin() + 1; it < tmp.end() - 1; it++)
	{
		if (*(it + 1) - *it < res)
			res = *(it + 1) - *it;
	}
	return (res);
}

int	Span::longestSpan() const
{
	std::vector<int> tmp = vect;
	if (vect.size() <= 1)
		throw std::logic_error("Need at least 2 numbers in the vector");
	sort(tmp.begin(), tmp.end());
	return (*(tmp.end() - 1) - *tmp.begin());
}