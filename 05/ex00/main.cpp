/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 16:13:04 by aindjare          #+#    #+#             */
/*   Updated: 2025/06/22 17:24:48 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

void	test_case_constructor(std::string name, unsigned int grade, const char *validity) {
	try {
		std::cout << "Constructing	Bureaucrat { \"" << name << "\", " << grade << " }\t:: got ";
		Bureaucrat	instance(name, grade);
		std::cout << "valid " << instance;
	} catch (std::exception& e) {
		std::cout << "invalid (" << e.what() << ")";
	}
	std::cout << ", while expecting " << validity << std::endl;
}

void	test_case_operation(std::string name, unsigned int grade, const char *validity, bool is_increment) {
	try {
		Bureaucrat	instance(name, grade);

		if (is_increment)	std::cout << "Demoting  +1	";
		else				std::cout << "Promoting -1	";
		std::cout << "Bureaucrat { \"" << name << "\", " << grade << " }\t:: got ";

		if (is_increment)	instance.demoteGrade();
		else				instance.promoteGrade();
		std::cout << "valid " << instance;
	} catch (std::exception& e) {
		std::cout << "invalid (" << e.what() << ")";
	}
	std::cout << ", while expecting " << validity << std::endl;
}

int	main(void) {
	test_case_constructor("Jake", 1, "valid");
	test_case_operation("Jake", 1, "valid", true);
	test_case_operation("Jake", 2, "valid", false);
	test_case_operation("Jake", 1, "invalid (Grade too high)", false);
	std::cout << std::endl;

	test_case_constructor("John", 0, "invalid (Grade too high)");
	std::cout << std::endl;

	test_case_constructor("Jane", 149, "valid");
	test_case_operation("Jane", 149, "valid", true);
	std::cout << std::endl;

	test_case_constructor("Johnson", 150, "valid");
	test_case_operation("Johnson", 150, "invalid (Grade too low)", true);
	std::cout << std::endl;

	test_case_constructor("Jenny", 200, "invalid (Grade too low)");
	std::cout << std::endl;

	Bureaucrat	a("Joe", 23);

	Bureaucrat	b(a);
	b.demoteGrade();

	Bureaucrat	c = a;
	c.promoteGrade();

	std::cout << "Bureaucrat a = " << a << std::endl;
	std::cout << "Bureaucrat b = " << b << std::endl;
	std::cout << "Bureaucrat c = " << c << std::endl;

	return (0);
}
