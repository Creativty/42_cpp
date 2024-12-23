/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:52:25 by aindjare          #+#    #+#             */
/*   Updated: 2024/12/23 14:08:53 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type): type(type) { }

std::string	Weapon::getType(void) {
	return (type);
}

void		Weapon::setType(std::string type) {
	this->type = type;
}
