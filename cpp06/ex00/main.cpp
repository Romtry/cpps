//
// Created by rothiery on 9/15/25.
//

#include "ScalarConverter.hpp"

int main(const int argc, char **argv)
{
	if (argc == 1)
		std::cout << "No values given" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			ScalarConverter::convert(argv[i]);
			if (i < argc - 1)
				std::cout << '\n' << "--------------------------" << '\n' << std::endl;
		}
	}
}