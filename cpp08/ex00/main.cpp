//
// Created by rothiery on 10/9/25.
//

#include "easyfind.hpp"

void	tryVector(const std::vector<int> &intVector, unsigned int target)
{
	try
	{
		easyfind(intVector, target);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	tryList(const std::list<int> &intList, unsigned int target)
{
	try
	{
		easyfind(intList, target);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int	main()
{
	std::list<int>		intList;
	std::vector<int>	intVector;

	intList.push_back(1);
	intList.push_back(2);
	intList.push_back(3);
	intList.push_back(4);
	intList.push_back(5);

	intVector.push_back(1);
	intVector.push_back(2);
	intVector.push_back(3);
	intVector.push_back(4);
	intVector.push_back(5);

	std::cout << "--- Test with Lists ---" << std::endl;
	tryList(intList, 0);
	tryList(intList, 1);
	tryList(intList, 3);
	tryList(intList, 5);
	tryList(intList, 42);
	tryList(intList, -42);

	std::cout << "\n--- Test with Vectors ---" << std::endl;
	tryVector(intVector, 0);
	tryVector(intVector, 1);
	tryVector(intVector, 3);
	tryVector(intVector, 5);
	tryVector(intVector, 42);
	tryVector(intVector, -42);

	return (0);
}