/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:31:57 by aindjare          #+#    #+#             */
/*   Updated: 2024/12/21 19:35:43 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Contact_HPP
#define Contact_HPP
#include <string>

class Contact {
	public:
		Contact();
		Contact(std::string first_name, std::string last_name,
			std::string nickname, std::string phone, std::string secret);
		Contact(const Contact &a);
		~Contact();
		Contact & operator = (const Contact &a);
	private:
		std::string	nickname, last_name, first_name, phone, secret;
};
#endif
