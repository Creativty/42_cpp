/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:48:59 by aindjare          #+#    #+#             */
/*   Updated: 2025/07/08 16:29:06 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef   RobotomyRequestForm_HPP
#define   RobotomyRequestForm_HPP
#include  "AForm.hpp"
#include  "Bureaucrat.hpp"
#include  <string>

class AForm;
class Bureaucrat;
class RobotomyRequestForm: public AForm {
private:
	std::string	target;

public:
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& instance);
	RobotomyRequestForm&	operator=(const RobotomyRequestForm& instance);
	~RobotomyRequestForm();

	const std::string&	getTarget(void) const;
	void				beExecuted(void) const;
};
#endif // RobotomyRequestForm_HPP
