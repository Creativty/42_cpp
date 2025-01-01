/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 13:03:08 by aindjare          #+#    #+#             */
/*   Updated: 2025/01/01 13:24:17 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"

Animal::Animal(): type("Animal") {
	std::cout << "Animal :: Constructor default" << std::endl;
}
Animal::Animal(std::string type): type(type) {
	std::cout << "Animal :: Constructor arguments" << std::endl;
}
Animal::Animal(const Animal& o): type(o.type) {
	std::cout << "Animal :: Constructor copy" << std::endl;
}
Animal::~Animal() {
	std::cout << "Animal :: Destructor" << std::endl;
}

Animal& Animal::operator=(const Animal& o) {
	std::cout << "Animal :: Assignment copy" << std::endl;
	this->type = o.type;
	return (*this);
}
const std::string& Animal::getType(void) const {
	return (this->type);
}
void	Animal::makeSound(void) const {
	std::cout << "Animal *silence*" << std::endl;
}
