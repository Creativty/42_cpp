/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 11:42:12 by aindjare          #+#    #+#             */
/*   Updated: 2024/12/23 11:54:47 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	Zombie	z_unknown;
	z_unknown.announce();

	Zombie	z_bill(std::string("Bill"));
	z_bill.announce();

	randomChump(std::string("Alex"));

	Zombie	*z_heap = newZombie(std::string("Tommy"));
	z_heap->announce();
	delete z_heap;
}
