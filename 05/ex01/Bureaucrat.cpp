/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 16:14:30 by aindjare          #+#    #+#             */
/*   Updated: 2025/06/28 15:35:56 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

unsigned int		Bureaucrat::getGrade(void) const {
	return (this->grade);
}

const std::string&	Bureaucrat::getName(void) const {
	return (this->name);
}

void				Bureaucrat::checkGrade(int delta = 0) const {
	if ((int)this->grade + delta > 150) throw Bureaucrat::GradeTooLowException();
	if ((int)this->grade + delta <   1) throw Bureaucrat::GradeTooHighException();
}

void				Bureaucrat::promoteGrade(void) {
	this->checkGrade(-1);
	this->grade--;
}

void				Bureaucrat::demoteGrade(void) {
	this->checkGrade(+1);
	this->grade++;
}

void				Bureaucrat::signForm(Form& instance) const {
	try {
		instance.beSigned(*this);
		std::cout << this->getName() << " signed " << instance.getName() << std::endl;
	} catch (std::exception& e) {
		std::cout << this->getName() << " couldn't sign " << instance.getName() << " because " << e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat(const std::string& name, unsigned int grade): name(name), grade(grade) { this->checkGrade(); }

Bureaucrat::Bureaucrat(const Bureaucrat& instance): name(instance.getName()), grade(instance.getGrade()) { }

Bureaucrat::~Bureaucrat() { }

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& instance) {
	this->grade = instance.getGrade();
	return (*this);
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade too high");
};

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade too low");
};

std::ostream&	operator<<(std::ostream& stream, const Bureaucrat& instance) {
	return (stream << "Bureaucrat { \"" << instance.getName() << "\", " << instance.getGrade() << " }");
}
