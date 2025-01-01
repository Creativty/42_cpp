/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 09:39:51 by aindjare          #+#    #+#             */
/*   Updated: 2025/01/01 10:35:06 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ScavTrap_hpp
#define ScavTrap_hpp
#include <string>
#include "ClapTrap.hpp"
class ScavTrap : public ClapTrap {
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& o);
	~ScavTrap();

	ScavTrap&	operator=(const ScavTrap& o);

	void		attack(const std::string& target);
	void		guardGate();
};
#endif

