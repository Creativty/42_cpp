/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 10:49:53 by aindjare          #+#    #+#             */
/*   Updated: 2025/11/25 13:47:17 by xenobas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP
#include <algorithm>

template <typename T>
typename T::iterator	easyfind(T& container, int to_find) {
	typename T::iterator	result = std::find(container.begin(), container.end(), to_find);
	if (result == container.end()) {
		throw std::runtime_error("Container does not contain queried value");
	}
	return (result);
}

#endif
