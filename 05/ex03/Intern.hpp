/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:46:38 by aindjare          #+#    #+#             */
/*   Updated: 2025/07/08 16:48:39 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef   Intern_HPP
#define   Intern_HPP
#include  "AForm.hpp"
#include  "ShrubberyCreationForm.hpp"
#include  "PresidentialPardonForm.hpp"
#include  "RobotomyRequestForm.hpp"
#include  <string>

class AForm;
class Intern {
public:
	Intern();
	Intern(const Intern& instance);
	Intern&	operator=(const Intern& instance);
	~Intern();

	AForm*	makeForm(const std::string& name, const std::string& target);
};
#endif // Intern_HPP
