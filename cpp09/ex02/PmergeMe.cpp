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

void	Print_vector(std::vector<int> vector)
{
	std::cout << "[";
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); ++it)
	{
		std::cout << *it;
		if (it + 1 < vector.end())
			std::cout << ", ";
	}
	std::cout << "]" << std::endl;
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
		unsigned int pend_index;
		if (nBlocks % 2 == 1)
			 pend_index = nBlocks / 2;
		else
			pend_index = (nBlocks / 2) - 1;
		std::vector<std::vector<int> > pend;
		std::vector<std::vector<int> > main;

		// std::cout << "pend = " << (nBlocks / 2) - 1 << std::endl;
		// std::cout << "main = " << (nBlocks - nBlocks / 2) + 1 << std::endl;
		bool b = false;
		if (nBlocks % 2 == 1)
			b = false;
		else
			b = true;
		pend_index = 0;
		unsigned int main_index = 0;
		for (unsigned int j = 0; j < nBlocks; ++j)
		{
			if (b == false && j + 1 < nBlocks)
			{
				std::vector<int> tmp;
				// std::cout << "pend[" << pend_index << "] = [";
				for (unsigned int k = 0; k < i; ++k)
				{
					// std::cout << _vector.back();
					// if (k + 1 < i)
					// 	std::cout << ", ";
					tmp.push_back( _vector.back());
					_vector.pop_back();
				}
				pend.push_back(tmp);
				++pend_index;
				// std::cout << "]" << std::endl;
				// std::cout << std::endl;
				b = true;
			}
			else
			{
				std::vector<int> tmp;
				// std::cout << "HERE" << std::endl;
				// std::cout << "main[" << maini << "] = [";
				for (unsigned int k = 0; k < i; ++k)
				{
					// std::cout << _vector.back();
					// if (k + 1 < i)
					// 	std::cout << ", ";
					tmp.push_back(_vector.back());
					_vector.pop_back();
				}
				main.push_back(tmp);
				++main_index;
				// std::cout << "]" << std::endl;
				// std::cout << std::endl;
				b = false;
			}
		}

		std::cout << "isempty = " << pend.empty() << std::endl;

		while (!pend.empty())
		{
			std::cout << "HERE" << std::endl;
			std::cout << "pend[0] = ";
			Print_vector(pend[0]);
			std::cout << std::endl;
		}
		--main_index;
		--pend_index;
		for (unsigned int j = 0; j < nBlocks; ++j)
		{
			for (unsigned int k = 0; k < i; ++k)
			{
				_vector.push_back(main[main_index].back());
				main[main_index].pop_back();
			}
			--main_index;
		}


		// for (unsigned int j = 0; j < nBlocks; ++j)
		// {
		// 	if (b == false && j != 0 && j != 1)
		// 	{
		//
		// 		std::cout << "pend[" << pend_index << "] = [";
		// 		for (unsigned int k = 0; k < i; ++k)
		// 		{
		// 			std::cout << pend[pend_index].back();
		// 			if (k + 1 < i)
		// 				std::cout << ", ";
		// 			_vector.push_back(pend[pend_index].back());
		// 			pend[pend_index].pop_back();
		// 		}
		// 		std::cout << "]" << std::endl;
		// 		std::cout << std::endl;
		// 		--pend_index;
		// 		b = true;
		// 	}
		// 	else
		// 	{
		// 		std::cout << "main[" << main_index << "] = [";
		// 		for (unsigned int k = 0; k < i; ++k)
		// 		{
		// 			std::cout << main[main_index].back();
		// 			if (k + 1 < i)
		// 				std::cout << ", ";
		// 			_vector.push_back(main[main_index].back());
		// 			main[main_index].pop_back();
		// 		}
		// 		std::cout << "]" << std::endl;
		// 		std::cout << std::endl;
		// 		--main_index;
		// 		b = false;
		// 	}
		// }
		while (!save.empty())
		{
			_vector.push_back(save.back());
			save.pop_back();
		}
		i /= 2;
		Print_vector(_vector);
		std::cout << std::endl;
	}
}