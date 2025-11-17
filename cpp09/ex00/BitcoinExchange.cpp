//
// Created by rothiery on 10/17/25.
//

#include "defines.hpp"
#include "BitcoinExchange.hpp"
#include <cstring>

void BitcoinExchange::Init()
{
	std::fstream fin;
	fin.open("data.csv", std::ios::in);
	if (fin.eof())
		throw std::invalid_argument(YELLOW "Empty data" RESET);
	std::string	line;
	std::getline(fin, line);
	if (line != "date,exchange_rate")
		throw std::invalid_argument(YELLOW "Wrong 1st line in data != " GREEN "date,exchange_rate" RESET);
	unsigned int	lineIndex = 1;
	std::getline(fin, line);
	if (!line.data())
		throw std::invalid_argument(YELLOW "No content in Data.csv" RESET);
	while (!fin.eof())
	{
		const unsigned int firstPart = 11;
		if (!Is_LineShort(line, lineIndex, "Data.csv"))
		{
			const std::string tmp = YELLOW "Line too short in data.csv: " YELLOW1 "[" RESET RED + line + YELLOW1 "]" RESET YELLOW " line: " + To_string_cpp98(lineIndex) + RESET;
			throw std::invalid_argument(tmp);
		}
		if (!ParseYear(line, lineIndex, "data.csv"))
		{
			const std::string tmp = YELLOW "Wrong year in data.csv: " YELLOW1 "[" RESET RED + line + YELLOW1 "]" RESET YELLOW " line: " + To_string_cpp98(lineIndex) + RESET;
			throw std::invalid_argument(tmp);
		}
		if (!Good_Sep(line, "data.csv", ",", lineIndex))
		{
			const std::string tmp = YELLOW "Wrong indentation in data.csv: " YELLOW1 "[" RESET RED + line + YELLOW1 "]" RESET YELLOW " line: " + To_string_cpp98(lineIndex) + RESET;
			throw std::invalid_argument(tmp);
		}
		if (!Possible_Month(line, "data.csv", lineIndex))
		{
			const std::string tmp = YELLOW "Wrong indentation in data.csv: " YELLOW1 "[" RESET RED + line + YELLOW1 "]" RESET YELLOW " line: " + To_string_cpp98(lineIndex) + RESET;
			throw std::invalid_argument(tmp);
		}
		if ((atoi(line.substr(5, 2).c_str()) < 8
			&& (atoi(line.substr(5, 2).c_str()) % 2 == 1))
			|| ((atoi(line.substr(5, 2).c_str()) >= 8
			&& (atoi(line.substr(5, 2).c_str()) % 2 == 0))))
		{
			if (!(line.substr(8, 2) >= "01" && line.substr(8, 2) <= "31"))
			{
				const std::string tmp = YELLOW "Impossible day in Data.csv: " RED + line.substr(8, 2) + YELLOW " line: " += To_string_cpp98(lineIndex) + RESET;
				throw std::invalid_argument(tmp);
			}
			++lineIndex;
		}
		else
		{
			std::string tmp = Possible_Day(line, "Data.csv", lineIndex);
			if (tmp != "ok")
				throw std::invalid_argument(tmp);
		}
		ParseValue(line.substr(firstPart, line.size() - firstPart), lineIndex);
		this->_data[line.substr(0, 10)] = strtold(line.substr(firstPart, line.size() - firstPart).c_str(), NULL);
		std::getline(fin, line);
	}
}

void BitcoinExchange::Exec(const std::string &argv)
{
	std::fstream fin;
	fin.open(argv.c_str(), std::ios::in);
	if (fin.eof())
		throw std::invalid_argument(YELLOW "Empty " + argv + RESET);
	std::string	line;
	std::getline(fin, line);
	if (line != "date | value")
		throw std::invalid_argument(YELLOW "Wrong 1st line in " + argv + " != " GREEN "date | value" RESET);
	unsigned int	lineIndex = 1;
	while (std::getline(fin, line))
	{
		const unsigned int firstPart = 13;
		if (!Is_LineShort(line, lineIndex, argv) || !ParseYear(line, lineIndex, argv)
			|| !Good_Sep(line, argv, " | ", lineIndex) || !Possible_Month(line, argv, lineIndex))
			continue;
		if ((atoi(line.substr(5, 2).c_str()) < 8
			&& (atoi(line.substr(5, 2).c_str()) % 2 == 1))
			|| ((atoi(line.substr(5, 2).c_str()) >= 8
			&& (atoi(line.substr(5, 2).c_str()) % 2 == 0))))
		{
			if (!(line.substr(8, 2) >= "01" && line.substr(8, 2) <= "31"))
			{
				const std::string tmp = YELLOW "Impossible day in " + argv + ": " RED + line.substr(8, 2) + YELLOW " line: " += To_string_cpp98(lineIndex) + RESET;
				std::cerr << tmp << std::endl;
				continue;
			}
			++lineIndex;
		}
		else
		{
			std::string tmp = Possible_Day(line, argv, lineIndex);
			if (tmp != "ok")
			{
				std::cerr << tmp << std::endl;
				continue;
			}
		}
		if (!ParseValue(line.substr(firstPart, line.size() - firstPart), lineIndex))
			continue;
		Printer(line.substr(0, 10), strtold(line.substr(firstPart, line.size() - firstPart).c_str(), NULL));
	}
}

