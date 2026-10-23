#pragma once

#include <stdexcept>
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <climits>
#include <list>

class RPN
{
	private:
		std::stack<long, std::list<long> > _stack;

		int		valid_digit(const std::string &token);
		char	valid_op(const std::string &token);
		void	math(char op);
	public:
		RPN();
		RPN(const RPN &cpyfrom);
		RPN& operator=(const RPN &cpyfrom);
		~RPN();
		void	token_extract(const std::string &str);
} ;