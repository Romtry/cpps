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
		if (!Is_LineShort(line, lineIndex))
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
	std::getline(fin, line);
	while (!fin.eof())
	{
		const unsigned int firstPart = 13;
		if (!Is_LineShort(line, lineIndex))
		{
			const std::string tmp = YELLOW "Line too short in " + argv + " " YELLOW1 "[" RESET RED + line + YELLOW1 "]" RESET YELLOW " line: " + To_string_cpp98(lineIndex) + RESET;
			std::cerr << tmp << std::endl;
			continue;
		}
		if (!ParseYear(line, lineIndex, argv))
		{
			const std::string tmp = YELLOW "Wrong year in " + argv + " " YELLOW1 "[" RESET RED + line + YELLOW1 "]" RESET YELLOW " line: " + To_string_cpp98(lineIndex) + RESET;
			std::cerr << tmp << std::endl;
			continue;
		}
		if (!Good_Sep(line, argv, " | ", lineIndex))
		{
			const std::string tmp = YELLOW "Wrong indentation in " + argv + " " YELLOW1 "[" RESET RED + line + YELLOW1 "]" RESET YELLOW " line: " + To_string_cpp98(lineIndex) + RESET;
			std::cerr << tmp << std::endl;
			continue;
		}
		if (!Possible_Month(line, argv, lineIndex))
		{
			const std::string tmp = YELLOW "Wrong indentation in " + argv + " " YELLOW1 "[" RESET RED + line + YELLOW1 "]" RESET YELLOW " line: " + To_string_cpp98(lineIndex) + RESET;
			std::cerr << tmp << std::endl;
			continue;
		}
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
		ParseValue(line.substr(firstPart, line.size() - firstPart), lineIndex);
		this->_file[line.substr(0, 10)] = strtold(line.substr(firstPart, line.size() - firstPart).c_str(), NULL);
		std::getline(fin, line);
	}
	Printer();
}

void BitcoinExchange::Printer()
{
	for (std::map<std::string, long double>::iterator itFile = _file.begin(); itFile != _file.end(); ++itFile)
	{
		for (std::map<std::string, long double>::iterator itData = _data.begin(); itData != _data.end(); ++itData)
		{
			if (itData->first.data() == itFile->first.data())
			{
				std::cout << itData->first.data() << " => " << itFile->second << " = " << itData->second * itFile->second << std::endl;
				break;
			}
		}
		std::map<std::string, long double>::iterator tmpit = _data.lower_bound(itFile->first);
		std::cout << itFile->first.data() << " not found closest date in Data.csv is " << tmpit->first.data() << " => " << itFile->second << " = " << tmpit->second * itFile->second << std::endl;
	}
}


