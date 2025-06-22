/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 16:14:30 by aindjare          #+#    #+#             */
/*   Updated: 2025/06/22 16:45:15 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

unsigned int		Bureaucrat::getGrade(void) const {
	return (this->grade);
}

const std::string&	Bureaucrat::getName(void) const {
	return (this->name);
}

void				Bureaucrat::checkGrade(int delta = 0) {
	if ((int)this->grade + delta > 150) throw Bureaucrat::GradeTooLowException();
	if ((int)this->grade + delta <   1) throw Bureaucrat::GradeTooHighException();
}

void				Bureaucrat::incrementGrade(void) {
	this->checkGrade(+1);
	this->grade++;
}

void				Bureaucrat::decrementGrade(void) {
	this->checkGrade(-1);
	this->grade--;
}


Bureaucrat::Bureaucrat(const std::string& name, unsigned int grade): name(name), grade(grade) { this->checkGrade(); }

Bureaucrat::Bureaucrat(const Bureaucrat& instance): name(instance.getName()), grade(instance.getGrade()) { }

Bureaucrat::~Bureaucrat() { }

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade too high");
};

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade too high");
};

std::ostream&	operator<<(std::ostream& stream, const Bureaucrat& instance) {
	return (stream << "Bureacrat { \"" << instance.getName() << "\", " << instance.getGrade() << " }");
}
