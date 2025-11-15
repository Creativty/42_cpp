/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenobas <rahimos.123@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 12:49:11 by xenobas           #+#    #+#             */
/*   Updated: 2025/11/15 13:04:06 by xenobas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef   BASE_HPP
#define   BASE_HPP
class Base {
public:
	virtual ~Base(void);

	virtual void	declare(void) const = 0;
};

class A: public Base {
public:
	~A(void);

	void	declare(void) const;
};
class B: public Base {
public:
	~B(void);

	void	declare(void) const;
};
class C: public Base {
public:
	~C(void);

	void	declare(void) const;
};

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);
#endif /* BASE_HPP */
