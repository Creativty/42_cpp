/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 13:09:29 by aindjare          #+#    #+#             */
/*   Updated: 2025/01/01 14:05:24 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"

Dog::Dog(): Animal("Dog") {
	brain = new Brain;
	std::cout << "Dog :: Constructor default" << std::endl;
}
Dog::Dog(const Dog& o): Animal(o.type) {
	brain = new Brain;
	for (size_t i = 0; i < 100; i++)
		brain->ideas[i] = o.brain->ideas[i];
	std::cout << "Dog :: Constructor copy" << std::endl;
}
Dog::~Dog() {
	delete brain;
	std::cout << "Dog :: Destructor" << std::endl;
}
Dog&	Dog::operator=(const Dog& o) {
	this->type = o.type;
	if (this != &o) {
		this->type = o.type;
		delete brain;
		brain = new Brain;
		for (size_t i = 0; i < 100; i++)
			brain->ideas[i] = o.brain->ideas[i];
	}
	std::cout << "Dog :: Assignment copy" << std::endl;
	return (*this);
}

void	Dog::makeSound(void) const {
	std::cout << "Dog barks" << std::endl;
}
