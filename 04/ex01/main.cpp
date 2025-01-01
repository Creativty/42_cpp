/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 12:57:59 by aindjare          #+#    #+#             */
/*   Updated: 2025/01/01 14:09:22 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
	Animal	*animals[8];
	// Constructors
	for (size_t i = 0; i < 8; i++) {
		if (i % 2 == 0) {
			animals[i] = new Cat;
		} else {
			animals[i] = new Dog;
		}
	}
	// Methods
	for (size_t i = 0; i < 8; i++)
		animals[i]->makeSound();
	// Destructors
	for (size_t i = 0; i < 8; i++)
		delete animals[i];
	return (0);
}
