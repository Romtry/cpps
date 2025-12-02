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
		_vector.push_back(std::atoi(argv[i]));
	}
	return (true);
}



void PmergeMe::PmergMe()
{
	int size = _vector.size();
	unsigned int i;
	for (i = 1; size / i > 2; i *= 2)
	{
		unsigned int nBlocks;
		if ((size / i) % 2)
			nBlocks = (size / i) - 1;
		else
			nBlocks = size / i;
		std::vector<int> save;
		for (unsigned int j = 0; j < size % (i * 2); ++j)
		{
			save.push_back(_vector.back());
			_vector.pop_back();
		}
		std::vector<int> lists[nBlocks];
		for (unsigned int j = 0; j < nBlocks; ++j)
		{
			for (unsigned int k = 0; k < i; ++k)
			{
				lists[j].push_back(_vector.back());
				_vector.pop_back();
			}
		}
		for (int j = nBlocks - 1; j >= 0; j -= 2)
		{
			if (lists[j].front() < lists[j - 1].front())
			{
				while (!lists[j].empty())
				{
					_vector.push_back(lists[j].back());
					lists[j].pop_back();
				}
				while (!lists[j - 1].empty())
				{
					_vector.push_back(lists[j - 1].back());
					lists[j - 1].pop_back();
				}
			}
			else
			{
				while (!lists[j - 1].empty())
				{
					_vector.push_back(lists[j - 1].back());
					lists[j - 1].pop_back();
				}
				while (!lists[j].empty())
				{
					_vector.push_back(lists[j].back());
					lists[j].pop_back();
				}
			}
		}
		while (!save.empty())
		{
			_vector.push_back(save.back());
			save.pop_back();
		}
	}

	while (i > 0)
	{
		const unsigned int nBlocks = size / i;
		std::vector<int> save;
		for (unsigned int j = 0; j < size % i; ++j)
		{
			save.push_back(_vector.back());
			_vector.pop_back();
		}
		std::vector<int> bend[nBlocks / 2];
		std::vector<int> main[nBlocks - nBlocks / 2];
		bool b = false;
		if (nBlocks % 2 == 1)
			b = false;
		else
			b = true;
		for (unsigned int l = 0; l < nBlocks; ++l)
		{
			if (b == false && l + 1 < nBlocks)
			{
				for (unsigned int j = 0; j < nBlocks; ++j)
				{
					std::cout << "list = [";
					for (unsigned int k = 0; k < i; ++k)
					{
						std::cout << _vector.back();
						if (k + 1 < i)
							std::cout << ", ";
						bend[j].push_back(_vector.back());
						_vector.pop_back();
					}
					std::cout << "]" << std::endl;
				}
				std::cout << std::endl;
				b = !b;
			}
			else
			{
				for (unsigned int j = 0; j < nBlocks; ++j)
				{
					std::cout << "list = [";
					for (unsigned int k = 0; k < i; ++k)
					{
						std::cout << _vector.back();
						if (k + 1 < i)
							std::cout << ", ";
						main[j].push_back(_vector.back());
						_vector.pop_back();
					}
					std::cout << "]" << std::endl;
				}
				std::cout << std::endl;
				b = !b;
			}
		}


		for (unsigned int j = 0; j < nBlocks; ++j)
		{
			std::cout << "list = [";
			for (unsigned int k = 0; k < i; ++k)
			{
				std::cout << _vector.back();
				if (k + 1 < i)
					std::cout << ", ";
				lists[j].push_back(_vector.back());
				_vector.pop_back();
			}
			std::cout << "]" << std::endl;
		}
		std::cout << std::endl;



		for (int j = nBlocks - 1; j >= 0; j -= 2)
		{
			if (lists[j].front() < lists[j - 1].front())
			{
				while (!lists[j].empty())
				{
					_vector.push_back(lists[j].back());
					lists[j].pop_back();
				}
				while (!lists[j - 1].empty())
				{
					_vector.push_back(lists[j - 1].back());
					lists[j - 1].pop_back();
				}
			}
			else
			{
				while (!lists[j - 1].empty())
				{
					_vector.push_back(lists[j - 1].back());
					lists[j - 1].pop_back();
				}
				while (!lists[j].empty())
				{
					_vector.push_back(lists[j].back());
					lists[j].pop_back();
				}
			}
		}
		while (!save.empty())
		{
			_vector.push_back(save.back());
			save.pop_back();
		}
		i /= 2;
	}
}