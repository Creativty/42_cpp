/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:23:02 by aindjare          #+#    #+#             */
/*   Updated: 2025/07/08 16:23:28 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef   PresidentialPardonForm_HPP
#define   PresidentialPardonForm_HPP
#include  "AForm.hpp"
#include  "Bureaucrat.hpp"
#include  <string>

class AForm;
class Bureaucrat;
class PresidentialPardonForm: public AForm {
private:
	std::string	target;

public:
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& instance);
	PresidentialPardonForm&	operator=(const PresidentialPardonForm& instance);
	~PresidentialPardonForm();

	const std::string&	getTarget(void) const;
	void				beExecuted(void) const;
};
#endif // PresidentialPardonForm_HPP
