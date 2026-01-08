//
// Created by rothiery on 11/25/25.
//

#pragma once

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <stdexcept>

template <typename C>
class PmergeMe
{
	public:
		PmergeMe() {}
		PmergeMe(PmergeMe &original) {_container = original.GetContainer();}
		PmergeMe &operator=(PmergeMe &original) {_container = original.GetContainer(); return (*this);}
		~PmergeMe() {}
		PmergeMe(char **argv);

		C		GetContainer() {return (_container);}
		void	MakePairs(std::vector<std::pair<int, int> > &pairs, int &rest);
		void	SplitPairs(const std::vector<std::pair<int, int> > &pairs, C &MainChain, C &Pend);

		void FordJohnson();

	private:
		C _container;
};
