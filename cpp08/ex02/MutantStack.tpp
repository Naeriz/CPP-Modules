#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &other) : std::stack<T>(other) {}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &other)
{
	if (this != &other)
		std::stack<T>::operator=(other);
	return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack() {}


template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (this->c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	return (this->c.end());
}

template <typename T>
T	&MutantStack<T>::top()
{
	if (this->empty())
		throw::std::logic_error("The stack is empty and contain no top");
	return (std::stack<T>::top());
}

template <typename T>
const T	&MutantStack<T>::top() const
{
	if (this->empty())
		throw::std::logic_error("The stack is empty and contain no top");
	return (std::stack<T>::top());
}

template <typename T>
void	MutantStack<T>::pop()
{
	if (this->empty())
		throw::std::logic_error("Impossible to pop something from an empty stack");
	std::stack<T>::pop();
}