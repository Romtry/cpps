//
// Created by rothiery on 11/25/25.
//

#include "PmergeMe.hpp"

int main(int ac, char **argv)
{
	if (ac <= 2)
	{
		std::cout << "not enough args" << std::endl;
		return (1);
	}
	PmergeMe test;
	test.Init(argv);
	test.PmergMe();
}
