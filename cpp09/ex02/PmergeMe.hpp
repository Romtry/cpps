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
		PmergeMe() {} ;
		PmergeMe(char **argv);

		void MakePairs(std::vector<std::pair<int, int> > &pairs, int &rest);
		void SplitPairs(const std::vector<std::pair<int, int> > &pairs, C &MainChain, C &Pend);

		void FordJohnson();

	private:
		C _container;
};
