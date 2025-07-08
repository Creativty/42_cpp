/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 10:48:52 by aindjare          #+#    #+#             */
/*   Updated: 2025/07/07 13:52:31 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef   Form_HPP
#define   Form_HPP
#include  <string>
#include  <ostream>
#include  <exception>
#include  "Bureaucrat.hpp"

class Bureaucrat;
class Form {
private:
	const std::string	name;
	const unsigned int	grade_sign;
	const unsigned int	grade_exec;
	bool				is_signed;
public:
	Form(const std::string& name, unsigned int grade_sign, unsigned int grade_exec);
	Form(const Form& instance);
	Form&	operator=(const Form& instance);
	~Form();

	const std::string&	getName(void) const;
	bool				getIsSigned(void) const;
	unsigned int		getGradeSign(void) const;
	unsigned int		getGradeExec(void) const;

	void				beSigned(const Bureaucrat& bureaucrat);
	class GradeTooHighException: public std::exception {
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException: public std::exception {
	public:
		virtual const char *what() const throw();
	};
};

std::ostream&	operator<<(std::ostream& stream, const Form& instance);
#endif // Form_HPP
