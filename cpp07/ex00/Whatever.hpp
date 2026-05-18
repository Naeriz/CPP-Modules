#pragma once

#include <iostream>

template <typename T>
void swap (T &a, T &b)
{
	T c;

	c = a;
	a = b;
	b = c;
}

template <typename T>
T min (T val1, T val2)
{
	if (val1 < val2)
		return (val1);
	return (val2);
}

template <typename T>
T max (T val1, T val2)
{
	if (val1 > val2)
		return (val1);
	return (val2);
}