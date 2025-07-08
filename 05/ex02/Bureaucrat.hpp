/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 09:43:11 by aindjare          #+#    #+#             */
/*   Updated: 2025/07/08 15:55:10 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef   Bureaucrat_HPP
#define   Bureaucrat_HPP
#include  "AForm.hpp"
#include  <string>
#include  <ostream>
#include  <exception>

class AForm;
class Bureaucrat {
private:
	const std::string	name;
	unsigned int		grade;
public:
	Bureaucrat(const std::string& name, unsigned int grade);
	Bureaucrat(const Bureaucrat& instance);
	Bureaucrat& operator=(const Bureaucrat& instance);
	~Bureaucrat();

	void				demote(void);
	void				promote(void);
	const std::string&	getName(void) const;
	unsigned int		getGrade(void) const;

	void				signForm(AForm& form) const;
	void				executeForm(AForm const& form) const;

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
#endif // Bureaucrat_HPP
