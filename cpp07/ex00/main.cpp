//
// Created by rothiery on 10/3/25.
//

#include <algorithm>
# include <iostream>
#include "utils.hpp"

int	main()
{
	char c = 'f';
	char c2 = '&';
	std::string str = "testsetsetset";
	std::string	str2 = "letest ^&*";
	double d = 54651.213;
	double d2 = 21;

	std::cout << "c = " << c << " c2 = " << c2 << std::endl;
	swap(c, c2);
	std::cout << "c = " << c << " c2 = " << c2 << std::endl;
	std::cout << "min = " << min(c, c2) << std::endl;
	std::cout << "max = " << max(c, c2) << std::endl;
	std::cout << "str = " << str << " str2 = " << str2 << std::endl;
	swap(str, str2);
	std::cout << "str = " << str << " str2 = " << str2 << std::endl;
	std::cout << "min = " << min(str, str2) << std::endl;
	std::cout << "max = " << max(str, str2) << std::endl;
	std::cout << "d = " << d << " d2 = " << d2 << std::endl;
	swap(d, d2);
	std::cout << "d = " << d << " d2 = " << d2 << std::endl;
	std::cout << "min = " << min(d, d2) << std::endl;
	std::cout << "max = " << max(d, d2) << std::endl;
}