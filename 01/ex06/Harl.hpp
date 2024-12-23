/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:38:41 by aindjare          #+#    #+#             */
/*   Updated: 2024/12/23 15:30:48 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP
#include <string>

typedef enum {
	HARL_NONE = 0,
	HARL_DEBUG,
	HARL_INFO,
	HARL_WARNING,
	HARL_ERROR,
}	Harl_Level;

class Harl {
public:
	Harl();
	void	complain(std::string level, Harl_Level min);

private:
	void	info(void);
	void	debug(void);
	void	error(void);
	void	warning(void);

	Harl_Level	last_level;
	bool		first_print;
};
#endif
