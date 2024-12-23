/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:43:14 by aindjare          #+#    #+#             */
/*   Updated: 2024/12/23 14:04:54 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP
#include <string>
#include "Weapon.hpp"

class HumanB {
public:
	HumanB(std::string name);
	HumanB(std::string name, Weapon &weapon);

	void			attack(void);
	void			setWeapon(Weapon& weapon);
private:
	bool		is_armed;
	Weapon*		weapon;
	std::string	name;
};

#endif