void BitcoinExchange::Printer(const std::string &date, const long double &value)
{
	if (value > 1000)
	{
		std::cout << YELLOW "Limit reached : " YELLOW1 "[" RESET RED << value << YELLOW1 "]" RESET YELLOW " >1000" RESET << std::endl;
		return;
	}
	for (std::map<std::string, long double>::iterator itData = _data.begin(); itData != _data.end(); ++itData)
	{
		if (itData->first.data() == date)
		{
			std::cout << GREEN << itData->first.data() << RESET " => " GREEN << value << RESET " = " GREEN << itData->second * value << RESET << std::endl;
			return;
		}
	}
	std::map<std::string, long double>::iterator tmpit = _data.lower_bound(date);
	std::cout << YELLOW << date << " not found closest date in Data.csv is " GREEN << tmpit->first.data() << RESET " => " GREEN << value << RESET " = " GREEN << tmpit->second * value << RESET << std::endl;
}


bool	BitcoinExchange::Is_LineShort(const std::string &line, const unsigned int lineIndex, const std::string &argv)
{
	if (line.size() < 12)
	{
		const std::string tmp = YELLOW "Line too short in " + argv + " file: " YELLOW1 "[" RESET RED + line + YELLOW1 "]" RESET YELLOW " line: " + To_string_cpp98(lineIndex) + RESET;
		std::cerr << tmp << std::endl;
		return (false);
	}
	return (true);
}

bool	BitcoinExchange::ParseYear(const std::string &line, const unsigned int lineIndex, const std::string &name)
{
	unsigned int i = 0;
	while (std::isdigit(line[i]))
		++i;
	if (i != 4)
	{
		std::string tmp;
		if (i < 4)
			tmp += YELLOW "Year is less than 4 digits in " + name + ": " YELLOW1 "[" RESET RED + line.substr(0, i) + YELLOW1 "]" RESET YELLOW " at line: " + To_string_cpp98(lineIndex) + RESET;
		if (i > 4)
			tmp += YELLOW "Year is more than 4 digits in " + name + ": " YELLOW1 "[" RESET RED  + line.substr(0, i) + YELLOW1 "]" RESET YELLOW " at line: " + To_string_cpp98(lineIndex) + RESET;
		std::cerr << tmp << std::endl;
		return (false);
	}
	return (true);
}

bool	BitcoinExchange::Good_Sep(const std::string &line, const std::string &name, const char *comp, const unsigned int lineIndex)
{
	if (line[4] != '-' || line[7] != '-' || line.substr(10, std::strlen(comp)) != comp)
	{
		const std::string tmp = YELLOW "Invalid indentation in " + name + " " YELLOW1 "[" RESET RED + line + YELLOW1 "]" RESET YELLOW " !=" GREEN " YYYY-MM-DD" + comp + " " YELLOW " at line: "  + To_string_cpp98(lineIndex) + RESET;
		std::cerr << tmp << std::endl;
		return (false);
	}
	return (true);
}

bool	BitcoinExchange::Possible_Month(const std::string &line, const std::string &name, const unsigned int lineIndex)
{
	if (!(line.substr(5, 2) >= "01" && line.substr(5, 2) <= "12"))
	{
		const std::string tmp = YELLOW "Impossible month in " + name + ": " RED + line.substr(5, 2) + YELLOW " line: " += To_string_cpp98(lineIndex) + RESET;
		std::cerr << tmp << std::endl;
		return (false);
	}
	return (true);
}

std::string	BitcoinExchange::Possible_Day(const std::string &line, const std::string &name, const unsigned int lineIndex)
{
	if (line.substr(5, 2) == "02")
	{
		const int year = atoi(line.substr(0, 4).c_str());
		if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
		{
			const int month = atoi(line.substr(8, 2).c_str());
			if (!((month >= 1 && month <= 29)))
			{
				const std::string tmp = YELLOW "Is impossible day in february leap year in " + name + ": " RED + line.substr(8, 2) + YELLOW " line: " += To_string_cpp98(lineIndex) + RESET;
				std::cerr << tmp << std::endl;
				return (tmp);
			}
		}
		else
		{
			const int month = atoi(line.substr(8, 2).c_str());
			if (!((month >= 1 && month <= 28)))
			{
				const std::string tmp = YELLOW "Is impossible day in february in " + name + ": " RED + line.substr(8, 2) + YELLOW " line: " += To_string_cpp98(lineIndex) + RESET;
				std::cerr << tmp << std::endl;
				return (tmp);
			}
		}
	}
	const int month = atoi(line.substr(8, 2).c_str());
	if (month < 1 || month > 30)
	{
		const std::string tmp = YELLOW "Is impossible day in 30 days month in " + name + ": " RED + line.substr(8, 2) + YELLOW " line: " += To_string_cpp98(lineIndex) + RESET;
		std::cerr << tmp << std::endl;
		return (tmp);
	}
	return ("ok");
}

bool BitcoinExchange::ParseValue(const std::string &value, const unsigned int lineIndex)
{
	bool	comma = false;
	for (unsigned int i = 0; value[i]; ++i)
	{
		if (std::isdigit(value[i]))
			continue;
		if (value[i] == '.')
		{
			if (i == 0 || comma == true || i == value.size())
			{
				std::cout << YELLOW << value[i] << " at line: " << lineIndex << " index: " << i << " is not coherent" << std::endl;
				return (false);
			}
			comma = true;
			continue;
		}
		std::cout << YELLOW "incoherent character: " YELLOW1 "[" RESET RED << value[i] << YELLOW1 "]" RESET << std::endl;
		return (false);
	}
	return (true);
}

BitcoinExchange::BitcoinExchange()
{

}

std::string BitcoinExchange::To_string_cpp98(const int value)
{
	std::ostringstream oss;
	oss << value;
	return oss.str();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &original)
{
	(void)original;
}

BitcoinExchange::~BitcoinExchange()
{

}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &original)
{
	(void)original;
	return (*this);
}



