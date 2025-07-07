/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 10:17:32 by aindjare          #+#    #+#             */
/*   Updated: 2025/07/07 10:22:55 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, unsigned int grade) {
	if (grade < 1) throw Bureaucrat::GradeTooHighException();
	if (grade > 150) throw Bureaucrat::GradeTooLowException();
	this->name = name;
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& instance) {
	this->name = instance.getName();
	this->grade = instance.getGrade();
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& instance) {
	return ((void)instance, *this);
}

Bureaucrat::~Bureaucrat() { }

void Bureaucrat::demote(void) {
	if (this->grade + 1 > 150) throw Bureaucrat::GradeTooLowException();
	this->grade++;
}

void Bureaucrat::promote(void) {
	if (this->grade - 1 < 1) throw Bureaucrat::GradeTooHighException();
	this->grade--;
}

const std::string&	Bureaucrat::getName(void) const {
	return (this->name);
}

unsigned int	Bureaucrat::getGrade(void) const {
	return (this->grade);
}

const char	*Bureaucrat::GradeTooHighException::what() const throw() {
	return ("GradeTooHigh(Bureaucrat)");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw() {
	return ("GradeTooLow(Bureaucrat)");
}

std::ostream&	operator<<(std::ostream& stream, const Bureaucrat& instance) {
	return (stream << instance.getName() << ", bureaucrat grade " << instance.getGrade());
}
