/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 09:45:08 by aindjare          #+#    #+#             */
/*   Updated: 2025/11/02 14:03:01 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <stdexcept>

#define ABS(X) ((X) > 0 ? +(X) : -(X))

Span::Span(unsigned int n): n(n), longest(-1), shortest(-1), integers()  {
	integers.reserve(n);
};
Span::~Span(void) { }
Span::Span(const Span& span) {
	(*this) = span;
}
Span&		Span::operator=(const Span& span) {
	if (this != &span) {
		this->n = span.n;
		this->longest = span.longest;
		this->shortest = span.shortest;
		this->integers = span.integers;
	}
	return (*this);
}

int			Span::shortestSpan(void) const {
	if (this->shortest < 0) {
		throw std::runtime_error("Not enough numbers in span");
	}
	return (this->shortest);
}
int			Span::longestSpan(void) const {
	if (this->longest < 0) {
		throw std::runtime_error("Not enough numbers in span");
	}
	return (this->longest);
}

void		Span::addNumber(int number) {
	if (this->integers.size() >= this->n) {
		throw std::runtime_error("Ran out of space while attempting addNumber");
	}

	this->integers.push_back(number);
	if (this->integers.size() >= 2) {
		int	curr = this->integers[this->integers.size() - 1];
		int	prev = this->integers[this->integers.size() - 2];
		int	dist = ABS(curr - prev);
		if (this->longest == -1 || dist > this->longest) {
			this->longest = dist;
		}
		if (this->shortest == -1 || dist < this->shortest) {
			this->shortest = dist;
		}
	}
}
void		Span::addNumbers(Span::iterator begin, Span::iterator end) {
	size_t	count = 0;
	for (Span::iterator	iter = begin; iter != end; ++iter) {
		++count;
	}

	if (this->integers.size() + count > this->n) {
		throw std::runtime_error("Ran out of space while attempting addNumbers");
	}

	this->integers.insert(this->integers.begin(), begin, end);
	for (size_t i = 1; i < this->integers.size(); ++i) {
		int	curr = this->integers[i - 0];
		int	prev = this->integers[i - 1];

		int	dist = ABS(curr - prev);
		if (this->longest == -1 || dist > this->longest) {
			this->longest = dist;
		}
		if (this->shortest == -1 || dist < this->shortest) {
			this->shortest = dist;
		}
	}
}

