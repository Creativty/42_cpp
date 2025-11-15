/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenobas <rahimos.123@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 11:18:59 by xenobas           #+#    #+#             */
/*   Updated: 2025/11/15 13:08:44 by xenobas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <cfloat>
#include <climits>
#include <cstdlib>
#include <iomanip>
#include <ostream>
#include <iostream>

std::ostream&		operator<<(std::ostream& stream, const ScalarType& type) {
	switch (type) {
	case SCALAR_INVALID:
		stream << "invalid";
		break ;
	case SCALAR_INT:
		stream << "int";
		break ;
	case SCALAR_FLOAT:
		stream << "float";
		break ;
	case SCALAR_DOUBLE:
		stream << "double";
		break ;
	default:
		stream << "unknown";
		break ;
	}
	return (stream);
}

static bool			is_inf(const std::string& literal) {
	if (literal == "-inff" || literal == "+inff") {
		return (true);
	}
	else if (literal == "-inf" || literal == "+inf") {
		return (true);
	}
	else {
		return (false);
	}
}
static bool			is_nan(const std::string& literal) {
	if (is_inf(literal)) {
		return (true);
	}
	else if (literal == "nan" || literal == "nanf") {
		return (true);
	}
	else {
		return (false);
	}
}
static bool			is_lit(char ch) {
	if (ch >= '0' && ch <= '9') {
		return (true);
	}
	return (ch == '-' || ch == '+' || ch == '.' || ch == 'f' || ch == 'e' || ch == 'E');
}

static ScalarType	query_type(const std::string& literal) {
	ScalarType	type = SCALAR_INVALID;

	char		ch = '\0';
	char		ch_last = '\0';

	size_t		i = 0ul;
	bool		dot = false;
	bool		exp_prefix = false;
	bool		float_suffix = false;
	for (; i < literal.size(); ch_last = ch, ++i) {
		ch = literal[i];

		if (!is_lit(literal[i])) {
			break ;
		}

		if (i == 0ul && ((ch >= '0' && ch <= '9') || ch == '-' || ch == '+')) {
			type = SCALAR_INT;
			continue ;
		}

		if (literal[i] == '-' || literal[i] == '+') {
			if (ch_last != 'e' && ch_last  != 'E') {
				return (SCALAR_INVALID);
			}
		}

		if (ch == 'e' || ch == 'E') {
			if (exp_prefix) {
				return (SCALAR_INVALID);
			}

			dot = true;
			exp_prefix = true;

			type = SCALAR_DOUBLE;
		}

		if (float_suffix) {
			return (SCALAR_INVALID);
		}

		if (literal[i] == '.') {
			if (dot) {
				type = SCALAR_INVALID;
				break ;
			}

			dot = true;
			type = SCALAR_DOUBLE;

			continue ;
		}

		if (literal[i] == 'f') {
			if (!dot) {
				return (SCALAR_INVALID);
			}

			type = SCALAR_FLOAT;
			float_suffix = true;

			continue ;
		}
	}

	if (type == SCALAR_FLOAT && ch_last != 'f') {
		type = SCALAR_INVALID;
	} else if (i != literal.size()) {
		type = SCALAR_INVALID;
	}
	return (type);
}

static int			read_int(const std::string& literal, bool* ok = NULL) {
	char*	end = NULL;
	long	number = std::strtol(literal.c_str(), &end, 10);

	if (ok) {
		if (number < INT_MIN || number > INT_MAX) {
			*ok = false;
		}
		if (!end || *end) {
			*ok = false;
		}
	}
	return (static_cast<int>(number));
}
static float		read_float(const std::string& literal, bool* ok = NULL) {
	char*	end = NULL;
	double	number = std::strtod(literal.c_str(), &end);

	if (ok) {
		if (number < FLT_MIN || number > FLT_MAX) {
			*ok = false;
		}
		if (!end || *end != 'f') {
			*ok = false;
		}
	}
	return (static_cast<float>(number));
}
static double		read_double(const std::string& literal, bool* ok = NULL) {
	char*	end = NULL;
	double	number = std::strtod(literal.c_str(), &end);

	if (ok && (!end || *end)) {
		*ok = false;
	}
	return (number);
}

					ScalarConverter::ScalarConverter(void) { }
					ScalarConverter::~ScalarConverter(void) { }
					ScalarConverter::ScalarConverter(const ScalarConverter& conv) { (void)conv; }
ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& conv) { (void)conv; return (*this); }
void				ScalarConverter::convert(const std::string& literal) {
	if (is_nan(literal)) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if (is_inf(literal)) {
			std::cout << "float: " << literal[0] << "inff" << std::endl;
			std::cout << "double: " << literal[0] << "inf" << std::endl;
		} else {
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
		}
		return ;
	}

	ScalarType	type = query_type(literal);
	// std::cout << "literal \"" << literal << "\" is of type " << type << std::endl;

	{ /* NOTE(xenobas): char */
		int			n = -1;
		char		ch = static_cast<char>(n);
		bool		is_impo = false;
		switch (type) {
			case SCALAR_INT: {
				n = read_int(literal, &is_impo);
			} break ;
			case SCALAR_FLOAT: {
				n = static_cast<int>(read_float(literal, &is_impo));
			} break ;
			case SCALAR_DOUBLE: {
				n = static_cast<int>(read_double(literal, &is_impo));
			} break ;
			case SCALAR_INVALID:
			default: {
				n = -1;
				is_impo = true;
			} break ;
		}

		ch = static_cast<char>(n);
		if (!is_impo) {
			is_impo = (n < 0 || n > 127);
		}

		if (is_impo) {
			std::cout << "char: Impossible" << std::endl;
		}
		else if (!std::isprint(ch)) {
			std::cout << "char: Not displayable" << std::endl;
		}
		else {
			std::cout << "char: '" << ch << "'" << std::endl;
		}
	}

	{ /* NOTE(xenobas): int */
		int		n = 0;
		bool	is_impo = false;
		switch (type) {
		case SCALAR_INT: {
			n = read_int(literal);
		} break ;
		case SCALAR_FLOAT: {
			n = static_cast<int>(read_float(literal));
		} break ;
		case SCALAR_DOUBLE: {
			n = static_cast<int>(read_double(literal));
		} break ;
		case SCALAR_INVALID:
		default: {
			is_impo = true;
		} break ;
		}

		if (is_impo) {
			std::cout << "int: Impossible" << std::endl;
		} else {
			std::cout << "int: " << n << std::endl;
		}
	}

	{ /* NOTE(xenobas): float */
		float	n = 0.0f;
		bool	is_impo = false;
		switch (type) {
		case SCALAR_INT: {
			n = static_cast<float>(read_int(literal));
		} break ;
		case SCALAR_FLOAT: {
			n = read_float(literal);
		} break ;
		case SCALAR_DOUBLE: {
			n = static_cast<float>(read_double(literal));
		} break ;
		case SCALAR_INVALID:
		default: {
			is_impo = true;
		} break ;
		}

		if (is_impo) {
			std::cout << "float: Impossible" << std::endl;
		} else {
			std::cout << "float: " << std::fixed << std::setprecision(1) << n << 'f' << std::endl;
		}
	}

	{ /* NOTE(xenobas): double */
		double	n = 0.0;
		bool	is_impo = false;
		switch (type) {
		case SCALAR_INT: {
			n = static_cast<double>(read_int(literal));
		} break ;
		case SCALAR_FLOAT: {
			n = static_cast<double>(read_float(literal));
		} break ;
		case SCALAR_DOUBLE: {
			n = read_double(literal);
		} break ;
		case SCALAR_INVALID:
		default: {
			is_impo = true;
		} break ;
		}

		if (is_impo) {
			std::cout << "double: Impossible" << std::endl;
		} else {
			std::cout << "double: " << std::fixed << std::setprecision(1) << n << std::endl;
		}
	}
}
