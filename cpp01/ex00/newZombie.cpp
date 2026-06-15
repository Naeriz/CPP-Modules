#include "Zombie.hpp"

Zombie *newZombie(std::string name)//heap
{
	Zombie *zombie = new Zombie(name);//new = malloc
	return zombie;
}
