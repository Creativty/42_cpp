/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 16:13:04 by aindjare          #+#    #+#             */
/*   Updated: 2025/06/22 17:54:13 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "Form.hpp"
#include "Bureaucrat.hpp"

int	main(void) {
	Bureaucrat	bureaucrat("Jake", 23);
	std::cout << bureaucrat << std::endl;
	std::cout << std::endl;

	Form		w19("W19", 22, 21);
	std::cout << w19 << std::endl;
	bureaucrat.signForm(w19);
	bureaucrat.promoteGrade(); std::cout << "Jake has been promoted" << std::endl;
	bureaucrat.signForm(w19);
	std::cout << std::endl;

	Form		a1b1("A1B1", 140, 119);
	std::cout << a1b1 << std::endl;
	bureaucrat.signForm(a1b1);
	std::cout << a1b1 << std::endl;
	bureaucrat.signForm(a1b1);
	return (0);
}
