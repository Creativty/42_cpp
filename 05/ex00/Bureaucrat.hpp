/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 16:14:33 by aindjare          #+#    #+#             */
/*   Updated: 2025/06/22 17:20:21 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef    Bureaucrat_HPP
#define    Bureaucrat_HPP

#include <string>
#include <ostream>
#include <exception>

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

