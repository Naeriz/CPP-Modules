#pragma once

#include <iostream>
#include <string>
#include <exception>

template <typename T>
class Array
{
	private:
		T *_array;
		unsigned int _size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		Array & operator=(const Array & other);
		~Array();

		T& 				operator[](unsigned int i);
		const T& 		operator[](unsigned int i) const;
		unsigned int	getSize() const;
};

#include "Array.tpp"