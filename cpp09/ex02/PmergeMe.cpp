//
// Created by rothiery on 11/25/25.
//

#include "PmergeMe.hpp"

#include <cctype>
#include <cstdlib>
#include <vector>

bool PmergeMe::Init(char **argv)
{
	for (unsigned int i = 1; argv[i]; ++i)
	{
		for (unsigned int j = 0; argv[i][j]; ++j)
		{
			if (!std::isdigit(argv[i][j]))
			{
				std::cout << "Error" << std::endl;
				return (false);
			}
		}
		_list.push_back(std::atoi(argv[i]));
	}
	return (true);
}

void PmergeMe::PmergMe()
{
	int size = _list.size();
	for (unsigned int i = 1; size / i > 2; i *= 2)
	{
		unsigned int nBlocks;
		if ((size / i) % 2)
			nBlocks = (size / i) - 1;
		else
			nBlocks = size / i;
		std::vector<int> save;
		for (unsigned int j = 0; j < size % (i * 2); ++j)
		{
			save.push_back(_list.back());
			_list.pop_back();
		}
		std::vector<int> lists[nBlocks];
		for (unsigned int j = 0; j < nBlocks; ++j)
		{
			for (unsigned int k = 0; k < i; ++k)
			{
				lists[j].push_back(_list.back());
				_list.pop_back();
			}
		}
		for (int j = nBlocks - 1; j >= 0; j -= 2)
		{
			if (lists[j].front() < lists[j - 1].front())
			{
				while (!lists[j].empty())
				{
					_list.push_back(lists[j].back());
					lists[j].pop_back();
				}
				while (!lists[j - 1].empty())
				{
					_list.push_back(lists[j - 1].back());
					lists[j - 1].pop_back();
				}
			}
			else
			{
				while (!lists[j - 1].empty())
				{
					_list.push_back(lists[j - 1].back());
					lists[j - 1].pop_back();
				}
				while (!lists[j].empty())
				{
					_list.push_back(lists[j].back());
					lists[j].pop_back();
				}
			}
		}
		while (!save.empty())
		{
			_list.push_back(save.back());
			save.pop_back();
		}
	}
}