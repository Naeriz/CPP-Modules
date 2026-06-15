#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap a("Clap");
	a.attack("victim");
	a.takeDamage(8);
	a.beRepaired(8);
}

// int	main(void)
// {
// 	ClapTrap a("Clap");
// 	a.attack("victim");
// 	a.attack("victim");
// 	a.attack("victim");
// 	a.attack("victim");
// 	a.attack("victim");
// 	a.attack("victim");
// 	a.attack("victim");
// 	a.attack("victim");
// 	a.attack("victim");
// 	a.attack("victim");
// 	a.takeDamage(5);
// 	a.beRepaired(1);
// 	a.attack("victim");
// }

// int main(void)
// {
// 	ClapTrap a("Clap");
// 	a.beRepaired(1000);
// 	a.takeDamage(999);
// 	a.attack("victim");
// }

// int main(void)
// {
// 	ClapTrap a("Clap");
// 	ClapTrap b("Clip");
// 	b = a;
// 	ClapTrap c(a);
// 	b.attack("Clip");
// 	c.attack("Clip"); //both should show clap as name
// }