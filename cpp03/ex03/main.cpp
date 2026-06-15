#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	d("Dia");
	d.attack("victim");
	d.guardGate();
	d.whoAmI();
	d.highFivesGuys();
}

// int	main(void)
// {
// 	DiamondTrap c("Diamond");
// 	c.attack("victim");
// 	c.takeDamage(8);
// 	c.beRepaired(5);
// 	c.whoAmI();
// 	c.showStats();
// }

// int	main(void)
// {
// 	int e = 50;
// 	DiamondTrap a("Dia");
// 	while (e > 0)
// 	{
// 		a.attack("victim");
// 		e--;
// 	}
// 	a.takeDamage(2);
// 	a.beRepaired(1);
// 	a.attack("victim");
// }

// int main(void)
// {
// 	DiamondTrap a("Dia");
// 	a.takeDamage(999);
// 	a.attack("victim");
// }

// int main(void)
// {
// 	DiamondTrap a("Dia");
// 	DiamondTrap b("Clip");
// 	b = a;
// 	DiamondTrap c(a);
// 	b.attack("Clip"); 
// 	c.attack("Clip");
// }