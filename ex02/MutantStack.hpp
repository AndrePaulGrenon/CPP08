/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 23:37:39 by samirbouzid       #+#    #+#             */
/*   Updated: 2022/04/03 23:39:40 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <stack>
#include <iostream>
#include <iterator>

template<class T>
class MutantStack: public std::stack<T>
{
	public:
		MutantStack<T>() {}
		MutantStack<T>(const MutantStack<T> &src){*this = src;}
		~MutantStack<T>() {}

		MutantStack<T> &operator=(const MutantStack<T> &src)
		{
			if (this == &src)
				return (*this);
		std::cout << "test" << std::endl;
			std::stack<T>::operator=(src);
		std::cout << "test2" << std::endl;
			return (*this);
		}

		typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator begin() { return (std::stack<T>::c.begin()); }
		iterator end() { return (std::stack<T>::c.end()); }

		const_iterator begin() const { return (std::stack<T>::c.begin()); }
		const_iterator end() const { return (std::stack<T>::c.end()); }

		reverse_iterator rbegin() { return (std::stack<T>::c.rbegin()); }
		reverse_iterator rend() { return (std::stack<T>::c.rend()); }

		const_reverse_iterator rbegin() const { return (std::stack<T>::c.rbegin()); }
		const_reverse_iterator rend() const { return (std::stack<T>::c.rend()); }
};

#endif