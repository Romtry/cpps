//
// Created by rothiery on 11/25/25.
//

#pragma once

#include <iostream>
#include <algorithm>
#include <vector>


class PmergeMe
{
	public:
		bool Init(char **argv);
		void PmergMe();

	private:
		std::vector<int>  _list;

};
