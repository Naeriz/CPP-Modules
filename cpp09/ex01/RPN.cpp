#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &cpyfrom)
{
	_stack = cpyfrom._stack;
	// std::cout << "copy constructor has been called\n";
}

RPN &RPN::operator=(const RPN &cpyfrom)
{
	if (this != &cpyfrom)
	{
		_stack = cpyfrom._stack;
	}
	// std::cout << "assignment operator has been called\n";
	return (*this);
}

RPN::~RPN() {}

int	RPN::valid_digit(const std::string &token)
{
	int conv = 0;
	char c = token[0];
	if (token.size() > 1)
		return 11;
	else if (c < '0' || c > '9')
		return 11;
	else
		conv = c - 48;
	return conv;
}

char	RPN::valid_op(const std::string &token)
{
	char c = token[0];
	if (token.size() > 1)
		return 'f';
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return c;
	return 'f';
}

void	RPN::math(char op)
{
	long valr = _stack.top();
	_stack.pop();
	long vall = _stack.top();
	_stack.pop();
	long res = -1;

	if (op == '/' && valr == 0)
		throw(std::logic_error("the universe will explode"));
	if (op == '+')
		res = vall + valr;
	if (op == '-')
		res = vall - valr;
	if (op == '*')
		res = vall * valr;
	if (op == '/')
		res = vall / valr;


	if (res > INT_MAX|| res < INT_MIN)
		throw(std::overflow_error("result bigger than int"));

	_stack.push(res);
}

void	RPN::token_extract(const std::string &str)
{
	std::stringstream ss(str);
	std::string token;
	
	if (str.empty() || str.find_first_not_of(" \t") == std::string::npos)
		throw(std::invalid_argument("empty or whitespace-only input"));
	while (ss >> token)
	{
		if (valid_op(token) != 'f') //if op
		{
			if (_stack.size() >= 2)
				math(token[0]);
			else
				throw(std::logic_error("not enough digits for op"));
		}
		else
		{
			int digit = valid_digit(token);
			if (digit == 11) //if not single digit
				throw(std::invalid_argument("invalid argument: " + token));
			_stack.push(digit);
		}
	}
	if (_stack.size() != 1)
		throw(std::runtime_error("wrong stack-count at end of operation"));
	else
		std::cout << _stack.top() << std::endl;
}