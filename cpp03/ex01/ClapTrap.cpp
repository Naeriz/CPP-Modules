#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _Name("default"), _hp(10), _energy(10), _ad(0) 
{
	std::cout << "ClapTrap default has been constructed\n";
}

ClapTrap::ClapTrap(std::string Name) : _Name(Name), _hp(10), _energy(10), _ad(0) 
{
	std::cout << "ClapTrap " << _Name << " has been constructed\n";
}

ClapTrap::ClapTrap(const ClapTrap& cpyfrom)
{
	_Name = cpyfrom._Name;
	_hp = cpyfrom._hp;
	_energy = cpyfrom._energy;
	_ad = cpyfrom._ad;
	std::cout << "Copy constructor has been called\n";
}

ClapTrap	&ClapTrap::operator=(const ClapTrap& cpyfrom)
{
	_Name = cpyfrom._Name;
	_hp = cpyfrom._hp;
	_energy = cpyfrom._energy;
	_ad = cpyfrom._ad;
	std::cout << "assignment operator has been called\n";
	return (*this);
}

ClapTrap::~ClapTrap() 
{
	std::cout << "ClapTrap has been destructed\n";
}

void	ClapTrap::attack(const std::string& target)
{
	if (_hp == 0)
		std::cout << BLUE <<  _Name << " is already dead :(" << RESET << "\n";
	else if (_energy != 0 && _hp > 0)
	{
		std::cout << RED << _Name << " attacks " << target << ", causing " << _ad << " points of damage!" << RESET << "\n";
		_energy--;
	}
	else if (_energy == 0)
		std::cout << BLUE <<  _Name << " is too tired to attack" << RESET << "\n";
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hp == 0)
		std::cout << BLUE <<  _Name << " is already dead :(" << RESET << "\n";
	else if ((unsigned int)_hp >= amount)
	{
		std::cout << MAG << _Name << " takes " << amount << " points of damage!" << RESET << "\n";
		_hp -= amount;
	}
	else if (amount > (unsigned int)_hp)
	{
		std::cout << BLUE << _Name << " has succumbed to its injuries" << RESET << "\n";
		_hp = 0;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_hp == 0)
		std::cout << BLUE <<  _Name << " is already dead :(" << RESET << "\n";
	else if (_hp == 10)
	{
		std::cout << GREEN << _Name << " does not need repair" << RESET << "\n";
		return ;
	}
	else if (_energy != 0 && _hp > 0)
	{
		//10hp limit removed due to constraints (no override or max_hp allowed), simpler so works for all
		std::cout << GREEN << _Name << " repairs itself for " << amount << " points" << RESET << "\n";
		_hp += amount;
		_energy--;
	}
	else if (_energy == 0)
		std::cout << BLUE << _Name << " is too tired to repair" << RESET << "\n";
}