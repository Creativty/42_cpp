/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:39:04 by aindjare          #+#    #+#             */
/*   Updated: 2024/12/23 15:44:03 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
public:
	Fixed(); // Default constructor
	~Fixed(); // Destructor
	Fixed(const Fixed &a); // Copy constructor
	Fixed&	operator=(const Fixed &a); // Copy assignment

	int		getRawBits(void);
	void	setRawBits(int const raw);
private:
	int					value;
	static const int	n_frac_bits = 8;
};

#endif
