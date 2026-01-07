//
// Created by rothiery on 11/25/25.
//

#include <deque>
#include <map>
#include <stack>
#include <ctime>
#include <iomanip>

#include "PmergeMe.hpp"

int main(const int ac, char **argv)
{
	if (ac < 2)
	{
		std::cout << "not enough args" << std::endl;
		return (1);
	}

	std::cout << std::endl;
	clock_t start = clock();
	try
	{
		PmergeMe<std::vector<int> > pm(argv);
		pm.FordJohnson();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Vector: " << e.what() << std::endl;
	}
	const double duration1 = (clock() - start) / double(CLOCKS_PER_SEC);

	std::cout << std::fixed << std::setprecision(6) << std::endl;


	start = clock();
	try
	{
		PmergeMe<std::deque<int> > pm2(argv);
		pm2.FordJohnson();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Deque: " << e.what() << std::endl;
		return (1);
	}
	const double duration = (clock() - start) / double(CLOCKS_PER_SEC);
	std::cout << std::endl << "Vector sort took: " << duration1 << " seconds" << std::endl;
	std::cout << "Deque sort took: " << duration << " seconds" << std::endl;

}
