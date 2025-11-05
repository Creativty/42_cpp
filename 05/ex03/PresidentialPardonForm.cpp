/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:53:31 by aindjare          #+#    #+#             */
/*   Updated: 2025/07/08 16:27:12 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("PresidentialPardon", 25, 5), target(target) { }

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& instance)
	: AForm("ShrubberyCreation", 25, 5), target(instance.getTarget()) { }

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& instance) {
	this->target = instance.getTarget();
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() { }

const std::string&	PresidentialPardonForm::getTarget(void) const {
	return (this->target);
}

void				PresidentialPardonForm::beExecuted(void) const {
	if (this->getTarget() == "")
		std::cout << "Zeophod Beeblebrox: I cannot accept such humiliation, a NO NAME asking for a PARDON. TO THE GALLOWS WITH YOU !" << std::endl;
	else
		std::cout << "Zeophod Beeblebrox: " << this->getTarget() << "... you have been pardoned, I better not see you again." << std::endl;
}
