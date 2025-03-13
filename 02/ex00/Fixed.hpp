/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 15:39:04 by aindjare          #+#    #+#             */
/*   Updated: 2025/03/13 10:01:08 by aindjare         ###   ########.fr       */
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

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
private:
	int					value;
	static const int	n_frac_bits = 8;
};
#endif
