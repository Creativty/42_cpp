/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:38:41 by aindjare          #+#    #+#             */
/*   Updated: 2025/03/12 14:41:08 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP
#include <string>

typedef enum {
	HARL_NONE = 0,
	HARL_DEBUG = 1,
	HARL_INFO = 2,
	HARL_WARNING = 3,
	HARL_ERROR = 4,
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
};
#endif
