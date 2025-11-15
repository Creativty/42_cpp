/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenobas <rahimos.123@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 11:50:38 by xenobas           #+#    #+#             */
/*   Updated: 2025/11/15 13:10:49 by xenobas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

#include <cstdlib>
#define		count_of(XS) (static_cast<int>(sizeof(XS) / sizeof((XS)[0])))
Data		data_random(void) {
	static const char*	strs[] = { "Hello, world", "#include <stdio.h>", "package main", "import math", "Hellope" };
	
	Data	data;

	data.num = rand();
	data.str = strs[data.num % count_of(strs)];
	return (data);
}

Serializer::Serializer(void) { };
Serializer::~Serializer(void) { };
Serializer::Serializer(const Serializer& serde) { (void)serde; };
const Serializer&	Serializer::operator=(const Serializer& serde) { (void)serde; return (*this); };

uintptr_t			Serializer::serialize(Data* ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}
Data*				Serializer::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data*>(raw));
}
