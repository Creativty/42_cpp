/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 10:11:09 by aindjare          #+#    #+#             */
/*   Updated: 2025/11/01 10:13:25 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_HPP
#define MATH_HPP

template <typename T>
void	swap(T& a, T& b) {
	T	t = a;

	a = b;
	b = t;
}

template <typename T>
T	min(const T& a, const T& b) {
	return (a < b ? a : b);
}

template <typename T>
T	max(const T& a, const T& b) {
	return (a > b ? a : b);
}

#endif
