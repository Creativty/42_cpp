/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 09:42:22 by aindjare          #+#    #+#             */
/*   Updated: 2025/07/08 15:31:52 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

enum Output {
	OUTPUT_SUCCESS,
	OUTPUT_BUREAUCRAT_HIGH,
	OUTPUT_BUREAUCRAT_LOW,
	OUTPUT_FORM_HIGH,
	OUTPUT_FORM_LOW,
};

enum Sign_Mode {
	SIGN_API_BUREAUCRAT = 0,
	SIGN_API_FORM = 1,
};

std::ostream&	operator<<(std::ostream& stream, const enum Output& output) {
	switch (output) {
	case OUTPUT_SUCCESS:
		return (stream << "Success");
	case OUTPUT_BUREAUCRAT_HIGH:
		return (stream << "Bureaucrat grade too high exception");
	case OUTPUT_BUREAUCRAT_LOW:
		return (stream << "Bureaucrat grade too low exception");
	case OUTPUT_FORM_HIGH:
		return (stream << "Form grade too high exception");
	case OUTPUT_FORM_LOW:
		return (stream << "Form grade too low exception");
	}
	return (stream);
}

void	test(Bureaucrat &bureaucrat, const std::string &name, unsigned int sign, unsigned int exec, enum Output output, enum Sign_Mode mode = SIGN_API_BUREAUCRAT) {
	enum Output	_output;
	try {
		Form	instance(name, sign, exec);

		if (mode == SIGN_API_FORM) instance.beSigned(bureaucrat);
		else bureaucrat.signForm(instance);

		std::cout << instance << std::endl;
		_output = OUTPUT_SUCCESS;
	} catch (std::exception& error) {
		std::cout << error.what() << std::endl;

		Bureaucrat::GradeTooHighException *bureau_high = dynamic_cast<Bureaucrat::GradeTooHighException*>(&error);
		Bureaucrat::GradeTooLowException *bureau_low = dynamic_cast<Bureaucrat::GradeTooLowException*>(&error);
		Form::GradeTooHighException *form_high = dynamic_cast<Form::GradeTooHighException*>(&error);
		Form::GradeTooLowException *form_low = dynamic_cast<Form::GradeTooLowException*>(&error);
		if (bureau_low != NULL)
			_output = OUTPUT_BUREAUCRAT_LOW;
		else if (bureau_high != NULL)
			_output = OUTPUT_BUREAUCRAT_HIGH;
		else if (form_low != NULL)
			_output = OUTPUT_FORM_LOW;
		else if (form_high != NULL)
			_output = OUTPUT_FORM_HIGH;
	}
	if (output != _output)
		std::cerr << "  \x1b[1;31mMISMATCH\x1b[0m: { (" << bureaucrat.getName() << ", " << bureaucrat.getGrade() << "), " << name << ", sign " << sign << ", exec " << exec << " }: Expecting " << output << ", got " << _output << "." << std::endl << std::endl;
	else
		std::cout << "  \x1b[1;32mMATCH\x1b[0m: { (" << bureaucrat.getName() << ", " << bureaucrat.getGrade() << "), " << name << ", sign " << sign << ", exec " << exec << " }: Outputs match as expected." << std::endl << std::endl;
}

int		main(void) {
	Bureaucrat	boss("Boss", 1);
	Bureaucrat	staff("Staff", 29);
	Bureaucrat	intern("Intern", 150);

	test(boss, "Wellness Session", 3, 1, OUTPUT_SUCCESS);
	test(boss, "Trip to Venus", 0, 0, OUTPUT_FORM_HIGH);
	test(staff, "Pizza Party", 10, 8, OUTPUT_FORM_LOW, SIGN_API_FORM);
	test(staff, "Pizza Party", 10, 8, OUTPUT_SUCCESS);

	test(intern, "(Paper that is definitely going into the bin)", 150, 150, OUTPUT_SUCCESS, SIGN_API_FORM);
	return (0);
}
