/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 13:12:05 by aindjare          #+#    #+#             */
/*   Updated: 2025/01/01 13:15:33 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cat.hpp"

Cat::Cat(): Animal("Cat") {
	std::cout << "Cat :: Constructor default" << std::endl;
}
Cat::Cat(const Cat& o): Animal(o.type) {
	std::cout << "Cat :: Constructor copy" << std::endl;
}
Cat::~Cat() {
	std::cout << "Cat :: Destructor" << std::endl;
}
Cat&	Cat::operator=(const Cat& o) {
	std::cout << "Cat :: Assignment copy" << std::endl;
	this->type = o.type;
	return (*this);
}

void	Cat::makeSound(void) const {
	std::cout << "Cat meows" << std::endl;
}
