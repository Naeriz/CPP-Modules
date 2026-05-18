#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(NULL), _size(n)
{
	if (_size == 0) {
        throw std::invalid_argument("Size can't be 0");
    }
    _array = new T[_size];
}

template <typename T>
Array<T>::Array(const Array &other) : _array(NULL), _size(other._size)
{
 	_array = new T[_size];
    for (unsigned int i = 0; i < _size; i++) 
	{
        _array[i] = other._array[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		delete[] (_array);
		_size = other._size;
		_array = NULL;
		if (_size > 0)
		{
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
			{
        		_array[i] = other._array[i];
			}
		}
	}
	return (*this);
}

template <typename T>
Array<T>::~Array()
{
	delete[] (_array);
}

template <typename T>
T&	Array<T>::operator[](unsigned int i)
{
	if (i >= _size || !_array)
		throw std::out_of_range("Array index out of bounds");
	return (_array[i]);
}

template <typename T>
const T&	Array<T>::operator[](unsigned int i) const
{
	if (i >= _size || !_array)
		throw std::out_of_range("Array index out of bounds");
	return (_array[i]);
}

template <typename T>
unsigned int	Array<T>::getSize() const
{
	return (_size);
}