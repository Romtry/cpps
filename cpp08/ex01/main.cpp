//
// Created by rothiery on 10/13/25.
//

#include <iostream>
# include <cstdlib>
#include <time.h>
#include "Span.hpp"

void	empty()
{
	Span test;
	//default constructor
	std::cout << "Test of default constructor\n" << std::endl;
	test.addNumber(40);
	std::cout << "\n---------------------\n" << std::endl;
	std::cout << test.longestSpan() << std::endl;
	std::cout << "\n---------------------\n" << std::endl;
	std::cout << test.shortestSpan() << std::endl;
	std::cout << "\n---------------------\n" << std::endl;
	//with 0
	Span test2(0);
	std::cout << "Test of an empty array\n" << std::endl;
	test2.addNumber(40);
	std::cout << "\n---------------------\n" << std::endl;
	std::cout << test2.longestSpan() << std::endl;
	std::cout << "\n---------------------\n" << std::endl;
	std::cout << test2.shortestSpan() << std::endl;
	std::cout << "\n---------------------\n" << std::endl;
}

void	classic()
{
	Span test(5);
	//5 num negatives, 0, positifs
	std::cout << "Test of 5 numbers\n" << std::endl;
	test.addNumber(42);
	test.addNumber(60);
	test.addNumber(0);
	test.addNumber(6546);
	test.addNumber(68);
	test.addNumber(50);
	std::cout << "\n---------------------\n" << std::endl;
	std::cout << test.longestSpan() << std::endl;
	std::cout << "\n---------------------\n" << std::endl;
	std::cout << test.shortestSpan() << std::endl;
	std::cout << "\n---------------------\n" << std::endl;

}
//
void	randomised()
{
	Span test(3);
	//15 random numbers
	std::cout << "Test of 3 rand numbers 0-10000\n" << std::endl;
	test.addManyNumber(3, 10000);
	std::cout << "\n---------------------\n" << std::endl;
	std::cout << test.longestSpan() << std::endl;
	std::cout << "\n---------------------\n" << std::endl;
	std::cout << test.shortestSpan() << std::endl;
	std::cout << "\n---------------------\n" << std::endl;

	Span test2(5);
	//15 random numbers
	std::cout << "Test of 5 rand numbers 0-100\n" << std::endl;
	test2.addManyNumber(5, 100);
	std::cout << "\n---------------------\n" << std::endl;
	std::cout << test2.longestSpan() << std::endl;
	std::cout << "\n---------------------\n" << std::endl;
	std::cout << test2.shortestSpan() << std::endl;
	std::cout << "\n---------------------\n" << std::endl;

	Span test3(20);
	std::cout << "Test of 20 rand numbers 0-500\n" << std::endl;
	test3.addManyNumber(20, 500);
	std::cout << "\n---------------------\n" << std::endl;
	std::cout << test3.longestSpan() << std::endl;
	std::cout << "\n---------------------\n" << std::endl;
	std::cout << test3.shortestSpan() << std::endl;
	std::cout << "\n---------------------\n" << std::endl;
}

void helltest()
{
	Span test(15000);
	//15 random numbers
	std::cout << "Test of 15000 rand numbers !!!!!!!\n" << std::endl;
	test.addManyNumber(15000, -1);
	std::cout << "\n---------------------\n" << std::endl;
	std::cout << test.longestSpan() << std::endl;
	std::cout << "\n---------------------\n" << std::endl;
	std::cout << test.shortestSpan() << std::endl;
	std::cout << "\n---------------------\n" << std::endl;
}

int main()
{
	// empty();
	// classic();
	// randomised();
	// helltest();
}