//
// Created by rothiery on 10/17/25.
//

#pragma once

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>
#include <sstream>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &original);
		~BitcoinExchange();

		BitcoinExchange	&operator=(const BitcoinExchange &original);

		void			Init();
		void			Exec(const std::string &argv);

		void				Printer(const std::string &date, const long double &value);

		static bool			Is_LineShort(const std::string &line, unsigned int lineIndex, const std::string &argv);
		static bool			ParseYear(const std::string &year, unsigned int line, const std::string &name);
		static bool			Good_Sep(const std::string &line, const std::string &name, const char *comp, unsigned int lineIndex);
		static bool			Possible_Month(const std::string &line, const std::string &name, unsigned int lineIndex);
		static std::string	Possible_Day(const std::string &line, const std::string &name, unsigned int lineIndex);
		bool				ParseValue(const std::string &value, unsigned int lineIndex);

		static std::string	To_string_cpp98(const int value);

	private:
		std::map<std::string, long double>	_data;
};
