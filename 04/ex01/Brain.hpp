/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 13:52:42 by aindjare          #+#    #+#             */
/*   Updated: 2025/01/01 14:00:51 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Brain_hpp
#define Brain_hpp
class Brain {
public:
	Brain();
	Brain(const Brain& o);
	~Brain();

	Brain&	operator=(const Brain& o);
public:
	std::string	ideas[100];
};
#endif
