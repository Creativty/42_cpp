/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 09:38:02 by aindjare          #+#    #+#             */
/*   Updated: 2025/01/01 10:41:04 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <typeinfo>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap() {
	std::cout << "ScavTrap :: constructor default" << std::endl;
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
}
ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
	std::cout << "ScavTrap :: constructor name" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap& o): ClapTrap(o) {
	std::cout << "ScavTrap :: constructor copy" << std::endl;
}
ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap :: destructor" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& o) {
	name = o.name;
	hit_points = o.hit_points;
	energy_points = o.energy_points;
	attack_damage = o.attack_damage;
	return (*this);
}
void	ScavTrap::attack(const std::string& target) {
	if (this->energy_points > 0) {
		std::cout << "ScavTrap " << name;
		std::cout << " attacks " << target;
		std::cout << ", causing " << attack_damage;
		std::cout << " points of damage!" << std::endl;
		energy_points--;
	} else {
		std::cout << "ScavTrap " << name;
		std::cout << " attempts an attack on " << target;
		std::cout << ", but misses!" << std::endl;;
	}
}
void	ScavTrap::guardGate() {
	std::cout << "ScavTrap " << name; 
	std::cout << " is now in guard keeper duty!" << std::endl; 
}
