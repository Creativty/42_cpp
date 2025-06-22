/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 16:13:04 by aindjare          #+#    #+#             */
/*   Updated: 2025/06/22 16:48:29 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

void	test_case_constructor(std::string name, unsigned int grade, const char *validity) {
	try {

		// return (stream << "Bureacrat { " << instance.getName() << ", " << instance.getGrade() << " }");
		std::cout << "Constructing		Bureaucrat { \"" << name << "\", " << grade << " }\t:: got ";
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

		if (is_increment)	std::cout << "Incrementing (+1)	";
		else				std::cout << "Decrementing (-1)	";
		std::cout << "Bureaucrat { \"" << name << "\", " << grade << " }\t:: got ";

		if (is_increment)	instance.incrementGrade();
		else				instance.decrementGrade();
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
	test_case_operation("Johnson", 150, "invalid", true);
	std::cout << std::endl;

	test_case_constructor("Jenny", 200, "invalid (Grade too low)");
	std::cout << std::endl;

	return (0);
}
