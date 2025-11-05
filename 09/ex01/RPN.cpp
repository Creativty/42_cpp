/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenobas <rahimos.123@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:36:16 by xenobas           #+#    #+#             */
/*   Updated: 2025/11/05 17:40:40 by xenobas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stdexcept>

static int		rpn_operator_proc_add(int a, int b) {
	return (a + b);
}
static int		rpn_operator_proc_sub(int a, int b) {
	return (a - b);
}
static int		rpn_operator_proc_mul(int a, int b) {
	return (a * b);
}
static int		rpn_operator_proc_div(int a, int b) {
	if (b == 0) {
		throw (std::runtime_error("attempted divsion by zero"));
	}
	return (a / b);
}

RPN_Operator	rpn_operator_match(char ch) {
	switch (ch) {
		case '+':
			return (RPN_OP_ADD);
		case '-':
			return (RPN_OP_SUB);
		case '*':
			return (RPN_OP_MUL);
		case '/':
			return (RPN_OP_DIV);
		default:
			return (RPN_OP_INVALID);
	}
}
RPN_Proc		rpn_operator_proc(RPN_Operator op) {
	switch (op) {
	case RPN_OP_ADD:
		return (rpn_operator_proc_add);
	case RPN_OP_SUB:
		return (rpn_operator_proc_sub);
	case RPN_OP_MUL:
		return (rpn_operator_proc_mul);
	case RPN_OP_DIV:
		return (rpn_operator_proc_div);
	case RPN_OP_COUNT:
	case RPN_OP_INVALID:
	default:
		return (0);
	}
}

RPN_Symbol		rpn_symbol_number(int number) {
	return ((RPN_Symbol){ .is_number = true, { .Number = number } });
}
RPN_Symbol		rpn_symbol_operator(RPN_Operator op) {
	return ((RPN_Symbol){ .is_number = false, { .Operator = op } });
}

void			rpn_expr_delete(RPN_Expr* expr) {
	if (expr == 0) {
		return ;
	}

	if (!expr->is_unary) {
		rpn_expr_delete(expr->Binary.left);
		rpn_expr_delete(expr->Binary.right);
	}
	delete expr;
}
RPN_Expr*		rpn_expr_parse(RPN_Stack& stack) {
	if (stack.empty()) {
		return (0);
	}

	RPN_Symbol	symbol = stack.top();
	stack.pop();

	if (symbol.is_number) { /* Number */
		RPN_Expr*	expr = new RPN_Expr;

		expr->is_unary = true;
		expr->Unary = symbol.Number;
		return (expr);
	} else { /* Operator */
		RPN_Expr*	expr = new RPN_Expr;

		expr->is_unary = false;

		expr->Binary.proc = rpn_operator_proc(symbol.Operator);
		expr->Binary.right = rpn_expr_parse(stack);
		expr->Binary.left = rpn_expr_parse(stack);
		return (expr);
	}
}
int				rpn_expr_exec(RPN_Expr* expr, bool disallow_unary) {
	if (expr->is_unary) {
		if (disallow_unary) {
			throw std::runtime_error("expected an operator got a number");
		}
		return (expr->Unary);
	} else {
		if (expr->Binary.left == 0 || expr->Binary.right == 0) {
			throw std::runtime_error("too few argument provided to operator");
		}
		int	left = rpn_expr_exec(expr->Binary.left);
		int	right = rpn_expr_exec(expr->Binary.right);
		return (expr->Binary.proc(left, right));
	}
}
