/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 13:09:29 by aindjare          #+#    #+#             */
/*   Updated: 2025/01/01 13:15:36 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Dog.hpp"

Dog::Dog(): Animal("Dog") {
	std::cout << "Dog :: Constructor default" << std::endl;
}
Dog::Dog(const Dog& o): Animal(o.type) {
	std::cout << "Dog :: Constructor copy" << std::endl;
}
Dog::~Dog() {
	std::cout << "Dog :: Destructor" << std::endl;
}
Dog&	Dog::operator=(const Dog& o) {
	std::cout << "Dog :: Assignment copy" << std::endl;
	this->type = o.type;
	return (*this);
}

void	Dog::makeSound(void) const {
	std::cout << "Dog barks" << std::endl;
}
