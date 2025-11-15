/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenobas <rahimos.123@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:03:58 by xenobas           #+#    #+#             */
/*   Updated: 2025/11/15 11:53:14 by xenobas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <cstdlib>
#include <iostream>
#include "Serializer.hpp"

#define RET_OK 0
#define RET_FAIL 1

int		main(void) {
	std::srand((unsigned int)std::time(NULL));

	/* NOTE(xenobas): Uncomment the following to test instantiation */
	/* Serializer	serializer; */
	bool		serialize_ok = true;
	for (size_t i = 0; i < 5; ++i) {
		Data		data = data_random();

		uintptr_t	data_raw = Serializer::serialize(&data);
		Data*		data_ptr = Serializer::deserialize(data_raw);
		if (data_ptr != &data) {
			serialize_ok = false;
			std::cerr << "At iteration " << i << " serialize -> deserialize did not match original pointer" << std::endl;
		}
	}
	if (serialize_ok) {
		std::cout << "Serialization has passed " << 5 << " random tests." << std::endl;
	}
	return (serialize_ok ? RET_OK : RET_FAIL);
}
