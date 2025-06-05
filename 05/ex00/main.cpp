/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:59:20 by aindjare          #+#    #+#             */
/*   Updated: 2025/06/05 16:41:05 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int	main(void) {
	try {
		Bureaucrat	too_high("CEO", 0);
	} catch (std::exception& e) {
		std::cerr << "[EXCEPTION] Expecting 'too high': " << e.what() << std::endl;
	}

	try {
		Bureaucrat	too_low("Intern", 230);
	} catch (std::exception& e) {
		std::cerr << "[EXCEPTION] Expecting 'too low':  " << e.what() << std::endl;
	}

	try {
		Bureaucrat	julian("Middle Management", 3);
		std::cout << "[INFO]      " << julian << std::endl;
	} catch (std::exception& e) {
		std::cerr << "[EXCEPTION] Unexpected, if this appears something is wrong: " << e.what() << std::endl;
	}
	return (0);
}
