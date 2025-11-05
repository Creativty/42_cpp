/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:53:31 by aindjare          #+#    #+#             */
/*   Updated: 2025/07/08 16:34:06 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequest", 72, 45), target(target) {
	if (this->target.empty())
		this->target = "unnamed";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& instance)
	: AForm("RobotomyRequest", 72, 45), target(instance.getTarget()) { }

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& instance) {
	this->target = instance.getTarget();
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() { }

const std::string&	RobotomyRequestForm::getTarget(void) const {
	return (this->target);
}

void				RobotomyRequestForm::beExecuted(void) const {
	std::cout << "Verrrrrrrrt, YORORORORORO..." << std::endl;
	bool	has_been_robotomized = !!(rand() % 2);
	if (has_been_robotomized) {
		std::cout << "\t" << this->getTarget() << " has been robotomized successfully." << std::endl;
	} else {
		std::cout << "\t" << this->getTarget() << " has lost too much blood and died during the robotomization process." << std::endl;
		if (this->getTarget() == "unnamed")
			std::cout << "\tgood thing we just picked him off the street for research." << std::endl;
	}
}
