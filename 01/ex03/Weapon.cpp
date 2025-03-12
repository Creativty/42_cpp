/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:52:25 by aindjare          #+#    #+#             */
/*   Updated: 2025/03/12 14:12:33 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type): type(type) { }

const std::string&	Weapon::getType(void) {
	return (this->type);
}

void		Weapon::setType(std::string type) {
	this->type = type;
}
