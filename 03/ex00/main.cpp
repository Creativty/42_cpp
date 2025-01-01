/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 09:18:34 by aindjare          #+#    #+#             */
/*   Updated: 2025/01/01 09:26:35 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void) {
	ClapTrap	alex("Alex");
	ClapTrap	unnamed;

	alex.attack("unnamed");
	unnamed.takeDamage(0);
	alex.attack("unnamed");
	unnamed.takeDamage(0);

	unnamed.takeDamage(9);
	unnamed.beRepaired(4);
	unnamed.takeDamage(10);
	return (0);
}
