#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
typename T::iterator	easyfind(T &v, int num)
{
	typename T::iterator it = std::find(v.begin(), v.end(), num);

	return (it);
}
