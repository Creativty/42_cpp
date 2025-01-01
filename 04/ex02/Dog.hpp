/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 12:59:42 by aindjare          #+#    #+#             */
/*   Updated: 2025/01/01 14:05:38 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Dog_hpp
#define Dog_hpp
#include "Brain.hpp"
#include "Animal.hpp"
class Dog: public Animal {
public:
	Dog();
	Dog(const Dog& o);
	~Dog();

	Dog&	operator=(const Dog& o);
	void	makeSound(void) const;
public:
	Brain*	brain;
};
#endif
