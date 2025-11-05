/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 14:07:35 by aindjare          #+#    #+#             */
/*   Updated: 2025/11/02 16:33:22 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include <stack>
#define DS_STACK
#ifdef DS_STACK
#include "MutantStack.hpp"
#define DS MutantStack<int>
#define DS_PUSH(X, Y) (X).push((Y))
#define DS_POP(X) (X).pop()
#define DS_TOP(X) (X).top()
#else
#include <list>
#define DS std::list<int>
#define DS_PUSH(X, Y) (X).push_back((Y))
#define DS_POP(X) (X).pop_back()
#define DS_TOP(X) (X).back()
#endif

int	main(void) {
	DS mstack;

	DS_PUSH(mstack,  5);
	DS_PUSH(mstack, 17);
	std::cout << "Top:  " << DS_TOP(mstack) << std::endl;

	DS_POP(mstack);
	std::cout << "Size: " << mstack.size() << std::endl;

	DS_PUSH(mstack,   3);
	DS_PUSH(mstack,   5);
	DS_PUSH(mstack, 737);
	DS_PUSH(mstack,   0);

	DS::iterator it = mstack.begin();
	DS::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	#ifdef DS_STACK
	std::stack<int> s(mstack);
	#endif
	return 0;
}
