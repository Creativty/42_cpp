/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:44:44 by aindjare          #+#    #+#             */
/*   Updated: 2024/12/23 13:38:40 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {
	this->is_visible = false;
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
