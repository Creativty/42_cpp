/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 10:13:55 by aindjare          #+#    #+#             */
/*   Updated: 2025/11/01 10:25:04 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "iter.hpp"

#define count_of(ARRAY) (sizeof(ARRAY) / sizeof((ARRAY)[0]))

template <typename T>
void	print_list_element(const T& v) {
	std::cout << "  - " << v << std::endl;
}

void	mul_2(size_t& v) {
	v *= 2;
}

int	main(void) {
	std::string	arr_strings[] = { "abc", "def", "ghi", "jkl", "mno", "pqr", "stuv", "wxyz" };
	size_t		arr_numbers[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };

	::iter((int*)0, 3, print_list_element);

	std::cout << "Alphabet groups:" << std::endl;
	::iter(arr_strings, count_of(arr_strings), print_list_element);

	std::cout << "Prime numbers:" << std::endl;
	::iter(arr_numbers, count_of(arr_numbers), print_list_element);

	std::cout << "Prime numbers * 2:" << std::endl;
	::iter(arr_numbers, count_of(arr_numbers), mul_2);
	::iter(arr_numbers, count_of(arr_numbers), print_list_element);

	return 0;
}
