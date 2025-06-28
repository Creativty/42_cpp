/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 16:58:52 by aindjare          #+#    #+#             */
/*   Updated: 2025/06/28 15:36:23 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef   Form_HPP
#define   Form_HPP

#include <string>
#include <ostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form {
private:
	const std::string		name;
	bool					is_signed;
	const unsigned int		grade_exec;
	const unsigned int		grade_sign;
public:
	Form(const std::string& name, unsigned int grade_sign, unsigned int grade_exec);
	Form(const Form& instance);
	~Form();

	Form&		operator=(const Form& instance);

	const std::string&	getName(void) const;
	bool				getIsSigned(void) const;
	unsigned int		getGradeExec(void) const;
	unsigned int		getGradeSign(void) const;

	void				beSigned(const Bureaucrat& instance);
	void				checkGrades(void) const;

	class GradeTooHighException: public std::exception {
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException: public std::exception {
	public:
		virtual const char *what() const throw();
	};
	class AlreadySignedException: public std::exception {
	public:
		virtual const char *what() const throw();
	};
};

std::ostream&	operator<<(std::ostream& stream, const Form& instance);
#endif // Form_HPP
