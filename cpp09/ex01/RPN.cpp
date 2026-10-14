#include "RPN.hpp"

rpn::rpn() {}

rpn::rpn(const rpn &cpyfrom)
{
	_stack = cpyfrom._stack;
	// std::cout << "copy constructor has been called\n";
}

rpn &rpn::operator=(const rpn &cpyfrom)
{
	if (this != &cpyfrom)
	{
		_stack = cpyfrom._stack;
	}
	// std::cout << "assignment operator has been called\n";
	return (*this);
}

rpn::~rpn() {}

int	rpn::valid_digit(std::string token)
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

char	rpn::valid_op(std::string token)
{
	char c = token[0];
	if (token.size() > 1)
		return 'f';
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return c;
	return 'f';
}

void	rpn::math(char op)
{
	int valr = _stack.top();
	_stack.pop();
	int vall = _stack.top();
	_stack.pop();
	int res = -1;

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
	_stack.push(res);
}

void	rpn::token_extract(std::string str)
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