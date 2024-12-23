/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aindjare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 14:10:39 by aindjare          #+#    #+#             */
/*   Updated: 2024/12/23 14:33:37 by aindjare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>

void	string_replace_all(std::string& str, std::string pattern, std::string substitution) {
	if (str.empty())
		return ;
	std::size_t	i = 0;
	for (; (i = str.find(pattern, i)) != std::string::npos;) {
		str.erase(i, pattern.length());
		str.insert(i, substitution);
		i += substitution.length();
	}
}

int	main(const int argc, const char **argv) {
	if (argc != 4) {
		std::cout << "sez is a recreation of sed for manipulating text streams" << std::endl;
		std::cout << "Usage:" << std::endl;
		std::cout << "\t" << argv[0] << " <filename> <pattern> <substitution>" << std::endl;
		return (1);
	}
	std::string		filename_in(argv[1]), pattern(argv[2]), substitution(argv[3]);
	std::string		filename_ext(".replace");
	std::string		filename_out(filename_in + filename_ext);

	if (pattern.empty()) {
		std::cout << "error: replacement pattern cannot be empty." << std::endl;
		return (2);
	}

	std::string		line;
	std::ifstream	file_in(filename_in.c_str());
	if (!file_in.is_open()) {
		std::cout << "error: file " << filename_in << " doesn't exist." << std::endl;
		return (4);
	}
	std::ofstream	file_out(filename_out.c_str());

	for (; getline(file_in, line); ) {
		string_replace_all(line, pattern, substitution);
		file_out << line << std::endl;
	}
	file_in.close();
	file_out.close();
	std::cout << "done writing output to " << filename_out << std::endl;
	return (0);
}
