/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 09:07:58 by aindjare          #+#    #+#             */
/*   Updated: 2025/01/01 10:39:21 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("unnamed"), attack_damage(20), energy_points(50),
						hit_points(100) {
	std::cout << "ClapTrap :: constructor default" << std::endl;
}
ClapTrap::ClapTrap(std::string name):	name(name), attack_damage(20),
						energy_points(50), hit_points(100) {
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
	this->name = o.name;
	this->hit_points = o.hit_points;
	this->energy_points = o.energy_points;
	this->attack_damage = o.attack_damage;
	return (*this);
}

void	ClapTrap::attack(const std::string& target) {
	if (this->energy_points > 0) {
		std::cout << "ClapTrap " << name;
		std::cout << " attacks " << target;
		std::cout << ", causing " << attack_damage;
		std::cout << " points of damage!" << std::endl;
		energy_points--;
	} else {
		std::cout << "ClapTrap " << name;
		std::cout << " attempts an attack on " << target;
		std::cout << ", but misses!" << std::endl;;
	}
}
void	ClapTrap::takeDamage(unsigned int amount) {
	if (this->hit_points > 0) {
		this->hit_points -= amount;
		std::cout << name;
		std::cout << " took " << amount;
		std::cout << " points of damage!" << std::endl;
		if (this->hit_points <= 0) {
			std::cout << name;
			std::cout << " has died!" << std::endl;
		}
	}
}
void	ClapTrap::beRepaired(unsigned int amount) {
	if (this->energy_points > 0) {
		std::cout << name;
		std::cout << " has restored " << amount;
		std::cout << " hit points!"   << std::endl;
		energy_points--;
	} else {
		std::cout << name;
		std::cout << " attempts to restore health, but is too tired!" << std::endl;
	}
}
