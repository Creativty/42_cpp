/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 09:02:06 by aindjare          #+#    #+#             */
/*   Updated: 2025/03/17 12:31:23 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef   CLAPTRAP_HPP
#define   CLAPTRAP_HPP
#include <string>

class ClapTrap {
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& o);
	~ClapTrap();

	ClapTrap&	operator=(const ClapTrap& o);

	void		attack(const std::string& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
private:
	std::string	name;
	int			attack_damage;
	int			energy_points, hit_points;
};
#endif // CLAPTRAP_HPP
