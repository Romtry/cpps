//
// Created by rothiery on 10/3/25.
//

#pragma once

template <typename T>
void	swap(T &arg1, T &arg2)
{
	T temp = arg1;
	arg1 = arg2;
	arg2 = temp;
}

template <typename T>
T	max(T &arg1, T &arg2)
{
	return (arg1 > arg2) ? arg1 : arg2;
}


template <typename T>
T	min(T &arg1, T &arg2)
{
	return (arg1 < arg2) ? arg1 : arg2;
}