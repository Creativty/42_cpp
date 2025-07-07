/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 09:42:22 by aindjare          #+#    #+#             */
/*   Updated: 2025/07/07 10:37:07 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

enum Output {
	OUTPUT_SUCCESS,
	OUTPUT_GRADE_HIGH,
	OUTPUT_GRADE_LOW,
};

std::ostream&	operator<<(std::ostream& stream, const enum Output& output) {
	switch (output) {
	case OUTPUT_SUCCESS:
		return (stream << "success");
	case OUTPUT_GRADE_HIGH:
		return (stream << "grade too high exception");
	case OUTPUT_GRADE_LOW:
		return (stream << "grade too low exception");
	}
	return (stream);
}

void	test(const std::string &name, unsigned int grade, enum Output output = OUTPUT_SUCCESS, int delta = 0) {
	enum Output	_output;
	try {
		Bureaucrat	instance(name, grade);

		_output = OUTPUT_SUCCESS;
		while (delta < 0) {
			instance.demote();
			delta++;
		}
		while (delta > 0) {
			instance.promote();
			delta--;
		}
		std::cout << instance << std::endl;
	} catch (std::exception& error) {
		std::cout << error.what() << std::endl;

		Bureaucrat::GradeTooHighException *high = dynamic_cast<Bureaucrat::GradeTooHighException*>(&error);
		Bureaucrat::GradeTooLowException *low = dynamic_cast<Bureaucrat::GradeTooLowException*>(&error);
		if (low != NULL)
			_output = OUTPUT_GRADE_LOW;
		if (high != NULL)
			_output = OUTPUT_GRADE_HIGH;
	}
	if (output != _output)
		std::cerr << "Test case failed: Expecting " << output << ", got " << _output << std::endl;
}

int		main(void) {
	test("Boss", 1);
	test("Oligarchy", 0, OUTPUT_GRADE_HIGH);
	test("Boss to Oligarchy", 1, OUTPUT_GRADE_HIGH, 1);
	test("Intern", 150);
	test("Joe (Guy outside)", 160, OUTPUT_GRADE_LOW);
	test("Intern to Jobless", 149, OUTPUT_GRADE_LOW, -3);
	test("James (Staff)", 19);
	return (0);
}