bool	BitcoinExchange::Is_LineShort(const std::string &line, const unsigned int lineIndex)
{
	if (line.size() < 12)
	{
		const std::string tmp = YELLOW "Line too short in input file: " YELLOW1 "[" RESET RED + line + YELLOW1 "]" RESET YELLOW " line: " + To_string_cpp98(lineIndex) + RESET;
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
	// ? is february
	if (line.substr(5, 2) == "02")
	{
		// ? is leap year
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
	bool	virgule = false;
	for (unsigned int i = 0; value[i]; ++i)
	{
		if (std::isdigit(value[i]))
			continue;
		if (value[i] == '.')
		{
			if (i == 0 || virgule == true || i == value.size())
			{
				std::cout << value[i] << " at line: " << lineIndex << " index: " << i << " is not coherent" << std::endl;
				return (false);
			}
			virgule = true;
			continue;
		}
		if (value[i] == '-')
		{
			if (i != 0)
			{
				std::cout << "incoherent character: " << value[i] << std::endl;
				return (false);
			}
			continue;
		}
		std::cout << "incoherent character: " << value[i] << std::endl;
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





// void BitcoinExchange::Parser(std::fstream &fin, std::map<std::string, std::string> &map, const char *comp, const std::string &name)
// {
// 	std::string	line;
// 	std::getline(fin, line);
// 	unsigned int lineIndex = 1;
// 	const unsigned int firstPart = 10 + std::strlen(comp);
// 	while (!fin.eof())
// 	{
// 		++lineIndex;
// 		// ? good year
// 		ParseYear(line, lineIndex, name);
// 		// ? good syntaxe
// 		if (line[4] != '-' || line[7] != '-' || line.substr(10, std::strlen(comp)) != comp)
// 		{
// 			const std::string tmp = YELLOW "Invalid indentation in " + name + " " YELLOW1 "[" RESET RED + line + YELLOW1 "]" RESET YELLOW " !=" GREEN " YYYY-MM-DD" + comp + " " YELLOW " at line: "  + To_string_cpp98(lineIndex) + RESET;
// 			std::cerr << tmp << std::endl;
// 			std::getline(fin, line);
// 			continue;
// 		}
// 		// ? possible month
// 		if (!(line.substr(5, 2) >= "01" && line.substr(5, 2) <= "12"))
// 		{
// 			const std::string tmp = YELLOW "Impossible month in " + name + ": " RED + line.substr(5, 2) + YELLOW " line: " += To_string_cpp98(lineIndex) + RESET;
// 			std::cerr << tmp << std::endl;
// 			std::getline(fin, line);
// 			continue;
// 		}
// 		// ? is a 31 days month
// 		if ((atoi(line.substr(5, 2).c_str()) < 8
// 			&& (atoi(line.substr(5, 2).c_str()) % 2 == 1))
// 			|| ((atoi(line.substr(5, 2).c_str()) >= 8
// 			&& (atoi(line.substr(5, 2).c_str()) % 2 == 0))))
// 		{
// 			if (!(line.substr(8, 2) >= "01" && line.substr(8, 2) <= "31"))
// 			{
// 				const std::string tmp = YELLOW "Impossible day in " + name + ": " RED + line.substr(8, 2) + YELLOW " line: " += To_string_cpp98(lineIndex) + RESET;
// 				std::cerr << tmp << std::endl;
// 				std::getline(fin, line);
// 				continue;
// 			}
// 		}
// 		else
// 		{
// 			// ? is february
// 			if (line.substr(5, 2) == "02")
// 			{
// 				// ? is leap year
// 				const int year = atoi(line.substr(0, 4).c_str());
// 				if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
// 				{
// 					const int month = atoi(line.substr(8, 2).c_str());
// 					if (!((month >= 1 && month <= 29)))
// 					{
// 						const std::string tmp = YELLOW "Is impossible day in february leap year in " + name + ": " RED + line.substr(8, 2) + YELLOW " line: " += To_string_cpp98(lineIndex) + RESET;
// 						std::cerr << tmp << std::endl;
// 						std::getline(fin, line);
// 						continue;
// 					}
// 				}
// 				else
// 				{
// 					const int month = atoi(line.substr(8, 2).c_str());
// 					if (!((month >= 1 && month <= 28)))
// 					{
// 						const std::string tmp = YELLOW "Is impossible day in february in " + name + ": " RED + line.substr(8, 2) + YELLOW " line: " += To_string_cpp98(lineIndex) + RESET;
// 						std::cerr << tmp << std::endl;
// 						std::getline(fin, line);
// 						continue;
// 					}
// 				}
// 			}
// 			const int month = atoi(line.substr(8, 2).c_str());
// 			if (month < 1 || month > 30)
// 			{
// 				const std::string tmp = YELLOW "Is impossible day in 30 days month in " + name + ": " RED + line.substr(8, 2) + YELLOW " line: " += To_string_cpp98(lineIndex) + RESET;
// 				std::cerr << tmp << std::endl;
// 				std::getline(fin, line);
// 				continue;
// 			}
// 		}
// 		ParseValue(line.substr(firstPart, line.size() - firstPart));
// 		map[line.substr(0, 10)] = line.substr(firstPart, line.size() - firstPart).c_str();
// 		std::getline(fin, line);
// 	}
// }





