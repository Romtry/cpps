//
// Created by rothiery on 10/17/25.
//

#pragma once

#include <iostream>
#include <exception>
#include <fstream>
#include <cstdlib>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &original);
		BitcoinExchange(char *argv);
		~BitcoinExchange();
		BitcoinExchange	&operator=(const BitcoinExchange &original);

		class DataError : public std::exception
		{
		public:
			virtual const char	*what() const throw();
		};
		class ParsError : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};