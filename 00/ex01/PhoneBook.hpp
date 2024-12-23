/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:25:35 by aindjare          #+#    #+#             */
/*   Updated: 2024/12/23 09:52:31 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP
#include "Contact.hpp"
#include <iostream>

class PhoneBook {
	public:
		PhoneBook ();
		PhoneBook (const PhoneBook &a);
		~PhoneBook ();
		PhoneBook & operator = (const PhoneBook &a);
		
		Contact	getContact(int index);
		int		addContact(Contact &contact);
	private:
		Contact	slots[8];
		int		cursor;
};
#endif
