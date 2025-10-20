//
// Created by rothiery on 10/6/25.
//

#pragma once

template <typename T, typename F>
void	iter(T *arr, const int length, void function(F &arg))
{
	for (int i = 0; i < length; i++)
	{
		function(arr[i]);
	}
}

