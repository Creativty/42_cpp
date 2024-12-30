/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 08:52:15 by aindjare          #+#    #+#             */
/*   Updated: 2024/12/30 13:21:16 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : value(0) { }
Fixed::Fixed(const Fixed& a) : value(a.getRawBits()) { }
Fixed::Fixed(const int value) {
	setRawBits(value << n_frac_bits);
}
Fixed::Fixed(const float value) {
	setRawBits(roundf(value * (float)(1 << n_frac_bits)));
}

Fixed::~Fixed() { }

int		Fixed::getRawBits(void) const {
	return (this->value);
}
void	Fixed::setRawBits(int const raw) {
	this->value = raw;
}
float	Fixed::toFloat(void) const {
	return ((float)getRawBits() / (float)(1 << n_frac_bits));
}
int		Fixed::toInt(void) const {
	return ((int)this->toFloat());
}

Fixed& Fixed::max(Fixed& lhs, Fixed& rhs) {
	return (lhs < rhs ? rhs : lhs);
}
Fixed& Fixed::min(Fixed& lhs, Fixed& rhs) {
	return (lhs > rhs ? rhs : lhs);
}
const Fixed& Fixed::max(const Fixed& lhs, const Fixed& rhs) {
	return (lhs < rhs ? rhs : lhs);
}
const Fixed& Fixed::min(const Fixed& lhs, const Fixed& rhs) {
	return (lhs > rhs ? rhs : lhs);
}

Fixed&	Fixed::operator=(const Fixed &a) {
	if (&a != this)
		setRawBits(a.getRawBits());
	return (*this);
}

bool	Fixed::operator==(const Fixed& rhs) const {
	return (this->value == rhs.value);
}
bool	Fixed::operator!=(const Fixed& rhs) const {
	return !(*this == rhs);
}
bool	Fixed::operator>(const Fixed& rhs) const {
	return (this->toFloat() > rhs.toFloat());
}
bool	Fixed::operator<(const Fixed& rhs) const {
	return (this->toFloat() < rhs.toFloat());
}
bool	Fixed::operator<=(const Fixed& rhs) const {
	return (*this < rhs || *this == rhs);
}
bool	Fixed::operator>=(const Fixed& rhs) const {
	return (*this > rhs || *this == rhs);
}

Fixed	Fixed::operator+(const Fixed& rhs) const {
	return (Fixed(this->toFloat() + rhs.toFloat()));
}
Fixed	Fixed::operator-(const Fixed& rhs) const {
	return (Fixed(this->toFloat() - rhs.toFloat()));
}
Fixed	Fixed::operator*(const Fixed& rhs) const {
	return (Fixed(this->toFloat() * rhs.toFloat()));
}
Fixed	Fixed::operator/(const Fixed& rhs) const {
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed	Fixed::operator++() {
	float value = this->toFloat() + (1.0f / (float)(1 << n_frac_bits));
	setRawBits(roundf(value * (float)(1 << n_frac_bits)));
	return (*this);
}
Fixed	Fixed::operator++(int) {
	Fixed	clone(*this);
	float value = this->toFloat() + (1.0f / (float)(1 << n_frac_bits));
	setRawBits(roundf(value * (float)(1 << n_frac_bits)));
	return (clone);
}
Fixed	Fixed::operator--() {
	return (*this);
}
Fixed	Fixed::operator--(int) {
	return (*this);
}

std::ostream&	operator<<(std::ostream &stream, const Fixed& fixed) {
	stream << fixed.toFloat();
	return (stream);
}

