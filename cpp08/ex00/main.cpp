#include "EasyFind.hpp"
#include <stack>

int main(void)
{
	std::vector<int>	v;
	std::vector<char>	v2;

	v.push_back(1);
	v.push_back(4);
	v2.push_back('a');

	if (easyfind(v, 4) == v.end())
		std::cout << "Could not find the number 4" << std::endl;
	else
		std::cout << "Number 4 found" << std::endl;

	v.pop_back();

	if (easyfind(v, 4) == v.end())
		std::cout << "Could not find the number 4" << std::endl;
	else
		std::cout << "Number 4 found" << std::endl;

	std::cout << std::endl;
	v2.pop_back();

	if (easyfind(v2, 97) == v2.end())
		std::cout << "Could not find the ascii number 97" << std::endl;
	else
		std::cout << "ascii number 97 found" << std::endl;
	if (easyfind(v2, 'a') == v2.end())
		std::cout << "Could not find the letter 'a'" << std::endl;
	else
		std::cout << "Letter 'a' found" << std::endl;

    return 0;
}
