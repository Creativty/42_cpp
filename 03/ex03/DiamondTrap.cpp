/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 11:20:04 by aindjare          #+#    #+#             */
/*   Updated: 2025/01/01 11:52:29 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(): ClapTrap("unnamed_clap_trap") {
	std::cout << "DiamondTrap :: constructor default" << std::endl;
	this->hit_points = FragTrap::hit_points;
	this->attack_damage = FragTrap::attack_damage;
	this->energy_points = ScavTrap::energy_points;
}
DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name") {
	std::cout << "DiamondTrap :: constructor name" << std::endl;
	this->name = name;
	this->hit_points = FragTrap::hit_points;
	this->attack_damage = FragTrap::attack_damage;
	this->energy_points = ScavTrap::energy_points;
}
DiamondTrap::DiamondTrap(const DiamondTrap& o) {
	std::cout << "DiamondTrap :: constructor copy" << std::endl;
	this->name = o.name;
	this->hit_points = o.hit_points;
	this->attack_damage = o.attack_damage;
	this->energy_points = o.energy_points;
}
DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap :: destructor" << std::endl;
}

void	DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}
void	DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap whoIs derived " <<           name << std::endl;
	std::cout << "DiamondTrap whoIs base    " << ClapTrap::name << std::endl;
}
