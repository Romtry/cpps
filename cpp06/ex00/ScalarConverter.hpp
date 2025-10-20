# pragma once

#include <iostream>

class ScalarConverter
{
	public:
		static void convert(const std::string &str);

	private:
		static void print_err(const std::string &str, const int i);
		static void printer(const std::string &str, const bool is_num);
		ScalarConverter() {}
		~ScalarConverter() {}
};
