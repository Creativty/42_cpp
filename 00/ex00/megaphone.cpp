/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:58:19 by aindjare          #+#    #+#             */
/*   Updated: 2025/03/07 15:04:58 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(int argc, const char **argv) {
	if (argc < 2) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	for (int i = 1; i < argc; i++) {
		std::string	arg = argv[i];
		for (size_t j = 0; j < arg.length(); j++)
			arg[j] = std::toupper(arg[j]);

		std::cout << arg;
		if (i == argc - 1)
			std::cout << std::endl;
	}
	return (0);
}
