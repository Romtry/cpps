//
// Created by rothiery on 10/17/25.
//

#pragma once

#include "MutantStack.hpp"

template <class T>
MutantStack<T>::MutantStack()
{

}

template <class T>
MutantStack<T>::MutantStack(const MutantStack<T> &original)
{
	(void)original;
}

template <class T>
MutantStack<T>::~MutantStack()
{

}

template <class T>
MutantStack<T>	&MutantStack<T>::operator=(const MutantStack &original)
{
	(void)original;
	return (*this);
}

template <class T>
typename MutantStack<T>::iterator	MutantStack<T>::begin()
{
	return (this->c.begin());
}

template <class T>
typename MutantStack<T>::iterator	MutantStack<T>::end()
{
	return (this->c.end());
}