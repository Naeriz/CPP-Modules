#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*horde = new Zombie[N];
	for(int i = 0; i < N; i++) //creation, condition, action
	{
		horde[i].setName(name);
	}
	return (horde); //returns first ptr by default
}
