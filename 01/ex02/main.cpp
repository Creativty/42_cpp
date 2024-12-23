/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:26:20 by aindjare          #+#    #+#             */
/*   Updated: 2024/12/23 13:29:56 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void) {
	std::string		str("HI THIS IS BRAIN");
	std::string		*str_ptr = &str;
	std::string&	str_ref(str);

	std::cout << "Memory address of str    : " << &str << std::endl;
	std::cout << "Memory address of str_ptr: " << &str_ptr << std::endl;
	std::cout << "Memory address of str_ref: " << &str_ref << std::endl;

	std::cout << "----" << std::endl;

	std::cout << "Value of str    : " <<  str << std::endl;
	std::cout << "Value of str_ptr: " << *str_ptr << std::endl;
	std::cout << "Value of str_ref: " <<  str_ref << std::endl;
	return (0);
}
