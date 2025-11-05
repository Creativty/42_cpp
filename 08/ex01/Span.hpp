/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 09:44:26 by aindjare          #+#    #+#             */
/*   Updated: 2025/11/02 10:52:06 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef   SPAN_HPP
#define   SPAN_HPP

#include <iterator>
#include <vector>

class Span {
private:
	unsigned int		n;
	int					longest;
	int					shortest;
	std::vector<int>	integers;
public:
	typedef std::vector<int>::iterator	iterator;
public:
	Span(unsigned int n);
	~Span(void);
	Span(const Span& span);
	Span&	operator=(const Span& span);

	int		shortestSpan(void) const;
	int		longestSpan(void) const;

	void	addNumber(int number);
	void	addNumbers(iterator begin, iterator end);
};
#endif /* SPAN_HPP */
