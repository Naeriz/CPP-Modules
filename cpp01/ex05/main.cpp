#include "Harl.hpp"

int main(void)
{
	Harl	smol_harl;

	smol_harl.complain("debug");
	std::cout << "\n";
	smol_harl.complain("info");
	std::cout << "\n";
	smol_harl.complain("warning");
	std::cout << "\n";
	smol_harl.complain("error");
	std::cout << "\n";
	smol_harl.complain("debuggus");
	return (0);
}