#pragma once

#include <iostream>
#include <stack>

template <typename T>

class	MutantStack : public std::stack<T>
{
public:
	MutantStack();
	MutantStack(const MutantStack<T> &other);
	MutantStack &operator=(const MutantStack<T> &other);
	~MutantStack();

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	iterator	begin();
	iterator	end();

	const_iterator	begin() const;
	const_iterator	end() const;

	T&			top();
	const T&	top() const;
	void		pop();
};

#include "MutantStack.tpp"

