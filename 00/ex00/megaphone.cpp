/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 18:58:19 by aindjare          #+#    #+#             */
/*   Updated: 2024/12/21 19:13:24 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int argc, const char **argv) {
	if (argc < 2) {
		argv[1] = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		argc++;
	}
	for (int i = 1; i < argc; i++) {
		std::string	str = argv[i];
		for (size_t j = 0; j < str.length(); j++)
			str[j] = std::toupper(str[j]);
		std::cout << str;
		if (i == argc - 1)
			std::cout << std::endl;
	}
	return (0);
}
