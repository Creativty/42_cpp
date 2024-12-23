/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:13:04 by aindjare          #+#    #+#             */
/*   Updated: 2024/12/23 18:14:17 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &a);
	Fixed&	operator=(const Fixed &a);

	Fixed(const int value);
	Fixed(const float value);

	int		toInt(void) const;
	float	toFloat(void) const;
	int		getRawBits(void);
	void	setRawBits(int const raw);
private:
	int					value;
	static const int	n_frac_bits = 8;
};

#endif