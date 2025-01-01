/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 09:50:59 by aindjare          #+#    #+#             */
/*   Updated: 2025/01/01 10:57:03 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void) {
	ClapTrap	clap("ravioli");
	ScavTrap	scav("pepperoni");
	FragTrap	frag("risotto");

	clap.attack("pepperoni");
	scav.takeDamage(20);

	scav.guardGate();

	for (int i = 0; i < 3; i++) {
		clap.attack("pepperoni");
		scav.takeDamage(20);
	}

	frag.highFivesGuys();
	return (0);
}
