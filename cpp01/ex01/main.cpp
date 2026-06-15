#include "Zombie.hpp"

int main()
{
	Zombie	*horde = zombieHorde(10, "Karl");
	for(int i = 0; i < 10; i++)
	{
		std::cout << "Karl n°" << i + 1 << std::endl;
		horde[i].announce();
	}

	delete[] (horde);
}
