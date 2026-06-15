#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
}
void	Harl::info(void)
{
	std::cout << "[ INFO ]\n";
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}
void	Harl::warning(void)
{
	std::cout << "[ WARNING ]\n";
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.\n";
}
void	Harl::error(void)
{
	std::cout << "[ ERROR ]\n";
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void	Harl::complain(std::string level)
{
	std::string diwe[4] = {"debug", "info", "warning", "error"}; //same as char **
	void (Harl::*harlus[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error}; //harlus ptr cuz mem funcs are &
	//void cuz all ret nothing, empty scopes cuz they dont take any params
	int i = 0;
	while(i < 4)
	{
		if (diwe[i] == level)
		{
			(this->*harlus[i])(); //this means this harlus that called complain will call function in harlus[i] | uses * to strip & | () cuz void no params
			return ;
		}
		i++;
	}
	std::cout << "Simple harl cannot comprehend nor fathom thy intentions.\n";
}
