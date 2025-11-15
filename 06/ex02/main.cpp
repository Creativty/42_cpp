/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenobas <rahimos.123@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:03:58 by xenobas           #+#    #+#             */
/*   Updated: 2025/11/15 13:05:46 by xenobas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <cstdlib>
#include <iostream>
#include "Base.hpp"

#define RET_OK 0
#define RET_FAIL 1

int		main(void) {
	std::srand((unsigned int)(std::time(0)));

	Base*	base = generate();
	base->declare();

	std::cout << "identify(ptr):" << std::endl;
	std::cout << '\t'; identify(base);

	std::cout << "identify(ref):" << std::endl;
	std::cout << '\t'; identify(*base);

	delete base;
	return (RET_OK);
}
