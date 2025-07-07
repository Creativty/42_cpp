/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 09:43:11 by aindjare          #+#    #+#             */
/*   Updated: 2025/07/07 10:21:48 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef   Bureaucrat_HPP
#define   Bureaucrat_HPP
#include  <string>
#include  <ostream>
#include  <exception>

class Bureaucrat {
private:
	std::string		name;
	unsigned int	grade;
public:
	Bureaucrat(const std::string& name, unsigned int grade);
	Bureaucrat(const Bureaucrat& instance);
	Bureaucrat& operator=(const Bureaucrat& instance);
	~Bureaucrat();

	void				demote(void);
	void				promote(void);
	const std::string&	getName(void) const;
	unsigned int		getGrade(void) const;

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
