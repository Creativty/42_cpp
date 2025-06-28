/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 17:03:27 by aindjare          #+#    #+#             */
/*   Updated: 2025/06/28 15:36:02 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>

void				Form::checkGrades(void) const {
	if (this->getGradeSign() > 150) throw Form::GradeTooLowException();
	if (this->getGradeExec() > 150) throw Form::GradeTooLowException();
	if (this->getGradeSign() <   1) throw Form::GradeTooHighException();
	if (this->getGradeExec() <   1) throw Form::GradeTooHighException();
}

void				Form::beSigned(const Bureaucrat& instance) {
	if (this->is_signed) throw Form::AlreadySignedException();
	if (this->getGradeSign() < instance.getGrade()) throw Form::GradeTooLowException();
	this->is_signed = true;
}

const std::string&	Form::getName(void) const { return (this->name); }
bool				Form::getIsSigned(void) const { return (this->is_signed); }
unsigned int		Form::getGradeExec(void) const { return (this->grade_exec); }
unsigned int		Form::getGradeSign(void) const { return (this->grade_sign); }

Form&	Form::operator=(const Form& instance) {
	this->is_signed = instance.getIsSigned();
	return (*this);
}

Form::Form(const std::string& name, unsigned int grade_sign, unsigned int grade_exec)
	: name(name), is_signed(false), grade_exec(grade_exec), grade_sign(grade_sign) { this->checkGrades(); }

Form::Form(const Form& instance)
	: name(instance.getName()), is_signed(false), grade_exec(instance.getGradeExec()), grade_sign(instance.getGradeSign()) { }

Form::~Form() { }

const char *Form::GradeTooHighException::what() const throw() {
	return ("Grade too high");
};

const char *Form::GradeTooLowException::what() const throw() {
	return ("Grade too low");
};

const char *Form::AlreadySignedException::what() const throw() {
	return ("Already signed");
};

std::ostream&	operator<<(std::ostream& stream, const Form& instance) {
	stream << "Form { \"" << instance.getName() << "\", sign " << instance.getGradeSign();
	stream << ", exec " << instance.getGradeExec();
	stream << ", " << (instance.getIsSigned() ? "is signed" : "is still unsigned");
	stream << " }";
	return (stream);
}
