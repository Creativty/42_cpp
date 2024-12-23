/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:44:44 by aindjare          #+#    #+#             */
/*   Updated: 2024/12/23 10:03:10 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {
	this->is_visible = false;
}

Contact::~Contact() {
}

Contact::Contact(std::string first_name, std::string last_name,
			std::string nickname, std::string phone, std::string secret)
 {
	this->phone = phone;
	this->secret = secret;
	this->nickname = nickname;
	this->last_name = last_name;
	this->first_name = first_name;
	this->is_visible = true;
}

Contact::Contact(const Contact &contact) {
	*this = contact;
}

Contact&	Contact::operator=(const Contact &contact) {
	if (this != &contact) {
		this->phone = contact.phone;
		this->secret = contact.secret;
		this->nickname = contact.nickname;
		this->last_name = contact.last_name;
		this->first_name = contact.first_name;
		this->is_visible = contact.is_visible;
	}
	return (*this);
}
