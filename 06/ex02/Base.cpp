/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenobas <rahimos.123@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 12:51:01 by xenobas           #+#    #+#             */
/*   Updated: 2025/11/15 13:06:18 by xenobas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "Base.hpp"

Base::~Base(void) {
};
A::~A(void) {
}
B::~B(void) {
}
C::~C(void) {
}
void	A::declare(void) const {
	std::cout << "A says: Hellope!" << std::endl;
};
void	B::declare(void) const {
	std::cout << "B says: Hi!" << std::endl;
};
void	C::declare(void) const {
	std::cout << "C says: Hello, World!" << std::endl;
};

Base*	generate(void) {
	int	idx = rand() % 3;
	switch (idx) {
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
		default:
			return (0); /* Unreachable */
	}
}

void	identify(Base* p) {
	A*	a = dynamic_cast<A*>(p);
	if (a != 0) {
		std::cout << static_cast<void*>(p) << " is an A instance" << std::endl;
		return ;
	}

	B*	b = dynamic_cast<B*>(p);
	if (b != 0) {
		std::cout << static_cast<void*>(p) << " is an B instance" << std::endl;
		return ;
	}

	C*	c = dynamic_cast<C*>(p);
	if (c != 0) {
		std::cout << static_cast<void*>(p) << " is an C instance" << std::endl;
		return ;
	}

	std::cout << static_cast<void*>(p) << "'s class cannot be determined" << std::endl;
}
void	identify(Base& p) {
	try {
		dynamic_cast<A&>(p);
		std::cout << static_cast<void*>(&p) << " is an A instance" << std::endl;
		return ;
	} catch (std::exception& err) { }

	try {
		dynamic_cast<B&>(p);
		std::cout << static_cast<void*>(&p) << " is an B instance" << std::endl;
		return ;
	} catch (std::exception& err) { }

	try {
		dynamic_cast<C&>(p);
		std::cout << static_cast<void*>(&p) << " is an C instance" << std::endl;
		return ;
	} catch (std::exception& err) { }

	std::cout << static_cast<void*>(&p) << "'s class cannot be determined" << std::endl;
}
