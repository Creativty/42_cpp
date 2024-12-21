/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:44:44 by aindjare          #+#    #+#             */
/*   Updated: 2024/12/21 19:51:02 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <string.h>

Contact::Contact() {
	nickname.clear();
	last_name.clear();
	first_name.clear();
	phone.clear();
	secret.clear();
}

Contact::Contact(std::string first_name, std::string last_name,
			std::string nickname, std::string phone, std::string secret)
 {
	this->nickname = nickname;
	this->last_name = last_name;
	this->first_name = first_name;
	this->phone = phone;
	this->secret = secret;
}

Contact::Contact(const Contact &contact) {
	nickname = contact.nickname;
	last_name = contact.last_name;
	first_name = contact.first_name;
	phone = contact.phone;
	secret = contact.secret;
}

Contact::~Contact() {
	nickname.clear();
	last_name.clear();
	first_name.clear();
	phone.clear();
	secret.clear();
}

Contact&	Contact::operator=(const Contact &contact) {
	if (this == &contact) {
		nickname = contact.nickname;
		last_name = contact.last_name;
		first_name = contact.first_name;
		phone = contact.phone;
		secret = contact.secret;
	}
	return (*this);
}
