/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 16:00:36 by aindjare          #+#    #+#             */
/*   Updated: 2025/06/05 16:37:24 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <ostream>
#include <exception>

class Bureaucrat {
public:
	class GradeTooHighException: public std::exception {
	public:
		GradeTooHighException();
		virtual ~GradeTooHighException() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW;
		virtual const char*	what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW;
	private:
		std::string	message;
	};
	class GradeTooLowException: public std::exception {
	public:
		GradeTooLowException();
		virtual ~GradeTooLowException() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW;
		virtual const char*	what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW;
	private:
		std::string	message;
	};

	Bureaucrat(std::string name, unsigned int grade) throw(GradeTooLowException, GradeTooHighException);
	Bureaucrat(const Bureaucrat& other);
	~Bureaucrat();
	Bureaucrat&		operator=(const Bureaucrat& other);
	friend std::ostream&	operator<<(std::ostream& stream, const Bureaucrat& bureaucrat);

	const std::string& getName(void) const;
	unsigned int getGrade(void) const;
private:
	std::string		name;
	unsigned int	grade;
};

std::ostream&	operator<<(std::ostream& stream, const Bureaucrat& bureaucrat);
#endif
