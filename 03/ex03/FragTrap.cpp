/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 10:50:37 by aindjare          #+#    #+#             */
/*   Updated: 2025/01/01 11:05:21 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap() {
	std::cout << "FragTrap :: constructor default" << std::endl;
}
FragTrap::FragTrap(std::string name): ClapTrap(name) {
	std::cout << "FragTrap :: constructor name" << std::endl;
}
FragTrap::FragTrap(const FragTrap& o): ClapTrap(o) {
	std::cout << "FragTrap :: constructor copy" << std::endl;
}
FragTrap::~FragTrap() {
	std::cout << "FragTrap :: destructor" << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& o) {
	name = o.name;
	hit_points = o.hit_points;
	energy_points = o.energy_points;
	attack_damage = o.attack_damage;
	return (*this);
}
void	FragTrap::attack(const std::string& target) {
	if (this->energy_points > 0) {
		std::cout << "FragTrap " << name;
		std::cout << " attacks " << target;
		std::cout << ", causing " << attack_damage;
		std::cout << " points of damage!" << std::endl;
		energy_points--;
	} else {
		std::cout << "FragTrap " << name;
		std::cout << " attempts an attack on " << target;
		std::cout << ", but misses!" << std::endl;;
	}
}
void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name; 
	std::cout << " asks politely if everyone can high five?" << std::endl; 
}

