/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 12:59:40 by aindjare          #+#    #+#             */
/*   Updated: 2025/01/01 14:17:55 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Animal_hpp
#define Animal_hpp
#include <string>
class Animal {
public:
	Animal(std::string type);
	virtual ~Animal();

	const std::string&	getType(void) const;
	virtual	void		makeSound(void) const = 0;
protected:
	std::string	type;
};
#endif
