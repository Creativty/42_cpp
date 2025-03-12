/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 11:42:12 by aindjare          #+#    #+#             */
/*   Updated: 2025/03/12 13:55:17 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	Zombie	z_bill(std::string("Default"));
	z_bill.announce();

	randomChump(std::string("Chump"));

	Zombie	*z_heap = newZombie(std::string("Heap"));
	z_heap->announce();
	delete z_heap;
}
