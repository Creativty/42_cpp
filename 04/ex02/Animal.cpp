/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 13:03:08 by aindjare          #+#    #+#             */
/*   Updated: 2025/01/01 14:16:25 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"

Animal::Animal(std::string type): type(type) {
	std::cout << "Animal :: Constructor arguments" << std::endl;
}
Animal::~Animal() {
	std::cout << "Animal :: Destructor" << std::endl;
}

const std::string& Animal::getType(void) const {
	return (this->type);
}
