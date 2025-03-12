/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:38:41 by aindjare          #+#    #+#             */
/*   Updated: 2025/03/12 14:29:28 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP
#include <string>

class Harl {
public:
	Harl();
	void	complain(std::string level);

private:
	void	info(void);
	void	debug(void);
	void	error(void);
	void	warning(void);
};
#endif
