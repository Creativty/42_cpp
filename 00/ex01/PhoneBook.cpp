/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:27:57 by aindjare          #+#    #+#             */
/*   Updated: 2024/12/23 13:39:39 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	for (int i = 0; i < 8; i++)
		slots[i] = Contact();
	cursor = 0;
}

int	PhoneBook::addContact(Contact &contact) {
	int	_cursor = cursor;
	slots[_cursor] = contact;
	cursor = (_cursor + 1) % 8;
	return (_cursor);
}

Contact	PhoneBook::getContact(int index) {
	if (index < 0 || index >= 8)
		return (Contact());
	return (this->slots[index]);
}
