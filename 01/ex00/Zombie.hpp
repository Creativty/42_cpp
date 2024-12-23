/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 11:42:29 by aindjare          #+#    #+#             */
/*   Updated: 2024/12/23 12:08:02 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <string>

class Zombie {
public:
	Zombie();
	Zombie(std::string name);
	~Zombie();

	void	announce(void);
private:
	std::string	name;
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);
#endif
