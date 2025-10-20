//
// Created by rothiery on 10/8/25.
//

#pragma once

template <class T>
class Array
{
	public:
		~Array();
		Array();
		Array(const Array &original);
		Array(const unsigned int &n);

		class IndexOutOfBound : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		Array	&operator=(const Array &original);
		T		&operator[](unsigned int index);
		const T	&operator[](unsigned int index) const;

		int GetSize() const;

	private:
		T				*_arr;
		unsigned int	_size;

};