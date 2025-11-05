/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 10:13:55 by aindjare          #+#    #+#             */
/*   Updated: 2025/11/02 14:06:40 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include "Span.hpp"

int	main(void) {
	Span	span(5);

	try { /* No numbers in span */
		span.shortestSpan();
		span.longestSpan();
	} catch (const std::exception& err) {
		std::cerr << "Expected: Error: " << err.what() << std::endl;
	}

	span.addNumber(6);

	try { /* Only 1 number in span */
		span.shortestSpan();
		span.longestSpan();
	} catch (const std::exception& err) {
		std::cerr << "Expected: Error: " << err.what() << std::endl;
	}

	std::vector<int>	vec(4);
	vec[0] =  3;
	vec[1] = 17;
	vec[2] =  9;
	vec[3] = 11;

	span.addNumbers(vec.begin(), vec.end());
	try {
		int	longest = span.longestSpan();
		int	shortest = span.shortestSpan();

		std::cout << "Expected: Value " << 2  << ", Got " << shortest << std::endl;
		std::cout << "Expected: Value " << 14 << ", Got " << longest << std::endl;
	} catch (const std::exception& err) {
		std::cerr << "Unexpected: Error: " << err.what() << std::endl;
	}

	return (0);
}
