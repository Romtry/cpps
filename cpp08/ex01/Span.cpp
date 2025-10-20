//
// Created by rothiery on 10/13/25.
//

#include "Span.hpp"

Span::Span()
	:	_vectint(0), _range(0)
{

}

Span::Span(const Span &original)
	: _vectint(original._vectint), _range(original._range)
{

}

Span::~Span()
{

}

Span::Span(const unsigned int n)
	: _range(n)
{

}

void Span::addNumber(const unsigned int n)
{
	if (this->_vectint.size() < this->_range)
	{
		_vectint.push_back(n);
		std::cout << n << " add to int vector at index : " << this->_vectint.size() << '\n' << std::endl;
		return;
	}
	std::cout << "can't add anymore" << std::endl;
}

void Span::addManyNumber(const unsigned int n, const unsigned int max)
{
	srand(time(0));
	for (unsigned int i = 0; i < n; i++)
	{
		addNumber(rand() % max);
	}
}


unsigned int Span::longestSpan() const
{
	if (this->_vectint.size() <= 1)
	{
		std::cout << "No span can be found" << std::endl;
		return (0);
	}
	unsigned int s = _vectint[0];
	unsigned int l = _vectint[0];
	for (unsigned int i = 0; i < this->_range; i++)
	{
		if (this->_vectint[i] < s)
			s = this->_vectint[i];
		else if (this->_vectint[i] > l)
			l = this->_vectint[i];
	}
	// std::cout << "Lower is : " << s << " and higher is : " << l << " span is : " << l - s << std::endl;
	return (l - s);
}

unsigned int Span::shortestSpan() const
{
	if (this->_vectint.size() <= 1)
	{
		std::cout << "No span can be found" << std::endl;
		return (0);
	}
	unsigned int save;
	if (this->_vectint[0] > this->_vectint[1])
		save = this->_vectint[0] - this->_vectint[1];
	else
		save = this->_vectint[1] - this->_vectint[0];

	for (unsigned int i = 0; i + 1 < _range; i++)
	{
		for (unsigned int i2 = i + 1; i2 < _range; i2++)
		{
			if (this->_vectint[i] > this->_vectint[i2] && this->_vectint[i] - this->_vectint[i2] < save)
			{
				save = this->_vectint[i] - this->_vectint[i2];
			}
			else if (this->_vectint[i2] - this->_vectint[i] < save)
			{
				save = this->_vectint[i2] - this->_vectint[i];
			}
		}
	}
	// std::cout << "i0 = " << indexes[0] << "i1 = " << indexes[1] << std::endl;
	return (save);
}

Span &Span::operator=(const Span &original)
{
	this->_range = original._range;
	this->_vectint = original._vectint;
	return (*this);
}