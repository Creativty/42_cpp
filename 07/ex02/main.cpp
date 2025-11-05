/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 10:13:55 by aindjare          #+#    #+#             */
/*   Updated: 2025/11/01 10:46:55 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "Array.hpp"

int	main(void) {
	Array<int>			arr_0;
	Array<int>			arr_1(69u);
	Array<int>			arr_2(arr_1);
	const Array<int>	arr_3 = arr_2;

	try {
		arr_1[42] = 42;
		std::cout << "arr_1[42] = " << arr_1[42] << std::endl;

		std::cout << "arr_3.size() == " << arr_3.size() << std::endl;

		arr_2[69] = 1; /* Throws */
		std::cout << arr_2[69] << std::endl; /* Unreachable */
		return (1);
	} catch (const std::exception& err) {
		std::cerr << "Caught Exception: " << err.what() << std::endl;
	}
	return 0;
}
