/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 10:13:55 by aindjare          #+#    #+#             */
/*   Updated: 2025/11/17 13:33:37 by xenobas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <exception>
#include "easyfind.hpp"

int	main(int argc, const char** argv) {
	std::vector<int>	vec;

	if (argc != 2) {
		std::cerr << "usage: " << argv[0] << " <lottery_number>" << std::endl;
		return (2);
	}

	std::srand((unsigned int)std::time(0));
	vec.resize(10);
	std::cout << "Raffle: " << std::endl;
	for (size_t i = 0; i < 10; ++i) {
		int	value = std::rand() % 10;
		std::cout << value;
		if (i + 1 == 10) {
			std::cout << std::endl;
		} else {
			std::cout << ", ";
		}
		vec.push_back(value);
	}
	try {
		int	v = std::atoi(argv[1]);
		::easyfind(vec, v);
		
		std::cout << "What a shame... You lost the lottery, as the raffle did contain `" << argv[1] << "`" << std::endl;
	} catch (const std::exception& err) {
		std::cout << "Your number is uniquely not in the raffle... You've won the lottery, You also get no prize!" << std::endl;
	}
	return (0);
}
