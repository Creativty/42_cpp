/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 12:59:40 by aindjare          #+#    #+#             */
/*   Updated: 2025/01/01 13:20:24 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Animal_hpp
#define Animal_hpp
#include <string>
class Animal {
public:
	Animal();
	Animal(std::string type);
	Animal(const Animal& o);
	virtual ~Animal();

	const std::string&	getType(void) const;
	virtual	void		makeSound(void) const;

	Animal&				operator=(const Animal& o);
protected:
	std::string	type;
};
#endif
