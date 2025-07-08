/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 10:57:32 by aindjare          #+#    #+#             */
/*   Updated: 2025/07/07 13:59:00 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string& name, unsigned int grade_sign, unsigned int grade_exec)
	: name(name),
	grade_sign(grade_sign), grade_exec(grade_exec), is_signed(false) {
	if (grade_sign < 1   || grade_exec < 1) throw Form::GradeTooHighException();
	if (grade_sign > 150 || grade_exec > 150) throw Form::GradeTooLowException();
}

Form::Form(const Form& instance)
	: name(instance.getName()),
	grade_sign(instance.getGradeSign()), grade_exec(instance.getGradeExec()), is_signed(false) { }

Form::~Form() { }

Form&	Form::operator=(const Form& instance) {
	return ((void)instance, *this);
}

const std::string&	Form::getName(void) const {
	return (this->name);
}

bool				Form::getIsSigned(void) const {
	return (this->is_signed);
}

unsigned int		Form::getGradeSign(void) const {
	return (this->grade_sign);
}

unsigned int		Form::getGradeExec(void) const {
	return (this->grade_exec);
}

void				Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->getGradeSign())
		throw Form::GradeTooLowException();
	this->is_signed = true;
}

const char	*Form::GradeTooHighException::what() const throw() {
	return ("GradeTooHigh(Form)");
}

const char	*Form::GradeTooLowException::what() const throw() {
	return ("GradeTooLow(Form)");
}

std::ostream&	operator<<(std::ostream& stream, const Form& instance) {
	return (stream << instance.getName() << ", form requires grade " << instance.getGradeSign() << " to sign, and " << instance.getGradeExec() << " to execute, and is" << (instance.getIsSigned() ? " signed" : " unsigned"));
}
