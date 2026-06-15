#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	FragTrap b("Frag");
	b.attack("victim");
	b.highFivesGuys();
	b.takeDamage(111);
	b.beRepaired(5);
}

// int	main(void)
// {
// 	int e = 100;
// 	FragTrap a("Frag");
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
// 	FragTrap a("Frag");
// 	a.beRepaired(1);
// 	a.takeDamage(999);
// 	a.attack("victim");
// }

// int main(void)
// {
// 	FragTrap a("Frag");
// 	ClapTrap b("Clip");
// 	b = a;
// 	ClapTrap c(a); //clap can copy all as parent but frag/scav only own offspring
// 	b.attack("Clip"); //should copy name but not funcs
// 	c.attack("Clip"); //both should show Frag as name
// }