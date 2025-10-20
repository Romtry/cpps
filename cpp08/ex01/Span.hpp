//
// Created by rothiery on 10/13/25.
//

#pragma once

# include <iostream>
# include <exception>
# include <vector>
# include <ctime>
# include <cstdlib>

class Span
{
	public:
		Span();
		Span(const Span &original);
		Span(const unsigned int n);
		~Span();
		void	addNumber(unsigned int n);
		void	addManyNumber(unsigned int n, unsigned int max);
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;
		Span			&operator=(const Span &original);

	private:
		std::vector<unsigned int>	_vectint;
		unsigned int				_range;
};