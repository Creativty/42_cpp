#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) throw(GradeTooLowException, GradeTooHighException) {
	if (grade  <   1) throw GradeTooHighException();
	if (grade  > 150) throw GradeTooLowException();
	this->name = name;
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) {
	/* No need for throwing given that the other bureaucrat is already instantiated, thus always valid */
	this->name = other.name;
	this->grade = other.grade;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other) {
	/* No need for throwing given that the other bureaucrat is already instantiated, thus always valid */
	this->name = other.name;
	this->grade = other.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() { }

Bureaucrat::GradeTooHighException::GradeTooHighException() : message("Grade too high") { }
Bureaucrat::GradeTooLowException::GradeTooLowException() : message("Grade too low") { }

Bureaucrat::GradeTooHighException::~GradeTooHighException() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW { }
Bureaucrat::GradeTooLowException::~GradeTooLowException() _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW { }

const std::string& Bureaucrat::getName(void) const {
	return (this->name);
}
unsigned int Bureaucrat::getGrade(void) const {
	return (this->grade);
}

std::ostream&	operator<<(std::ostream& stream, const Bureaucrat& bureaucrat) {
	stream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (stream);
}

const char*	Bureaucrat::GradeTooHighException::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW { return (this->message.c_str()); }
const char*	Bureaucrat::GradeTooLowException::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW { return (this->message.c_str()); }
