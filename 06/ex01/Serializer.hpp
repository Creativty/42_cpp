/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenobas <rahimos.123@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 11:50:49 by xenobas           #+#    #+#             */
/*   Updated: 2025/11/15 13:09:59 by xenobas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef   SERIALIZER_HPP
#define   SERIALIZER_HPP
#include <string>
#include <stdint.h>

struct Data {
	int			num;
	std::string	str;
};

Data	data_random(void);

class Serializer {
private:
	Serializer(void);
	~Serializer(void);
	Serializer(const Serializer& serde);
	const Serializer&	operator=(const Serializer& serde);
public:
	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);
};
#endif /* SERIALIZER_HPP */
