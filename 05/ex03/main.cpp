/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 09:42:22 by aindjare          #+#    #+#             */
/*   Updated: 2025/07/08 17:04:32 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <string>
#include <cstdlib>
#include <iostream>
#include "Intern.hpp"
#define nullptr NULL
#define ITERATIONS 5

int		main(void) {
	srand((unsigned int)time(nullptr));

	const std::string	NAMES[] = {
		"ShrubberyCreation",
		"RobotomyRequest",
		"PresidentialPardon",
		"Unknown",
	};
	const unsigned long NAMES_COUNT = sizeof(NAMES) / sizeof(NAMES[0]);
	const std::string	TARGETS[] = {
		"Ahmed",
		"Dumbass",
	};
	const unsigned long TARGETS_COUNT = sizeof(TARGETS) / sizeof(TARGETS[0]);

	Intern	intern;

	for (int i = 0; i < ITERATIONS; i++) {
		const std::string&	name   = NAMES[rand() % (int)NAMES_COUNT];
		const std::string&	target = TARGETS[rand() % (int)TARGETS_COUNT];

		AForm*	form = intern.makeForm(name, target);
		if (form == NULL)
			std::cout << name << " has gotten us a (AForm*)NULL." << std::endl;
		else
			std::cout << *form << std::endl;
	}
	return (0);
}
