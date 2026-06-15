#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap b("Scav");
	b.attack("victim");
	ScavTrap c("Miguel");
	b = c;
	b.takeDamage(11);
	b.guardGate();
	b.beRepaired(5);
}

// int	main(void)
// {
// 	int e = 50;
// 	ScavTrap a("Scav");
// 	while (e > 0)
// 	{
// 		a.attack("victim");
// 		e--;
// 	}
// 	a.takeDamage(5);
// 	a.beRepaired(1);
// 	a.attack("victim");
// }

// int main(void)
// {
// 	ScavTrap a("Scav");
// 	a.beRepaired(1);
// 	a.takeDamage(999);
// 	a.attack("victim");
// }

// int main(void)
// {
// 	ScavTrap a("Scav");
// 	ClapTrap b("Clip");
// 	b = a;
// 	ScavTrap c(a);
// 	b.attack("Clip"); //should copy name but not funcs
// 	c.attack("Clip"); //both should show Scav as name
// }