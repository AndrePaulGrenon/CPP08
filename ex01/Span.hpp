/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 19:35:28 by samirbouzid       #+#    #+#             */
/*   Updated: 2022/04/03 23:19:36 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP
#include <vector>
#include <iostream>

class Span
{
	public:
		Span(unsigned int n);
		Span(const Span &src);
		~Span();

		Span &operator=(const Span &src);
	
		void addNumber(int n);
		void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);

		int shortestSpan() const;
		int longestSpan() const;

        private:
		unsigned int N;
		unsigned int stored;
		std::vector<int> vect;
		Span();

};

#endif
