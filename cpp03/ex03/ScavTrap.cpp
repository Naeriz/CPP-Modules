#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	_hp = 100;
	_energy = 50;
	_ad = 20;
	std::cout << "ScavTrap default has been constructed\n";
}

ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name)
{
	_hp = 100;
	_energy = 50;
	_ad = 20;
	std::cout << "ScavTrap " << Name << " has been constructed\n";
}

ScavTrap::ScavTrap(const ScavTrap& cpyfrom) : ClapTrap(cpyfrom) //ScavTrap& gets treated as ClapTrap
{
	//if scavtrap had own private would have to copy manually like before
	std::cout << "Copy constructor has been called\n";
}

ScavTrap	&ScavTrap::operator=(const ScavTrap& cpyfrom)
{
	if (this != &cpyfrom) //good practise
		ClapTrap::operator=(cpyfrom);
	std::cout << "ScavTrap assignment operator has been called\n";
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap has been destructed\n";
}

void ScavTrap::guardGate()
{
	std::cout << _Name << " is in Gatekeeper mode!\n";
}

void	ScavTrap::attack(const std::string& target) //override to slightly change parent function
{
	if (_hp == 0)
		std::cout << BLUE <<  _Name << " is already dead :(" << RESET << "\n";
	else if (_energy != 0 && _hp > 0)
	{
		std::cout << RED << _Name << " swings at " << target << ", causing " << _ad << " massive points of damage!" << RESET << "\n";
		_energy--;
	}
	else if (_energy == 0)
		std::cout << BLUE <<  _Name << " is too tired to attack" << RESET << "\n";
}

//not required only for logic of max hp

// void	ScavTrap::beRepaired(unsigned int amount)
// {
// 	if (_hp == 0)
// 		std::cout << BLUE <<  _Name << " is already dead :(" << RESET << "\n";
// 	else if (_hp == 100)
// 	{
// 		std::cout << GREEN <<  _Name << " does not need repair" << RESET << "\n";
// 		return ;
// 	}
// 	else if (_energy != 0 && _hp > 0)
// 	{
// 		std::cout << GREEN <<  _Name << " repairs itself for " << amount << " points" << RESET << "\n";
// 		_hp += amount;
// 		_energy--;
// 	}
// 	else if (_energy == 0)
// 		std::cout << BLUE <<  _Name << " is too tired to repair" << RESET << "\n";
// }