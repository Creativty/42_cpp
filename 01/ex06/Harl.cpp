/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:13:08 by aindjare          #+#    #+#             */
/*   Updated: 2025/03/12 14:45:34 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl() { }

void	Harl::debug(void) {
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void) {
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void) {
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void) {
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level, Harl_Level min) {
	const int	N = 4;
	std::string log_levels_strings[N] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR",
	};
	for (int i = 1; i < N + 1; i++)
		if (log_levels_strings[i - 1] == level && i >= min) {
			switch (i) {
				case HARL_DEBUG:
					this->debug();
				break ;
				case HARL_INFO:
					this->info();
				break ;
				case HARL_WARNING:
					this->warning();
				break ;
				case HARL_ERROR:
					this->error();
				break ;
			}
		}
}	
