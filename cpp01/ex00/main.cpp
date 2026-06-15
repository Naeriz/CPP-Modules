#include "Zombie.hpp"

int main()
{
	randomChump("Karl");
	Zombie *Juan = newZombie("Juan");
	Juan->announce();
	
	delete Juan;
	return 0;
}
//destructor procs after delte insteadof return bcs it does that w delete yis
//karl dies once the function exits and is no ptr= stack = no delte needed
//juan is ptr = heap = delete needed or leaks
//karl automatically gets deleted bcs no ptr