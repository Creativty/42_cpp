/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:42:58 by aindjare          #+#    #+#             */
/*   Updated: 2024/12/23 15:08:29 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

Harl::Harl() {
	first_print = true;
	last_level = HARL_NONE;
}

void	Harl::info(void) {
	if (first_print || last_level != HARL_INFO)
		std::cout << "[INFO]" << std::endl;
	last_level = HARL_INFO;
	first_print = false;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void	Harl::debug(void) {
	if (first_print || last_level != HARL_DEBUG)
		std::cout << "[DEBUG]" << std::endl;
	last_level = HARL_DEBUG;
	first_print = false;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n" << std::endl;
}

void	Harl::error(void) {
	if (first_print || last_level != HARL_ERROR)
		std::cout << "[ERROR]" << std::endl;
	last_level = HARL_ERROR;
	first_print = false;
	std::cout << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void	Harl::warning(void) {
	if (first_print || last_level != HARL_WARNING)
		std::cout << "[WARNING]" << std::endl;
	last_level = HARL_WARNING;
	first_print = false;
	std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming for years whereas you started working here since last month.\n" << std::endl;
}

void	Harl::complain(std::string level) {
	const int N = 4;
	const char	*allowed_levels[N] = {
		"INFO",
		"DEBUG",
		"ERROR",
		"WARNING",
	};
	void (Harl::*functions[N])(void) = {
		&Harl::info,
		&Harl::debug,
		&Harl::error,
		&Harl::warning,
	};

	for (int i = 0; i < N; i++)
		if (level == allowed_levels[i]) {
			(this->*functions[i])();

			break ;
		}
}	
