/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:37:49 by aindjare          #+#    #+#             */
/*   Updated: 2024/12/23 15:06:20 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "Harl.hpp"

int	main(void) {
	Harl	harl;

	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("DEBUG");
	harl.complain("WARNING");
	harl.complain("WARNING");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("DEBUG");
	harl.complain("ERROR");
	return (0);
}
