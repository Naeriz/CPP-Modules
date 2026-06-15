#include "Zombie.hpp"

Zombie::Zombie() : _name("Default Zombie") {} //security incase no name given

Zombie::Zombie(std::string name) : _name(name) {}

Zombie::~Zombie()
{
	std::cout << _name << " got blown up :(" << std::endl;
}

void 	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string &new_name)
{
	_name = new_name;
}

std::string Zombie::getName()
{
	return(_name);
}