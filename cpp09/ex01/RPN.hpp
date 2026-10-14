#include <stdexcept>
#include <iostream>
#include <string>
#include <sstream>
#include <stack>

class rpn
{
	private:
		std::stack<int> _stack;

		int		valid_digit(std::string token);
		char	valid_op(std::string token);
		void	math(char op);
	public:
		rpn();
		rpn(const rpn &cpyfrom);
		rpn& operator=(const rpn &cpyfrom);
		~rpn();
		void	token_extract(std::string str);
} ;