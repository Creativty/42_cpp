/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 12:58:41 by aindjare          #+#    #+#             */
/*   Updated: 2025/01/01 14:02:40 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cat_hpp
#define Cat_hpp
#include "Brain.hpp"
#include "Animal.hpp"
class Cat: public Animal {
public:
	Cat();
	Cat(const Cat& o);
	~Cat();

	Cat&	operator=(const Cat& o);
	void	makeSound(void) const;
private:
	Brain*	brain;
};
#endif
