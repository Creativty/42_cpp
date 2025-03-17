/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 09:07:58 by aindjare          #+#    #+#             */
/*   Updated: 2025/03/17 12:28:53 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("unnamed"), attack_damage(0), energy_points(10),
						hit_points(10) {
	std::cout << "ClapTrap :: constructor default" << std::endl;
}

ClapTrap::ClapTrap(std::string name):	name(name), attack_damage(0),
						energy_points(10), hit_points(10) {
	std::cout << "ClapTrap :: constructor name" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& o):	name(o.name),
										attack_damage(o.attack_damage),
										energy_points(o.energy_points),
										hit_points(o.hit_points) {
	std::cout << "ClapTrap :: constructor copy" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap :: destructor" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& o) {
	std::cout << "ClapTrap :: assignment copy" << std::endl;
	if (this != &o)
		*this = o;
	return (*this);
}

void	ClapTrap::attack(const std::string& target) {
	if (this->hit_points <= 0 || this->energy_points <= 0) return ;

	std::cout << "ClapTrap " << this->name
			  << " attacks " << target
			  << ", causing " << this->attack_damage
			  << " points of damage!" << std::endl;
	energy_points--;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->hit_points <= 0) return ;

	this->hit_points -= amount;
	std::cout << "ClapTrap " << this->name
			  << " took " << amount
			  << " points of damage!" << std::endl;
	if (this->hit_points <= 0) {
		std::cout << "ClapTrap " << this->name
				  << " has died!" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->hit_points <= 0 || this->energy_points <= 0) return ;

	std::cout << "ClapTrap " << this->name
			  << " has restored " << amount
			  << " hit points!"   << std::endl;
	energy_points--;
}
