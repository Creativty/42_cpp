/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   book.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:15:39 by aindjare          #+#    #+#             */
/*   Updated: 2024/12/23 10:42:11 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

std::string ask(const char *prompt, bool is_retry = false) {
	std::string answer;

	if (!std::cin.eof()) {
		std::cout << "  " << prompt;
		if (is_retry)
			std::cout << " [retry]";
		std::cout <<  ": ";
		std::getline(std::cin, answer);
		if (answer.length() == 0)
			return (ask(prompt, true));
	}
	return (answer);
}

void	book_add(PhoneBook &book) {
	std::string first_name = ask("- First name"), last_name = ask("- Last name");
	std::string nickname = ask("- Nickname"), phone = ask("- Phone number");
	std::string secret = ask("- Secret (Your darkest one!)");
	Contact		contact(first_name, last_name, nickname, phone, secret);
	if (!std::cin.eof()) {
		int index = book.addContact(contact);
		std::cout << "  << added contact to slot " << index << std::endl;
	}
}

void	book_contact_print(int i, Contact &c) {
	std::cout << std::setiosflags(std::ios_base::right) << std::setw(10) << i << "|";

	std::string first_name(c.first_name.substr(0, 10));
	if (first_name.length() >= 10) first_name[9] = '.';
	std::cout << std::setiosflags(std::ios_base::right) << std::setw(10) << first_name << "|";

	std::string	last_name(c.last_name.substr(0, 10));
	if (last_name.length() >= 10) last_name[9] = '.';
	std::cout << std::setiosflags(std::ios_base::right) << std::setw(10) << last_name << "|";

	std::string	nickname(c.nickname.substr(0, 10));
	if (nickname.length() >= 10) nickname[9] = '.';
	std::cout << std::setiosflags(std::ios_base::right) << std::setw(10) << nickname << "|" << std::endl;
}

void	book_contact_print_header(void) {
	std::cout << std::setiosflags(std::ios_base::right) << std::setw(10) << "Index" << "|";
	std::cout << std::setiosflags(std::ios_base::right) << std::setw(10) << "F. Name" << "|";
	std::cout << std::setiosflags(std::ios_base::right) << std::setw(10) << "L. Name" << "|";
	std::cout << std::setiosflags(std::ios_base::right) << std::setw(10) << "Nickname" << "|" << std::endl;
}

void	book_search(PhoneBook &book) {
	book_contact_print_header();
	for (int i = 0; i < 8; i++) {
		Contact	c = book.getContact(i);
		if (!c.is_visible)
			continue ;
		book_contact_print(i, c);
	}
	bool				is_digits = true;
	std::string			str = ask(">> Contact index");
	if (std::cin.eof())
		return ;
	for (size_t i = 0; is_digits && i < str.length(); i++)
		is_digits = (str[i] >= '0' && str[i] <= '9');
	if (!is_digits) {
		std::cout << "  << invalid index format; only digits are allowed." << std::endl;
		return ;
	}
	std::stringstream	stream(str);
	int					idx = 0;
	stream >> idx;
	Contact				c = book.getContact(idx);
	if (c.is_visible) {
		std::cout << "    > First name: " << c.first_name << std::endl;
		std::cout << "    > Last name: " << c.last_name << std::endl;
		std::cout << "    > Nickname: " << c.nickname << std::endl;
		std::cout << "    > Phone number: " << c.phone << std::endl;
		std::cout << "    > Your darkest secret: " << c.secret << std::endl;
	} else {
		std::cout << "  > there is no contact at index " << idx << std::endl;
	}
}

int	main(void) {
	PhoneBook	book;
	bool		run = true;
	while (run) {
		std::string  cmd;
		std::cout << ">> ";
		std::getline(std::cin, cmd);

		if (cmd == "ADD") book_add(book);
		if (cmd == "SEARCH") book_search(book);
		run = !(cmd == "EXIT" || std::cin.eof() == true);
		if (std::cin.eof())
			std::cout << std::endl;
	}
	return (0);
}
