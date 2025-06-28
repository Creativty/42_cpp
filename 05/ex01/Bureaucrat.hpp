/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 16:14:33 by aindjare          #+#    #+#             */
/*   Updated: 2025/06/28 15:36:26 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef    Bureaucrat_HPP
#define    Bureaucrat_HPP

#include <string>
#include <ostream>
#include <exception>
#include "Form.hpp"

class Form;
class Bureaucrat {
private:
	const std::string	name;
	unsigned int		grade;
public:
	Bureaucrat(const std::string& name, unsigned int grade);
	Bureaucrat(const Bureaucrat& instance);
	~Bureaucrat();

	Bureaucrat&			operator=(const Bureaucrat& instance);
	unsigned int		getGrade(void) const;
	const std::string&	getName(void) const;

	void				promoteGrade(void);
	void				demoteGrade(void);

	void				signForm(Form& instance) const;
	void				checkGrade(int delta) const;

	class GradeTooHighException: public std::exception {
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException: public std::exception {
	public:
		virtual const char *what() const throw();
	};
};

std::ostream&	operator<<(std::ostream& stream, const Bureaucrat& instance);
#endif  // Bureaucrat_HPP
