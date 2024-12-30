/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:16:49 by aindjare          #+#    #+#             */
/*   Updated: 2024/12/30 13:21:04 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : value(0) {
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const Fixed &a) : value(a.value) {
	std::cout << "Copy constructor called" << std::endl;
}
Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	this->value = value << n_frac_bits;
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	this->value = (roundf(value * (1 << n_frac_bits)));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed &a) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (&a != this)
		this->value = a.value;
	return (*this);
}

std::ostream&	operator<<(std::ostream &stream, const Fixed& fixed) {
	stream << fixed.toFloat();
	return (stream);
}

int		Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}

int		Fixed::toInt(void) const {
	return ((int)this->toFloat());
}

float	Fixed::toFloat(void) const {
	return ((float)this->value / (float)(1 << n_frac_bits));
}
