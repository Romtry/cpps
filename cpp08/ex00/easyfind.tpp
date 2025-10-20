# pragma once

# include "easyfind.hpp"
# include <iterator>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

template <typename T>
void	easyfind(const T &arr, int i)
{
	typename T::const_iterator it = std::find(arr.begin(), arr.end(), i);

	if (it == arr.end())
		throw std::out_of_range("Value not found");
	std::cout << i << " found" << std::endl;
}
