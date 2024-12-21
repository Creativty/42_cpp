/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   book.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 19:15:39 by aindjare          #+#    #+#             */
/*   Updated: 2024/12/21 19:56:26 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>

std::string	ask(const char *prompt) { // TODO(XENOBAS): Fix empty line error.
	std::string answer;

	if (std::cin.eof() == false) {
		std::cout << "\t" << prompt << "\t";
		std::getline(std::cin, answer);
		std::cout << std::endl;
		std::cout << "Answer: " << answer << std::endl;
	}
	return (answer);
}

void	book_add(PhoneBook &book) {
	std::string first_name = ask("First name: "), last_name = ask("Last name: ");
	std::string nickname = ask("Nickname: "), phone = ask("Phone number: ");
	std::string secret = ask("Secret (Your darkest one!): ");
	Contact		contact(first_name, last_name, nickname, phone, secret);
	(void)book;
}

void	book_search(PhoneBook &book) {
	(void)book;
}

int	main(void) {
	PhoneBook	book;
	bool		run = true;
	while (run) {
		// Read input
		std::string  cmd;
		std::cout << "$> ";
		std::getline(std::cin, cmd);

		if (cmd == "ADD") book_add(book);
		if (cmd == "SEARCH") book_search(book);
		run = !(cmd == "EXIT" || std::cin.eof() == true);
		if (std::cin.eof() == true)
			std::cout << std::endl;
	}
	return (0);
}
