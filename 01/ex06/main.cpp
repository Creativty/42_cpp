/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:09:20 by aindjare          #+#    #+#             */
/*   Updated: 2025/03/12 14:44:27 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	main(const int argc, const char **argv) {
	Harl	harl;

	if (argc != 2) {
		std::cout << argv[0] << " is a level based filter for loggers like harl" << std::endl;
		std::cout << "Usage:" << std::endl;
		std::cout << "\t" << argv[0] << " <minimum_level>" << std::endl;
		std::cout << "Levels:" << std::endl;
		std::cout << "\t- " << "DEBUG" << std::endl;
		std::cout << "\t- " << "INFO" << std::endl;
		std::cout << "\t- " << "WARNING" << std::endl;
		std::cout << "\t- " << "ERROR" << std::endl;
		return (1);
	} else {
		const int N = 4;
		Harl_Level	log_level = HARL_NONE;
		Harl_Level	log_levels[N] = { HARL_DEBUG, HARL_INFO, HARL_WARNING, HARL_ERROR };
		std::string	log_strings[N] = { "DEBUG", "INFO", "WARNING", "ERROR" };
		for (int i = 0; i < N; i++) {
			if (log_strings[i] == argv[1]) {
				log_level = log_levels[i];
				break ;
			}
		}
		if (log_level == HARL_NONE) {
			std::cout << "Error: invalid log level" << std::endl;
			return (2);
		}
		harl.complain("INFO", log_level);
		harl.complain("WARNING", log_level);
		harl.complain("ERROR", log_level);
		harl.complain("DEBUG", log_level);
		harl.complain("WARNING", log_level);
		harl.complain("WARNING", log_level);
		harl.complain("INFO", log_level);
		harl.complain("WARNING", log_level);
		harl.complain("DEBUG", log_level);
		harl.complain("ERROR", log_level);
	}
	return (0);
}
