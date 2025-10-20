//
// Created by rothiery on 10/17/25.
//

#include <list>

#include "MutantStack.hpp"

// * CUSTOM

// void	testIterator()
// {
// 	MutantStack<int>			mstack;
// 	MutantStack<int>::iterator	it;
// 	MutantStack<int>::iterator	ite;
// 	unsigned int				i;
//
// 	mstack.push(0);
// 	mstack.push(1);
// 	mstack.push(2);
// 	mstack.push(3);
// 	mstack.push(4);
// 	mstack.push(5);
// 	mstack.push(6);
// 	mstack.push(7);
// 	mstack.push(8);
// 	mstack.push(9);
//
// 	it = mstack.begin();
// 	ite = mstack.end();
// 	i = 0;
//
// 	while (it != ite)
// 	{
// 		std::cout << "mstack[" << i << "] = " << *it << std::endl;
// 		it++;
// 		i++;
// 	}
// }
//
// void	testPop()
// {
// 	MutantStack<int>	mstack;
//
// 	mstack.push(42);
// 	mstack.push(420);
// 	mstack.push(69);
//
// 	std::cout << "Size before pop: " << mstack.size() << std::endl;
// 	std::cout << "Top before pop: " << mstack.top() << std::endl;
//
// 	mstack.pop();
// 	std::cout << "Size after pop: " << mstack.size() << std::endl;
// 	std::cout << "Top after pop: " << mstack.top() << std::endl;
// }
//
// void	testPush()
// {
// 	MutantStack<int>	mstack;
//
// 	mstack.push(42);
// 	mstack.push(420);
// 	mstack.push(69);
//
//
// 	std::cout << "Size: " << mstack.size() << std::endl;
// 	std::cout << "Begin: " << *mstack.begin() << std::endl;
// 	std::cout << "Top: " << mstack.top() << std::endl;
// }
//
// int	main()
// {
// 	std::cout << "--- Testing Push ---" << std::endl;
// 	testPush();
// 	std::cout << "\n--- Testing Pop ---" << std::endl;
// 	testPop();
// 	std::cout << "\n--- Testing Iterators ---" << std::endl;
// 	testIterator();
//
// 	return (0);
// }

// * ORIGINAL

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}

// * WITH LIST

// int main()
// {
// 	std::list<int> mstack;
// 	mstack.push_back(5);
// 	mstack.push_back(17);
// 	std::cout << mstack.back() << std::endl;
// 	mstack.pop_back();
// 	std::cout << mstack.size() << std::endl;
// 	mstack.push_back(3);
// 	mstack.push_back(5);
// 	mstack.push_back(737);
// 	//[...]
// 	mstack.push_back(0);
// 	std::list<int>::iterator it = mstack.begin();
// 	std::list<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
// 	return 0;
// }