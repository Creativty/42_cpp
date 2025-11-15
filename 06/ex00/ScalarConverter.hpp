/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenobas <rahimos.123@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 11:16:16 by xenobas           #+#    #+#             */
/*   Updated: 2025/11/15 13:08:54 by xenobas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef   SCALAR_CONVERTER_HPP
#define   SCALAR_CONVERTER_HPP
#include <string>

enum ScalarType {
	SCALAR_INVALID,

	SCALAR_INT,
	SCALAR_FLOAT,
	SCALAR_DOUBLE,
};

class ScalarConverter {
public:
	static void			convert(const std::string&);
private: /* NOTE(xenobas): disallow construction */
	ScalarConverter(void);
	~ScalarConverter(void);
	ScalarConverter(const ScalarConverter& conv);
	ScalarConverter& operator=(const ScalarConverter& conv);
};
#endif /* SCALAR_CONVERTER_HPP */
