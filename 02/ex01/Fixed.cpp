/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:16:49 by aindjare          #+#    #+#             */
/*   Updated: 2024/12/25 18:50:16 by aindjare         ###   ########.fr       */
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
	int	sign = (value < 0) ? 1 : 0;
	int	integer = (value < 0) ? -value : value;
	this->value = (sign << 31) | (integer << n_frac_bits);
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	int	integer = (int)value;
	int	decimal  = (int)roundf((value - integer) * 256.0f);
	int	sign = 0;
	if (integer < 0) {
		sign = 1;
		integer = -integer;
	}
	this->value = (sign << 31) | (integer << n_frac_bits) | decimal;
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
	int	sign = (value >> 31) & 1;
	int mantissa = ((value & 0x7fffffff) >> n_frac_bits) ;
	return (sign ? -mantissa : mantissa);
}

float	Fixed::toFloat(void) const {
	int	sign = (value >> 31) & 1;
	int	integer = ((value & 0x7FFFFFFF) >> n_frac_bits);
	int	decimal = (value & 0xFF);
	if (sign)
		integer = -integer;
	return ((float)integer + (float)decimal / 256.0f);
}
