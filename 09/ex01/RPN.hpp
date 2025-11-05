/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenobas <rahimos.123@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:34:38 by xenobas           #+#    #+#             */
/*   Updated: 2025/11/05 17:37:14 by xenobas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP
#include <stack>

enum RPN_Operator {
	RPN_OP_INVALID,

	RPN_OP_ADD,
	RPN_OP_SUB,
	RPN_OP_MUL,
	RPN_OP_DIV,

	RPN_OP_COUNT,
};

RPN_Operator	rpn_operator_match(char ch);

typedef struct RPN_Symbol RPN_Symbol;
struct RPN_Symbol {
	bool	is_number;
	union {
		int				Number;
		RPN_Operator	Operator;
	};
};

RPN_Symbol		rpn_symbol_number(int number);
RPN_Symbol		rpn_symbol_operator(RPN_Operator op);

typedef int				(*RPN_Proc)(int, int);

typedef struct RPN_Expr	RPN_Expr;
struct RPN_Expr {
	bool	is_unary;
	union {
		int	Unary;
		struct {
			RPN_Proc		proc;
			RPN_Expr*		left;
			RPN_Expr*		right;
		}	Binary;
	};
};

typedef std::stack<RPN_Symbol>	RPN_Stack;

void			rpn_expr_delete(RPN_Expr* expr);
RPN_Expr*		rpn_expr_parse(RPN_Stack& stack);
int				rpn_expr_exec(RPN_Expr* expr, bool disallow_unary = false);

#endif
