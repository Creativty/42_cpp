/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenobas <rahimos.123@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:34:13 by xenobas           #+#    #+#             */
/*   Updated: 2025/11/25 15:19:13 by xenobas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <vector>
#include <climits>
#include <cstdlib>
#include <iostream>

static std::vector<int>	parse_numbers(const char **strs, int strs_size) {
	std::vector<int>	numbers;

	numbers.reserve(strs_size);
	for (int i = 0; i < strs_size; ++i) {
		char*		end = NULL;
		const char* str = strs[i];

		long		num = std::strtol(str, &end, 10);
		if (end == NULL || *end != '\0') {
			continue ;
		}

		if (num > INT_MAX || num < INT_MIN) {
			continue ;
		}

		numbers.push_back(static_cast<int>(num));
	}
	return (numbers);
}

int						main(int argc, const char** argv) {
	std::vector<int>	numbers = parse_numbers(&argv[1], argc - 1);

	Span				span(numbers.size());
	span.addNumbers(numbers.begin(), numbers.end());

	for (int i = 0; i < span.capacity(); ++i) {
		if (i > 0) {
			std::cout << ", ";
		}
		std::cout << span[i];
	}
	std::cout << '\n';

	std::cout << "shortest span: " << span.shortestSpan() << '\n';
	std::cout << "longest  span: " <<  span.longestSpan() << '\n';
	return (0);
}
