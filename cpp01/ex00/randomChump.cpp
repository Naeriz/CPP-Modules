#include "Zombie.hpp"

void	randomChump(std::string name)//stack
{
	Zombie newZombie(name);
	newZombie.announce();
}
