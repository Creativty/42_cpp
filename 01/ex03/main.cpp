/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:30:35 by aindjare          #+#    #+#             */
/*   Updated: 2024/12/23 14:09:14 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main(void) {
	{
		Weapon	club = Weapon("crude club");

		HumanA	bob("Bob", club);
		bob.attack();
		club.setType("bloodied chipped club");
		bob.attack();
	}	
	{
		Weapon	club = Weapon("spiked club");

		HumanB	jim("Jim");
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType("broken club");
		jim.attack();
	}
	return (0);
}
