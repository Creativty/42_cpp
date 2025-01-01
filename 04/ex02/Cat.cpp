/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 13:12:05 by aindjare          #+#    #+#             */
/*   Updated: 2025/01/01 14:15:57 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"

Cat::Cat(): Animal("Cat") {
	brain = new Brain;
	std::cout << "Cat :: Constructor default" << std::endl;
}
Cat::Cat(const Cat& o): Animal(o.type) {
	brain = new Brain;
	for (size_t i = 0; i < 100; i++)
		brain->ideas[i] = o.brain->ideas[i];
	std::cout << "Cat :: Constructor copy" << std::endl;
}
Cat::~Cat() {
	delete brain;
	std::cout << "Cat :: Destructor" << std::endl;
}
Cat&	Cat::operator=(const Cat& o) {
	if (this != &o) {
		this->type = o.type;
		delete brain;
		brain = new Brain;
		for (size_t i = 0; i < 100; i++)
			brain->ideas[i] = o.brain->ideas[i];
	}
	std::cout << "Cat :: Assignment copy" << std::endl;
	return (*this);
}

void	Cat::makeSound(void) const {
	std::cout << "Cat meows" << std::endl;
}
