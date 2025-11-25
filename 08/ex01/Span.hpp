/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenobas <rahimos.123@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:17:35 by xenobas           #+#    #+#             */
/*   Updated: 2025/11/25 15:21:23 by xenobas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP
#include <vector>
#include <iterator>
#include <stdexcept>

class Span {
private:
	typedef std::vector<int>::iterator			iterator;
	typedef std::vector<int>::const_iterator	const_iterator;
public:
	Span(int cap);
	Span(unsigned int cap);
	Span(size_t cap);
	Span(const Span& span);

	~Span(void);

	Span&			operator=(const Span& span);
	int&			operator[](int i);
	const int&		operator[](int i) const;

	void			addNumber(int n);
	template <typename InputIterator>
	void		addNumbers(InputIterator begin, InputIterator end) {
		int	dist = static_cast<int>(std::distance(begin, end));
		int	size = this->size();
		int	capacity = this->capacity();
		if (size + dist > capacity) {
			throw std::runtime_error("Cannot add more numbers to a span that reached its capacity");
		}

		this->container.insert(this->container.end(), begin, end);
	}

	int				size(void) const;
	int				capacity(void) const;
	
	iterator		begin(void);
	const_iterator	begin(void) const;
	iterator		end(void);
	const_iterator	end(void) const;

	int				shortestSpan(void);
	int				longestSpan(void);

private:
	std::vector<int>	container;
};
#endif
