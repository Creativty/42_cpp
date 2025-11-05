/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:48:59 by aindjare          #+#    #+#             */
/*   Updated: 2025/07/08 16:00:18 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef   ShrubberyCreationForm_HPP
#define   ShrubberyCreationForm_HPP
#include  "AForm.hpp"
#include  "Bureaucrat.hpp"
#include  <string>

class AForm;
class Bureaucrat;
class ShrubberyCreationForm: public AForm {
private:
	std::string	target;

public:
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& instance);
	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& instance);
	~ShrubberyCreationForm();

	const std::string&	getTarget(void) const;
	void				beExecuted(void) const;
};
#endif // ShrubberyCreationForm_HPP
