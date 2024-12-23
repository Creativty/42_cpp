/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:46:58 by aindjare          #+#    #+#             */
/*   Updated: 2024/12/23 14:07:45 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(std::string name): weapon(NULL), name(name) {};

HumanB::HumanB(std::string name, Weapon &weapon): weapon(&weapon), name(name) { }

void	HumanB::attack(void) {
	if (weapon == NULL)
		std::cout << name << " attempts to attack, yet he has no weapon ?!?" << std::endl;
	else
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon) {
	this->weapon = &weapon;
}

