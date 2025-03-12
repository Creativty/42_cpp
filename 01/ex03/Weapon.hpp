/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:30:43 by aindjare          #+#    #+#             */
/*   Updated: 2025/03/12 14:12:46 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <string>

class Weapon {
public:
	Weapon(std::string type);

	const std::string&	getType(void);
	void				setType(std::string type);
private:
	std::string	type;
};

#endif
