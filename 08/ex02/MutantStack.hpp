/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 14:07:57 by aindjare          #+#    #+#             */
/*   Updated: 2025/11/02 16:33:08 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef   MUTANTSTACK_HPP
#define   MUTANTSTACK_HPP
#include <stack>
#include <deque>
#include <stdexcept>
template <typename T>
class MutantStack: public std::stack<T, std::deque<T> > {
public: /* MutantStack::iterator */
	typedef typename std::deque<T>::iterator			iterator;
	typedef typename std::deque<T>::reverse_iterator	reverse_iterator;

public: /* MutantStack::MutantStack */
	iterator	begin(void) {
		return (this->c.begin());
	};
	iterator	end(void) {
		return (this->c.end());
	};
	reverse_iterator	rbegin(void) {
		return (this->c.rbegin());
	};
	reverse_iterator	rend(void) {
		return (this->c.rend());
	};
};
#endif /* MUTANTSTACK_HPP */
