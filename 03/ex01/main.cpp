/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 09:50:59 by aindjare          #+#    #+#             */
/*   Updated: 2025/01/01 10:41:50 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void) {
	ClapTrap	clap("ravioli");
	ScavTrap	scav("pepperoni");

	clap.attack("pepperoni");
	scav.takeDamage(20);

	scav.guardGate();

	for (int i = 0; i < 5; i++) {
		scav.attack("ravioli");
		clap.takeDamage(20);
	}
	return (0);
}
