//
// Created by rothiery on 10/17/25.
//

#pragma once

# include <iostream>
# include <stack>
# include <iterator>

template <class T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack();
	MutantStack(const MutantStack<T> &original);
	~MutantStack();
	MutantStack	&operator=(const MutantStack<T> &original);
	typedef typename std::stack<T>::container_type::iterator	iterator;

	iterator	begin();
	iterator	end();
};

# include "MutantStack.tpp"
