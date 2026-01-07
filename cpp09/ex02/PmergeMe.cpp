//
// Created by rothiery on 11/25/25.
//

#include "PmergeMe.hpp"

#include <cctype>
#include <cstdlib>
#include <cstring>
#include <vector>


template<typename C>
PmergeMe<C>::PmergeMe(char **argv)
{
	for (unsigned int i = 1; argv[i]; ++i)
	{
		if (!argv[i][0])
			throw (std::invalid_argument("Empty arg"));
		for (unsigned int j = 0; argv[i][j]; ++j)
		{
			if (!std::isdigit(argv[i][j]))
			{
				std::string tmp;
				tmp += "[";
				tmp += argv[i][j];
				tmp += "] Is not a digit";
				throw (std::invalid_argument(tmp));
			}
		}
		long number = std::atol(argv[i]);
		if (strlen(argv[i]) > 10 || number > 2147483647)
			throw (std::invalid_argument("Overflow value"));
		_container.push_back(number);
	}
}

template <typename C>
void	Print_container(C &_container)
{
	std::cout << "[";
	for (typename C::iterator it = _container.begin(); it != _container.end(); ++it)
	{
		std::cout << *it;
		if (it + 1 < _container.end())
			std::cout << ", ";
	}
	std::cout << "]" << std::endl;
}

template <typename C>
void PmergeMe<C>::MakePairs(std::vector<std::pair<int,int> > &pairs, int &rest)
{
	rest = -1;
	pairs.clear();

	typename C::const_iterator it = _container.begin();

	while (it != _container.end())
	{
		int first = *it;
		++it;

		if (it == _container.end())
		{
			rest = first;
			break;
		}

		int second = *it;
		++it;

		if (first < second)
			pairs.push_back(std::make_pair(first, second));
		else
			pairs.push_back(std::make_pair(second, first));
	}
}

template <typename C>
void PmergeMe<C>::SplitPairs(const std::vector<std::pair<int,int> > &pairs, C &MainChain, C &Pend)
{
	MainChain.clear();
	Pend.clear();

	for (size_t i = 0; i < pairs.size(); ++i)
	{
		MainChain.push_back(pairs[i].second);
		Pend.push_back(pairs[i].first);
	}
}

template <typename C>
void PmergeMe<C>::FordJohnson()
{
	std::vector<std::pair<int,int> > pairs;
	std::vector<C> pendLists;
	int rest = -1;

	while (_container.size() > 1)
	{
		if (rest != -1)
		{
			typename C::iterator it = std::lower_bound(_container.begin(), _container.end(), rest);
			_container.insert(it, rest);
			rest = -1;
		}
		if (_container.size() % 2 != 0)
		{
			rest = _container.back();
			_container.pop_back();
		}
		pairs.clear();
		for (size_t i = 0; i + 1 < _container.size(); i += 2)
		{
			int a = _container[i];
			int b = _container[i + 1];
			if (a < b)
				pairs.push_back(std::make_pair(a,b));
			else
				pairs.push_back(std::make_pair(b,a));
		}

		C newMainChain;
		C pend;

		for (size_t i = 0; i < pairs.size(); ++i)
		{
			newMainChain.push_back(pairs[i].second);
			pend.push_back(pairs[i].first);
		}
		pendLists.push_back(pend);
		_container = newMainChain;
	}

	for (int i = pendLists.size() - 1; i >= 0; --i)
	{
		C& pend = pendLists[i];
		for (size_t i = 0; i < pend.size(); ++i)
		{
			typename C::iterator it = std::lower_bound(_container.begin(), _container.end(), pend[i]);
			_container.insert(it, pend[i]);
		}
	}
	if (rest != -1)
	{
		typename C::iterator it = std::lower_bound(_container.begin(), _container.end(), rest);
		_container.insert(it, rest);
	}
	Print_container(_container);
}

template class PmergeMe<std::vector<int> >;
template class PmergeMe<std::deque<int> >;
