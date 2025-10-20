#include "ScalarConverter.hpp"

# include <cmath>
# include <iostream>
# include <cstdlib>
# include <iomanip>
# include <cstring>
#include <limits.h>

void	ScalarConverter::print_err(const std::string &str, const int i)
{
	std::cout << "error in " << str << " at index " << i << " " << str[i] << std::endl;
}

void ScalarConverter::printer(const std::string &str, const bool is_num)
{
	char *end;
	const double d = std::atof(str.c_str());
	const float f = d;
	bool b = true;
	int i = 0;
	std::cout << str << ":" << std::endl;
	const long long l = std::strtol(str.substr(0, str.find('.')).c_str(), &end, 10);
	if (str.length() > 15 || l >= INT_MAX || l <= INT_MIN)
		b = false;
	else
		i = atoi(str.substr(0, str.find('.')).c_str());
	// Char
	if (i < 127 && i > 0 && isprint(i))
		std::cout << "Char : '" << static_cast<char>(i) << "'" << std::endl;
	else
		std::cout << "Char : Non displayable" << std::endl;
	// int
	if (!is_num)
		std::cout << "Int : impossible" << std::endl;
	else if (b == false)
		std::cout << "Int : overflow" << std::endl;
	else
		std::cout << "Int : " << i << std::endl;
	// float
	if (!is_num && f == 0)
		std::cout << "Float : not a thing" << std::endl;
	else
		std::cout << "Float : " << std::setprecision(8) << f << "f" << std::endl;
	// double
	if (!is_num && d == 0)
		std::cout << "Double : not a thing" << std::endl;
	else
		std::cout << "Double : " << std::setprecision(15) << d << std::endl;
}

void ScalarConverter::convert(const std::string &str)
{
	bool t;
	bool dote = false;
	bool f = false;
	int i = 0;
	if (str[0] == '-')
		i++;
	if (std::isdigit(str[i]))
		t = true;
	else
		t = false;
	while (str[i])
	{
		if (f == true)
			return (print_err(str, i));
		if (str[i] == '.')
		{
			if (dote == true || i == static_cast<int>(str.length() - 1))
				return (print_err(str, i));
			dote = true;
		}
		else if (str[i] == 'f')
		{
			if (i == 0)
				return (print_err(str, i));
			f = true;
		}
		else if (std::isdigit(str[i]))
		{
			if (t == false)
				return (print_err(str, i));
		}
		else if (t == true)
			return (print_err(str, i));
		i++;
	}
	printer(str, t);
}
