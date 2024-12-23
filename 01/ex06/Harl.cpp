/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:13:08 by aindjare          #+#    #+#             */
/*   Updated: 2024/12/23 15:31:35 by aindjare         ###   ########.fr       */
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

void	Harl::complain(std::string level, Harl_Level min) {
	int			i;
	const int	N = 4;
	const char	*log_levels_strings[N] = {
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR",
	};
	for (i = min - 1; i < N; i++)
		if (level == log_levels_strings[i])
			break ;
	if (i == N)
		return ;
	switch (i) {
		case 0:
			this->debug();
		break ;
		case 1:
			this->info();
		break ;
		case 2:
			this->warning();
		break ;
		case 3:
			this->error();
		break ;
		default:
			std::cout << "error: unreachable piece of code" << std::endl;
	}
}	
