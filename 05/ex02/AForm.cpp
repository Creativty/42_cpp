/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 10:57:32 by aindjare          #+#    #+#             */
/*   Updated: 2025/07/08 16:00:12 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string& name, unsigned int grade_sign, unsigned int grade_exec)
	: name(name),
	grade_sign(grade_sign), grade_exec(grade_exec), is_signed(false) {
	if (grade_sign < 1   || grade_exec < 1) throw AForm::GradeTooHighException();
	if (grade_sign > 150 || grade_exec > 150) throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& instance)
	: name(instance.getName()),
	grade_sign(instance.getGradeSign()), grade_exec(instance.getGradeExec()), is_signed(false) { }

AForm::~AForm() { }

AForm&	AForm::operator=(const AForm& instance) {
	return ((void)instance, *this);
}

const std::string&	AForm::getName(void) const {
	return (this->name);
}

bool				AForm::getIsSigned(void) const {
	return (this->is_signed);
}

unsigned int		AForm::getGradeSign(void) const {
	return (this->grade_sign);
}

unsigned int		AForm::getGradeExec(void) const {
	return (this->grade_exec);
}

void				AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->getGradeSign())
		throw AForm::GradeTooLowException();
	this->is_signed = true;
}

void				AForm::execute(Bureaucrat const& executor) const {
	if (executor.getGrade() > this->getGradeExec())
		throw AForm::GradeTooLowException();
	this->beExecuted();
}

const char	*AForm::GradeTooHighException::what() const throw() {
	return ("GradeTooHigh(AForm)");
}

const char	*AForm::GradeTooLowException::what() const throw() {
	return ("GradeTooLow(AForm)");
}

std::ostream&	operator<<(std::ostream& stream, const AForm& instance) {
	return (stream << instance.getName() << ", form requires grade " << instance.getGradeSign() << " to sign, and " << instance.getGradeExec() << " to execute, and is" << (instance.getIsSigned() ? " signed" : " unsigned"));
}
