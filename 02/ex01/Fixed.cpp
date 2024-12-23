/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:16:49 by aindjare          #+#    #+#             */
/*   Updated: 2024/12/23 18:24:24 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &a) {
	std::cout << "Copy constructor called" << std::endl;
	this->value = a.value;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed &a) {
	std::cout << "Copy assignment called" << std::endl;
	if (&a != this)
		this->value = a.value;
	return (*this);
}

int		Fixed::getRawBits(void) {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}

// seeeeeeeemmmmmmmmmmmmmmmmmmmmmmm 32 bits
// seeeeeeeeeeeeeeeemmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm 64bits
// (m * 2^e) * s

Fixed::Fixed(const int value) {
}

Fixed::Fixed(const float value) {
}

int		toInt(void) const {
}

float	toFloat(void) const {
}
