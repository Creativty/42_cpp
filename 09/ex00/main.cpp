/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xenobas <rahimos.123@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:03:58 by xenobas           #+#    #+#             */
/*   Updated: 2025/11/05 16:32:23 by xenobas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define cast(X) (X)

#define RET_OK				0
#define RET_ERR_ARGC		1
#define RET_ERR_OPEN		2
#define RET_ERR_VALIDATION	4
#define RET_ERR_CSV			8

#include <list>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <cerrno>
#include <cstring>

typedef struct Date	Date;
struct Date {
	int		year;
	int		month;
	int		day;

	bool	ok;
};

bool	char_match_digit(char ch) {
	return (ch >= '0' && ch <= '9');
}

int		string_count(const std::string& str, char ch) {
	int	count = 0;
	for (size_t i = 0; i < str.size(); ++i) {
		if (str[i] == ch) {
			++count;
		}
	}
	return (count);
}

double	string_double(const std::string& str, double fallback = 0.0) {
	std::istringstream	stream(str);
	double				value = fallback;

	stream >> value;
	return ((stream.bad() || !stream.eof()) ? fallback : value);
}

int		string_int(const std::string& str, int fallback = 0) {
	std::istringstream	stream(str);
	int					value = fallback;

	stream >> value;
	return ((stream.bad() || !stream.eof()) ? fallback : value);
}

Date	string_date_nil(void) {
	return ((Date){ 0, 0, 0, true });
}

Date	string_date_fail(void) {
	return ((Date){ 0, 0, 0, false });
}

Date	string_date(const std::string& str) {
	std::string				tmp;
	std::string				sep = "-";
	std::string				rem = str;
	Date					date = string_date_nil();

	if (string_count(rem, '-') != 2) {
		return (string_date_fail());
	}

	std::string::size_type	sep_idx;

	sep_idx = rem.find(sep);
	tmp = rem.substr(0, sep_idx);
	rem = rem.substr(sep_idx + sep.size());

	date.year = string_int(tmp, -1);
	if (date.year <= -1) {
		return (string_date_fail());
	}

	sep_idx = rem.find(sep);
	tmp = rem.substr(0, sep_idx);
	rem = rem.substr(sep_idx + sep.size());

	date.month = string_int(tmp);
	if (date.month < 1 || date.month > 12) {
		return (string_date_fail());
	}

	date.day = string_int(rem);
	if (date.day < 1 || date.day > 31) {
		return (string_date_fail());
	}
	return (date);
}

int	month_days(int year, int month) {
	int	leap = (year % 4 == 0 && year % 100 == 0 && year % 400 == 0);
	switch (month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 9:
		case 11:
			return (30);
		case 4:
		case 6:
		case 8:
		case 10:
		case 12:
			return (31);
		case 2:
			return (28 + leap);
		default:
			return (0);
	}
}

int	date_days(const Date& date) {
	if (!date.ok) {
		return (-1);
	}

	int	days = 0;
	days += date.day;
	days += cast(int)(cast(double)date.year * 365.25);
	days += month_days(date.year, date.month);
	return (days);
}

struct CSV_Entry {
	double		rate;

	std::string	date;
	int			days;
};

typedef std::list<CSV_Entry>::const_iterator CSV_iterator;

double	csv_find_rate(const std::list<CSV_Entry>& csv, const Date& date) {
	int	days = date_days(date);

	CSV_iterator lower_bound = csv.end();
	for (CSV_iterator iter = csv.begin(); iter != csv.end(); ++iter) { /* As naive as it gets */
		const CSV_Entry&	entry = *iter;
		if (entry.days > days) {
			break ;
		}
		lower_bound = iter;
	}
	return (lower_bound == csv.end() ? 0.0 : lower_bound->rate);
}

int		main(int argc, const char** argv) {
	if (argc != 2) {
		std::cerr << "usage: " << argv[0] << " <file>" << std::endl;
		return (RET_ERR_ARGC);
	}

	std::list<CSV_Entry>	vec_csv;

	const char*				path_csv = "data.csv";
	std::ifstream			file_csv(path_csv);
	if (!file_csv.is_open()) {
		std::cerr << "error: could not read essential file " << path_csv << std::endl;
		std::cerr << "    reason: " << std::strerror(errno) << std::endl;
		std::cerr << "    suggestion: " << "please put the required file " << path_csv << " next in the current working directory" << std::endl;
		return (RET_ERR_OPEN);
	}

	std::string				line_csv;
	size_t					line_csv_index = 0;
	while (std::getline(file_csv, line_csv)) {
		if (line_csv == "date,exchange_rate" && line_csv_index == 0) {
			continue ;
		}
		std::string				sep = ",";
		std::string::size_type	sep_idx = line_csv.find(sep);

		std::string				str_date = line_csv.substr(0, sep_idx);
		std::string				str_rate = line_csv.substr(sep_idx + sep.size());

		Date					date = string_date(str_date);
		if (!date.ok) {
			std::cerr << "error: invalid csv entry `date` value" << std::endl;
			std::cerr << "    line: " << line_csv_index << std::endl;
			return (RET_ERR_CSV);
		}

		double	rate = string_double(str_rate, -1.0);
		if (rate == -1.0) {
			std::cerr << "error: invalid csv entry `exchange_rate` value" << std::endl;
			std::cerr << "    line: " << line_csv_index << std::endl;
			return (RET_ERR_CSV);
		}

		CSV_Entry entry = { rate, str_date, date_days(date) };
		vec_csv.push_back(entry);

		++line_csv_index;
	}
	if (vec_csv.size() == 0) {
		std::cerr << "error: csv file must contain at least one entry" << std::endl;
		return (RET_ERR_CSV);
	}

	std::ifstream	file_in(argv[1]);
	if (!file_in.is_open()) {
		std::cerr << "error: could not read file " << argv[1] << std::endl;
		std::cerr << "    reason: " << std::strerror(errno) << std::endl;
		return (RET_ERR_OPEN);
	}

	std::string		line_in;
	while (std::getline(file_in, line_in)) {
		std::string				sep = " | ";
		std::string::size_type	sep_idx = line_in.find(sep);
		if (sep_idx == std::string::npos) {
			std::cerr << "error: bad line: " << line_in << std::endl;
			continue ;
		}

		std::string	str_date = line_in.substr(0, sep_idx);
		Date			date = string_date(str_date);
		if (!date.ok) {
			std::cerr << "error: bad date: " << str_date << std::endl;
			continue ;
		}

		std::string	str_value = line_in.substr(sep_idx + sep.size());
		double		value = string_double(str_value, /* fallback = */ -1.0);
		if (value < 0.0 || value > 1000.0) {
			std::cerr << "error: bad value: " << str_value << std::endl;
			continue ;
		}

		double		price = csv_find_rate(vec_csv, date) * value;
		std::cout << str_date << ": " << price << std::endl;
	}
	
	return (RET_OK);
}
