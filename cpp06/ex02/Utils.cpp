//
// Created by rothiery on 9/24/25.
//

#include "Base.hpp"
#include <iostream>
#include <cstdlib>

Base	*generate()
{
	srand(time(0));
	switch (rand() % 3)
	{
		case(0):
			return (new A);
		case(1):
			return (new B);
		default:
			return (new C);
	}
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "Class is A type" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "Class is B type" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "Class is C type" << std::endl;
	else
		std::cout << "Class is unknown type" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		if (dynamic_cast<A *>(&p))
			std::cout << "Class is A type" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		if (dynamic_cast<B *>(&p))
			std::cout << "Class is B type" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		if (dynamic_cast<C *>(&p))
			std::cout << "Class is C type" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
