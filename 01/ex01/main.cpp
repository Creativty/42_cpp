/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:00:48 by aindjare          #+#    #+#             */
/*   Updated: 2025/03/12 13:59:00 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {
	#define N 10
	Zombie	*horde = zombieHorde(N, std::string("Gillian"));
	for (int i = 0; i < N; i++)
		horde[i].announce();
	delete[] horde;
}
