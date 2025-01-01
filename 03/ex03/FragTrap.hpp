/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 10:49:28 by aindjare          #+#    #+#             */
/*   Updated: 2025/01/01 11:47:32 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FragTrap_hpp
#define FragTrap_hpp
#include <string>
#include "ClapTrap.hpp"
class FragTrap : virtual public ClapTrap {
public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(const FragTrap& o);
	~FragTrap();

	FragTrap&	operator=(const FragTrap& o);

	void		attack(const std::string& target);
	void		highFivesGuys(void);
};
#endif

