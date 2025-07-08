/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 10:48:52 by aindjare          #+#    #+#             */
/*   Updated: 2025/07/08 15:59:53 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef   AForm_HPP
#define   AForm_HPP
#include  "Bureaucrat.hpp"
#include  <string>
#include  <ostream>
#include  <exception>

class Bureaucrat;
class AForm {
private:
	const std::string	name;
	const unsigned int	grade_sign;
	const unsigned int	grade_exec;
	bool				is_signed;
public:
	AForm(const std::string& name, unsigned int grade_sign, unsigned int grade_exec);
	AForm(const AForm& instance);
	AForm&	operator=(const AForm& instance);
	virtual ~AForm();

	const std::string&	getName(void) const;
	bool				getIsSigned(void) const;
	unsigned int		getGradeSign(void) const;
	unsigned int		getGradeExec(void) const;

	void				beSigned(const Bureaucrat& bureaucrat);
	virtual void		beExecuted(void) const = 0;

	void				execute(Bureaucrat const& executor) const;
	class GradeTooHighException: public std::exception {
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException: public std::exception {
	public:
		virtual const char *what() const throw();
	};
};

// ShrubberyCreationForm(target), (sign 145, exec 137), create file `<target>_shrubbery` and write ASCII tree inside of it.
// RobotomyRequestForm(target),   (sign 72, exec 45),   print drilling noises, print whether `<target>` has been robotimized (50%).
// PresidentialPardonForm(target), (sign 25, exec 5),    print `<target>` has been pardoned by Zephod Beeblebrox.

std::ostream&	operator<<(std::ostream& stream, const AForm& instance);
#endif // AForm_HPP
