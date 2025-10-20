//
// Created by rothiery on 10/6/25.
//

# include "iter.hpp"
#include <iostream>

void	printercc(const char &arg)
{
	std::cout << arg << std::endl;
}

void	printerc(char &arg)
{
	arg = 42;
	std::cout << arg << std::endl;
}

void	printeri(int &arg)
{
	arg = 42;
	std::cout << arg << std::endl;
}

void	printeric(const int &arg)
{
	std::cout << arg << std::endl;
}

void	printers(std::string &arg)
{
	arg = 42;
	std::cout << arg << std::endl;
}

void	printersc(const std::string &arg)
{
	std::cout << arg << std::endl;
}

int	main()
{
	char					carr[] = "test";
	char					carr2[] = "fffff";
	char					carr3[] = "";
	int						iarr[] = {0, 10, 21321, -8468};
	int						iarr2[] = {0, 10, 21321, -8468};
	int						iarr3[] = {};
	std::string				sarr[] = {"test", "test2", "les test avec plein de mots", "", "last one"};
	std::string				sarr2[] = {"test", "test2", "les test avec plein de mots", "", "last one"};
	std::string				sarr3[] = {};
//char
	iter(carr, 5, printerc);
	std::cout << '\n' << "------------------------" << '\n' << std::endl;
	iter(carr2, 5, printercc);
	std::cout << '\n' << "------------------------" << '\n' << std::endl;
	iter(carr3, 0, printercc);
	std::cout << '\n' << "------------------------" << '\n' << std::endl;
//int
	iter(iarr, 4, printeri);
	std::cout << '\n' << "------------------------" << '\n' << std::endl;
	iter(iarr2, 4, printeric);
	std::cout << '\n' << "------------------------" << '\n' << std::endl;
	iter(iarr3, 10, printeric);
	std::cout << '\n' << "------------------------" << '\n' << std::endl;
//str
	iter(sarr, 5, printersc);
	std::cout << '\n' << "------------------------" << '\n' << std::endl;
	iter(sarr2, 5, printers);
	std::cout << '\n' << "------------------------" << '\n' << std::endl;
	iter(sarr3, 0, printers);
}