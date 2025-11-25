/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenobas <rahimos.123@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:15:22 by xenobas           #+#    #+#             */
/*   Updated: 2025/11/25 15:22:10 by xenobas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <stdexcept>
#include <algorithm>

Span::Span(int cap) {
	if (cap <= 0) {
		throw std::runtime_error("Invalid capacity for Span instance");
	}

	this->container.reserve(cap);
}
Span::Span(unsigned int cap) {
	if (cap == 0) {
		throw std::runtime_error("Invalid capacity for Span instance");
	}
	this->container.reserve(cap);
}
Span::Span(size_t cap) {
	if (cap == 0) {
		throw std::runtime_error("Invalid capacity for Span instance");
	}
	this->container.reserve(cap);
}
Span::~Span(void) {
}
Span::Span(const Span& span) {
	this->container = span.container;
}
Span&		Span::operator=(const Span& span) {
	if (this != &span) {
		this->container = span.container;
	}
	return (*this);
}

void		Span::addNumber(int n) {
	if (this->container.size() >= this->container.capacity()) {
		throw std::runtime_error("Cannot add an extra number to a span that reached its capacity");
	}

	this->container.push_back(n);
}

int			Span::size(void) const {
	return (static_cast<int>(this->container.size()));
}
int			Span::capacity(void) const {
	return (static_cast<int>(this->container.capacity()));
}

int&		Span::operator[](int i) {
	if (i < 0 || i >= static_cast<int>(this->container.capacity())) {
		throw std::runtime_error("Out of bounds access");
	}
	return (this->container[i]);
}
const int&	Span::operator[](int i) const {
	if (i < 0 || i >= static_cast<int>(this->container.capacity())) {
		throw std::runtime_error("Out of bounds access");
	}
	return (this->container[i]);
}

Span::iterator	Span::begin(void) {
	return (this->container.begin());
}
Span::iterator	Span::end(void) {
	return (this->container.end());
}

Span::const_iterator	Span::begin(void) const {
	return (this->container.begin());
}
Span::const_iterator	Span::end(void) const {
	return (this->container.end());
}

int			Span::shortestSpan(void) {
	if (this->size() < 2) {
		throw std::runtime_error("Not enough numbers to measure shortest span");
	}

	std::sort(this->begin(), this->end());

	Span&	self = *this;
	int		span = this->container.back() - this->container.front();
	int		size = this->size();
	for (int i = 1; i < size; ++i) {
		int	span_i = self[i - 0] - self[i - 1];
		if (span_i < span) {
			span = span_i;
		}
	}
	return (span);
}
int			Span::longestSpan(void) {
	if (this->size() < 2) {
		throw std::runtime_error("Not enough numbers to measure shortest span");
	}

	iterator	a = std::min_element(this->begin(), this->end());
	iterator	b = std::max_element(this->begin(), this->end());
	return (*b - *a);
}
