# pragma once

# include <iostream>
# include <exception>

#include "Array.hpp"

template <class T>
Array<T>::~Array()
{
	delete[] this->_arr;
}

template <class T>
Array<T>::Array()
	: _arr(NULL), _size(0)
{}

template <class T>
Array<T>::Array(const Array &original)
{
	this->_arr = new T[original._size];
	this->_size = original._size;
	if (!this->_arr)
	{
		std::cout << "allocation of memory failed" << std::endl;
	}
	for (unsigned int i2 = 0; i2 < original._size; i2++)
	{
		this->_arr[i2] = original._arr[i2];
	}
}

template <class T>
Array<T>::Array(const unsigned int &n)
{
	this->_size = n;
	this->_arr = new T[n]();
	if (!this->_arr)
	{
		std::cout << "allocation of memory failed" << std::endl;
	}
}

template<class T>
const char *Array<T>::IndexOutOfBound::what() const throw()
{
	return ("out of bound");
}


template<class T>
Array<T> &Array<T>::operator=(const Array &original)
{
	delete[] this->_arr;
	int i = 0;
	while (original._arr[i])
		i++;
	this->_arr = new T[i];
	if (!this->_arr)
	{
		std::cout << "allocation of memory failed" << std::endl;
	}
	for (unsigned int i2 = 0; i2 < i; i2++)
	{
		this->_arr[i2] = original._arr[i2];
	}
	return (*this);
}

template <class T>
T				&Array<T>::operator[](unsigned int index)
{
	if (this->_size > index)
		return (this->_arr[index]);
	throw (IndexOutOfBound());
}

template <class T>
const T			&Array<T>::operator[](unsigned int index) const
{
	if (this->_size > index)
		return (this->_arr[index]);
	throw (IndexOutOfBound());
}

template<class T>
int Array<T>::GetSize() const
{
	return (this->_size);
}
