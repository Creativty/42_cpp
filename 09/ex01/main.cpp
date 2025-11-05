/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenobas <rahimos.123@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:55:24 by xenobas           #+#    #+#             */
/*   Updated: 2025/11/05 17:38:38 by xenobas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define cast(X) (X)

#define RET_OK			0
#define RET_ERR_ARGC	1
#define RET_ERR_PARSE	2
#define RET_ERR_RUNTIME	4
#define RET_ERR_EMPTY	8

#include <iostream>
#include <exception>
#include "RPN.hpp"

int	main(int argc, const char** argv) {
	if (argc != 2) {
		std::cerr << "usage: " << argv[0] << " <reverse polish notation expression>" << std::endl;
		std::cerr << "    example: " << argv[0] << " '3 1 + 4 *'" << std::endl;
		return (RET_ERR_ARGC);
	}

	RPN_Stack	rpn_stack;
	std::string	rpn_expr = argv[1];

	/* Parser */
	for (size_t i = 0; i < rpn_expr.size(); ++i) {
		char	ch = rpn_expr[i];
		if (ch == ' ' || ch == '\t') {
			continue ;
		}

		if (ch >= '0' && ch <= '9') {
			RPN_Symbol	symbol = rpn_symbol_number(cast(int)(ch - '0'));
			rpn_stack.push(symbol);
			continue ;
		}

		RPN_Operator	op = rpn_operator_match(ch);
		if (op != RPN_OP_INVALID) {
			RPN_Symbol	symbol = rpn_symbol_operator(op);
			rpn_stack.push(symbol);
			continue ;
		}

		std::cerr << "error: could not parse character '" << ch << "' at position " << i << std::endl;
		return (RET_ERR_PARSE);
	}

	if (rpn_stack.empty()) {
		std::cerr << "error: disallowed empty expression" << std::endl;
		return (RET_ERR_EMPTY);
	}

	/* Runtime */
	RPN_Expr*	expr = rpn_expr_parse(rpn_stack);
	bool		error = false;
	try {
		if (!rpn_stack.empty()) {
			throw std::runtime_error("stranded symbols on the stack");
		}
		int			output = rpn_expr_exec(expr, /* disallow_unary = */ true);
		std::cout << "'" << argv[1] << "' = " << output << std::endl;
	} catch (const std::exception& err) {
		std::cerr << "error: " << err.what() << std::endl;
	}
	rpn_expr_delete(expr);
	return (error ? RET_ERR_RUNTIME : RET_OK);
}
