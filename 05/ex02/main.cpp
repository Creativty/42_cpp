/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 09:42:22 by aindjare          #+#    #+#             */
/*   Updated: 2025/07/08 16:33:47 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <string>
#include <cstdlib>
#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#define nullptr NULL

int		main(void) {
	srand((unsigned int)time(nullptr));

	Bureaucrat	boss("Boss", 1);
	Bureaucrat	staff("Staff", 29);
	Bureaucrat	intern("Intern", 150);

	{
		ShrubberyCreationForm	form("h1b1");
		intern.signForm(form);
		staff.signForm(form);

		staff.executeForm(form);
		intern.executeForm(form);
	}

	{
		ShrubberyCreationForm	form("");
		boss.executeForm(form);
	}

	{
		RobotomyRequestForm	form("xenobas");
		intern.signForm(form);
		staff.signForm(form);
		boss.signForm(form);

		boss.executeForm(form);
		staff.executeForm(form);
		intern.executeForm(form);
	}

	{
		RobotomyRequestForm	form("");
		boss.executeForm(form);
	}

	{
		PresidentialPardonForm	form("xenobas");
		intern.signForm(form);
		staff.signForm(form);
		boss.signForm(form);

		boss.executeForm(form);
		staff.executeForm(form);
		intern.executeForm(form);
	}

	{
		PresidentialPardonForm	form("");
		boss.executeForm(form);
	}
	return (0);
}
