/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 08:50:25 by aindjare          #+#    #+#             */
/*   Updated: 2025/03/13 10:36:43 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <bitset>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include "Fixed.hpp"

enum e_op {
	OP_ADD = 0,
	OP_SUB,
	OP_MUL,
	OP_DIV,
	OP_EQ,
	OP_NEQ,
	OP_GT,
	OP_GTE,
	OP_LT,
	OP_LTE,
	OP_MAX,
	OP_MIN,
	OP_ASSIGN,
};

const char *op_strs[OP_ASSIGN + 1] = {
	"  + ",
	"  - ",
	"  * ",
	"  / ",
	" == ",
	" != ",
	"  > ",
	" >= ",
	"  < ",
	" <= ",
	" max ",
	" min ",
	"  = ",
};

void	test(float lhs, float rhs, enum e_op op) {
	float	res_float;
	Fixed	res_fixed;
	bool	did_print = false;

	if (op == OP_ASSIGN)
		std::cout << std::fixed << "f = " << lhs << " :: ";
	else
		std::cout << std::fixed << lhs << op_strs[op] << rhs << " :: ";
	switch (op) {
		case OP_ADD: {
			res_float = lhs + rhs;
			res_fixed = Fixed(lhs) + Fixed(rhs);
		} break ;
		case OP_SUB: {
			res_float = lhs - rhs;
			res_fixed = Fixed(lhs) - Fixed(rhs);
		} break ;
		case OP_MUL: {
			res_float = lhs * rhs;
			res_fixed = Fixed(lhs) * Fixed(rhs);
		} break ;
		case OP_DIV: {
			res_float = lhs / rhs;
			res_fixed = Fixed(lhs) / Fixed(rhs);
		} break ;
		case OP_MAX: {
			res_float = std::max(lhs, rhs);
			res_fixed = Fixed::max(Fixed(lhs), Fixed(rhs));
		} break ;
		case OP_MIN: {
			res_float = std::min(lhs, rhs);
			res_fixed = Fixed::min(Fixed(lhs), Fixed(rhs));
		} break ;
		case OP_ASSIGN: {
			res_float = lhs;
			res_fixed = Fixed(lhs);
			std::cout << "float " << res_float << ", ";
			std::cout << "fixed " << res_fixed << std::endl;
			did_print = true;
		} break ;
		case OP_EQ: {
			std::cout << std::boolalpha;
			std::cout << "float " << (lhs == rhs) << ", ";
			std::cout << "fixed " << (Fixed(lhs) == Fixed(rhs));
			std::cout << std::endl;
			did_print = true;
		} break ;
		case OP_NEQ: {
			std::cout << std::boolalpha;
			std::cout << "float " << (lhs != rhs) << ", ";
			std::cout << "fixed " << (Fixed(lhs) != Fixed(rhs));
			std::cout << std::endl;
			did_print = true;
		} break ;
		case OP_GT: {
			std::cout << std::boolalpha;
			std::cout << "float " << (lhs > rhs) << ", ";
			std::cout << "fixed " << (Fixed(lhs) > Fixed(rhs));
			std::cout << std::endl;
			did_print = true;
		} break ;
		case OP_GTE: {
			std::cout << std::boolalpha;
			std::cout << "float " << (lhs >= rhs) << ", ";
			std::cout << "fixed " << (Fixed(lhs) >= Fixed(rhs));
			std::cout << std::endl;
			did_print = true;
		} break ;
		case OP_LT: {
			std::cout << std::boolalpha;
			std::cout << "float " << (lhs < rhs) << ", ";
			std::cout << "fixed " << (Fixed(lhs) < Fixed(rhs));
			std::cout << std::endl;
			did_print = true;
		} break ;
		case OP_LTE: {
			std::cout << std::boolalpha;
			std::cout << "float " << (lhs <= rhs) << ", ";
			std::cout << "fixed " << (Fixed(lhs) <= Fixed(rhs));
			std::cout << std::endl;
			did_print = true;
		} break ;
	}
	if (!did_print) {
		std::cout << "float " << res_float << ", ";
		std::cout << "fixed " << res_fixed << std::endl;
	}
}

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << "----------------    Standard   ----------------" << std::endl;
	std::cout << "   a   :: " << a << std::endl;
	std::cout << " ++a   :: " << ++a << std::endl;
	std::cout << "   a   :: " << a << std::endl;
	std::cout << "   a++ :: " << a++ << std::endl;
	std::cout << "   a   :: " << a << std::endl;
	std::cout << "   b   :: " << b << std::endl;
	std::cout << "  max  :: " << Fixed::max(a, b) << std::endl;
	std::cout << "  min  :: " << Fixed::min(a, b) << std::endl;
	std::cout << "----------------    Addition    ----------------" << std::endl;
	test(32.0f, 64.0f, OP_ADD);
	test(32.0f, 64.0f, OP_ADD);
	std::cout << "----------------   Subtraction  ----------------" << std::endl;
	test(32.0f, 64.4f, OP_SUB);
	test(0.0f, 0.2f, OP_SUB);
	std::cout << "----------------   Assignment     ----------------" << std::endl;
	test(-49.5f,  0.0f, OP_ASSIGN);
	test(+49.5f,  0.0f, OP_ASSIGN);
	std::cout << "---------------- Multiplication ----------------" << std::endl;
	test(0.0f, 64.4f, OP_MUL);
	test(1.0f, 64.4f, OP_MUL);
	test(2.0f, 64.4f, OP_MUL);
	std::cout << "----------------    Division   ----------------" << std::endl;
	try {
		test(2.0f, 0.0f, OP_DIV);
	} catch (const char *reason) {
		std::cerr << "test failed because of `" << reason << "`." << std::endl;
	}
	test(0.0f, 64.4f, OP_DIV);
	test(64.4f, 1.0f, OP_DIV);
	test(64.4f, 2.0f, OP_DIV);
	test(2.0f, 64.4f, OP_DIV);
	std::cout << "----------------    Equality   ----------------" << std::endl;
	test(0.0f, 64.4f, OP_EQ);
	test(64.4f, 64.4f, OP_EQ);
	test(64.4f, 2.0f, OP_NEQ);
	test(64.4f, 64.4f, OP_NEQ);
	std::cout << "----------------    Greater   ----------------" << std::endl;
	test(0.0f, 64.4f, OP_GT);
	test(64.4f, 64.4f, OP_GT);
	test(64.4f, 0.4f, OP_GT);
	test(64.4f, 2.0f, OP_GTE);
	test(64.4f, 64.4f, OP_GTE);
	test(64.4f, 0.4f, OP_GTE);
	std::cout << "----------------     Lower   ----------------" << std::endl;
	test(0.0f, 64.4f, OP_LT);
	test(64.4f, 64.4f, OP_LT);
	test(64.4f, 0.4f, OP_LT);
	test(64.4f, 2.0f, OP_LTE);
	test(64.4f, 64.4f, OP_LTE);
	test(64.4f, 0.4f, OP_LTE);
	std::cout << "----------------      Max   ----------------" << std::endl;
	test(0.0f, 2.2f, OP_MAX);
	test(64.4f, 64.4f, OP_MAX);
	test(64.4f, 0.4f, OP_MAX);
	std::cout << "----------------      Min   ----------------" << std::endl;
	test(64.4f, 2.0f, OP_MIN);
	test(64.4f, 64.4f, OP_MIN);
	test(64.4f, 0.4f, OP_MIN);
	return 0;
}
