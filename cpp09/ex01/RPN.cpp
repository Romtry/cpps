//
// Created by rothiery on 11/19/25.
//

#include "RPN.hpp"

#include <algorithm>

void RPN::exec(const std::string &input)
{
	for (unsigned int i = 0; input.size() > i; )
	{
		if (std::isdigit(input[i]))
			_numbers.push(input[i] - '0');
		else if (input[i] == '+' || input[i] == '-' || input[i] == '/' || input[i] == '*')
		{
			if (_numbers.size() < 2)
			{
				std::cout << "Not enough numbers for this operation: input[" << i << "]: " << input[i] << std::endl;
				return;
			}
			const char comp[] = {'+', '-', '*', '/'};
			unsigned int j = 0;
			while (comp[j])
			{
				if (comp[j] == input[i])
					break;
				++j;
			}
			const int tmp = _numbers.top();
			_numbers.pop();
			switch (j)
			{
				case 0:
				{
					// std::cout << _numbers.top() << " + " << tmp << std::endl;
					_numbers.top() += tmp;
					// std::cout << "res = " << _numbers.top() << std::endl;
					break;
				}
				case 1:
				{
					// std::cout << _numbers.top() << " - " << tmp << std::endl;
					_numbers.top() -= tmp;
					// std::cout << "res = " << _numbers.top() << std::endl;
					break;
				}
				case 2:
				{
					// std::cout << _numbers.top() << " * " << tmp << std::endl;
					_numbers.top() *= tmp;
					// std::cout << "res = " << _numbers.top() << std::endl;
					break;
				}
				case 3:
				{
					// std::cout << _numbers.top() << " / " << tmp << std::endl;
					_numbers.top() /= tmp;
					// std::cout << "res = " << _numbers.top() << std::endl;
					break;
				}
				default:;
			}
		}
		else
		{
			std::cout << "Wrong input at: input[" << i << "]: " << input[i] << std::endl;
			return;
		}
		++i;
		if (i != input.size())
		{
			if (input[i] != ' ')
			{
				std::cout << "Need a space at index: " << i << std::endl;
				return;
			}
			i = input.find_first_not_of(' ', i);
		}
	}
	if (_numbers.size() > 1)
	{
		std::cout << "Not enough operators" << std::endl;
		return;
	}
	std::cout << _numbers.top() << std::endl;
}
