#pragma once

#include <iostream>
#include <string>

template <typename T>
void iter(T *array, const size_t size, void (*func)(T&))
{
	for (size_t i = 0; i < size; i++)
		func(array[i]);
}
//overload for const ver
template <typename T>
void iter(const T *array, const size_t size, void (*func)(const T&))
{
	for (size_t i = 0; i < size; i++)
		func(array[i]);
}
//need const ver of print,if 2 ambiguous since both could match for non const case
//passing non const to const is fine, other way around could change and then disaster
template <typename test>
void	print(const test &a)
{
	std::cout << a << std::endl;
}