/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:49:34 by aindjare          #+#    #+#             */
/*   Updated: 2025/07/08 16:58:57 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() { }

Intern::Intern(const Intern& instance) { (void)instance; }

Intern&	Intern::operator=(const Intern& instance) { return ((void)instance, *this); }

Intern::~Intern() { }

AForm*	Intern::makeForm(const std::string& name, const std::string& target) {
	enum Form {
		FORM_SHRUBBERY = 0,
		FORM_ROBOTOMY = 1,
		FORM_PARDON = 2,
		FORM_UNKNOWN = 3,
	};
	const std::string	NAMES[3] = { "ShrubberyCreation", "RobotomyRequest", "PresidentialPardon" };

	int					index = 0;
	while (index < FORM_UNKNOWN && NAMES[index] != name)
		index++;

	switch (index) {
		case FORM_SHRUBBERY:
			return (new ShrubberyCreationForm(target));
		case FORM_ROBOTOMY:
			return (new RobotomyRequestForm(target));
		case FORM_PARDON:
			return (new PresidentialPardonForm(target));
		default:
			return (NULL);
	}
}
