/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 10:15:42 by aindjare          #+#    #+#             */
/*   Updated: 2025/11/01 10:22:32 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

template <typename T>
void	iter(T* arr, size_t len, void (*proc)(T&)) {
	if (arr == 0)
		return ;

	for (size_t i = 0; i < len; ++i) {
		proc(arr[i]);
	}
}

template <typename T>
void	iter(const T* arr, size_t len, void (*proc)(const T&)) {
	if (arr == 0 || proc == 0)
		return ;

	for (size_t i = 0; i < len; ++i) {
		proc(arr[i]);
	}
}

#endif
