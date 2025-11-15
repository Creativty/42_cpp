/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenobas <rahimos.123@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:03:58 by xenobas           #+#    #+#             */
/*   Updated: 2025/11/15 11:36:50 by xenobas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <iostream>

#define RET_OK 0
#define RET_FAIL 1

int		main(int argc, char **argv) {
	if (argc < 2) {
		std::cerr << "error: please pass a literal or more to convert" << std::endl;
		std::cerr << "usage:" << std::endl;
		std::cerr << "\t" << argv[0] << " <literal...>" << std::endl;
		return (RET_FAIL);
	}
	for (int i = 1; i < argc; ++i) {
		if (i > 1) {
			std::cout << std::endl;
		}
		ScalarConverter::convert(argv[i]);
	}
	return (RET_OK);
}
