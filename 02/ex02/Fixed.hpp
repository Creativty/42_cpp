/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 08:52:04 by aindjare          #+#    #+#             */
/*   Updated: 2025/03/13 10:18:20 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed {
public:
	static	Fixed& max(Fixed& lhs, Fixed& rhs);
	static	Fixed& min(Fixed& lhs, Fixed& rhs);
	static	const Fixed& max(const Fixed& lhs, const Fixed& rhs);
	static	const Fixed& min(const Fixed& lhs, const Fixed& rhs);

public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &a);

	Fixed(const int value);
	Fixed(const float value);

	int		toInt(void) const;
	float	toFloat(void) const;
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	Fixed&	operator=(const Fixed &a);

	bool	operator==(const Fixed& rhs) const;
	bool	operator!=(const Fixed& rhs) const;
	bool	operator< (const Fixed& rhs) const;
	bool	operator<=(const Fixed& rhs) const;
	bool	operator> (const Fixed& rhs) const;
	bool	operator>=(const Fixed& rhs) const;

	Fixed	operator+(const Fixed& rhs) const;
	Fixed	operator-(const Fixed& rhs) const;
	Fixed	operator*(const Fixed& rhs) const;
	Fixed	operator/(const Fixed& rhs) const;

	Fixed	operator++();
	Fixed	operator++(int);
	Fixed	operator--();
	Fixed	operator--(int);

	friend std::ostream&	operator<<(std::ostream &stream, const Fixed& f);

private:
	static int	floatToBits(const float value);

	int					value;
	static const int	n_frac_bits = 8;
};
#endif
