//
// Created by rothiery on 11/19/25.
//

#pragma once

#include <iostream>
#include <stack>
#include <vector>

class RPN
{
	public:
					RPN() {} ;
					~RPN() {};
		void		exec(const std::string &input);
	private:
		std::stack<int>	_numbers;
};
