//
// Created by rothiery on 10/17/25.
//

#include "BitcoinExchange.hpp"

static bool	parseYear(std::string &year)
{
	for (unsigned int i = 0; year[i]; ++i)
	{
		if (!std::isdigit(year[i]))
			return (false);
	}
}

BitcoinExchange::BitcoinExchange(char *argv)
{
	std::fstream fin;
	fin.open(argv, std::ios::in);
	if (fin.eof())
		throw DataError();
	std::string	line;
	//skip 1st line
	std::getline(fin, line);
	if (line != "date,exchange_rate")
		throw DataError();
	std::getline(fin, line);
	while (!fin.eof())
	{
		if (line.size() < 12)
			throw DataError();
		// std::cout << "YEAR = " << line.substr(0, 4) << std::endl;
		//good year
		if (parseYear(line.substr(0,4)))
			throw DataError();
		// std::cout << "SYNTAXE = " << line[4] << " and " << line[7] << " and " << line[10] << std::endl;
		//good syntaxe
		if (line[4] != '-' || line[7] != '-' || line[10] != ',')
			throw DataError();
		// std::cout << "mounth = " << line.substr(5, 2) << std::endl;
		//possible mounth
		if (!(line.substr(5, 2) >= "00" && line.substr(5, 2) <= "12"))
			throw DataError();
		//is a 31 days mounth
		if ((atoi(line.substr(5, 2).c_str()) < 8
			&& (atoi(line.substr(5, 2).c_str()) % 2 == 1))
			|| ((atoi(line.substr(5, 2).c_str()) >= 8
			&& (atoi(line.substr(5, 2).c_str()) % 2 == 0))))
		{
			if (!(line.substr(8, 2) >= "00" && line.substr(8, 2) <= "31"))
				throw DataError();
		}
		else
		{

			//is february
			if (line.substr(5, 2) == "02")
			{
				//is leap year
				if ((atoi(line.substr(0, 4).c_str()) % 4 == 0
					&& atoi(line.substr(0, 4).c_str()) % 100 != 0)
					|| atoi(line.substr(0, 4).c_str()) % 400 == 0)
				{
					if (!((line.substr(8, 2) >= "00" && line.substr(8, 2) <= "29")))
						throw DataError();
				}
				else
				{
					if (!((line.substr(8, 2) >= "00" && line.substr(8, 2) <= "28")))
						throw DataError();
				}

			}
			if (!(line.substr(8, 2) >= "00" && line.substr(8, 2) <= "30"))
				throw DataError();
		}
		std::getline(fin, line);
	}
}

const char *BitcoinExchange::DataError::what() const throw()
{
	return ("Wrong data.csv");
}

const char *BitcoinExchange::ParsError::what() const throw()
{
	return ("Parsing Error");
}

BitcoinExchange::BitcoinExchange()
{

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
