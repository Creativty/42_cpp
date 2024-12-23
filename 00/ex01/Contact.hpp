/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:31:57 by aindjare          #+#    #+#             */
/*   Updated: 2024/12/23 13:38:13 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Contact_HPP
#define Contact_HPP
#include <string>
#include <iostream>

class Contact {
	public:
		Contact();
		Contact(std::string first_name, std::string last_name,
			std::string nickname, std::string phone,
			std::string secret);
	public:
		std::string	first_name, last_name, nickname, phone, secret;
		bool		is_visible;
};
#endif
