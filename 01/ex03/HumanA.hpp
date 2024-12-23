/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:32:33 by aindjare          #+#    #+#             */
/*   Updated: 2024/12/23 13:52:02 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP
#include <string>
#include "Weapon.hpp"

class HumanA {
public:
	HumanA(std::string name, Weapon &weapon);

	void			attack(void);
private:
	Weapon&		weapon;
	std::string	name;
};

#endif
