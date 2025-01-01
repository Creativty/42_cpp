/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 13:56:40 by aindjare          #+#    #+#             */
/*   Updated: 2025/01/01 14:02:28 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain :: Constructor default" << std::endl;
}
Brain::Brain(const Brain& o) {
	std::cout << "Brain :: Constructor copy" << std::endl;
	for (size_t i = 0; i < 100; i++)
		this->ideas[i] = o.ideas[i];
}
Brain::~Brain() {
	std::cout << "Brain :: Destructor" << std::endl;
}

Brain&	Brain::operator=(const Brain& o) {
	std::cout << "Brain :: Assignment copy" << std::endl;
	if (this != &o) {
		for (size_t i = 0; i < 100; i++)
			this->ideas[i] = o.ideas[i];
	}
	return (*this);
}
