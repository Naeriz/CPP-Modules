#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain has been constructed\n";
}

Brain::Brain(const Brain&  cpyfrom)
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = cpyfrom._ideas[i];
	std::cout << "Copy constructor has been called\n";
}

Brain	&Brain::operator=(const Brain& cpyfrom)
{
	if (this != &cpyfrom)
	{
		for (int i = 0; i < 100; i++)
		_ideas[i] = cpyfrom._ideas[i];
	}
	std::cout << "assignment operator has been called\n";
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain has been destructed\n";
}

void Brain::setIdea(std::string idea, int index)
{
	if (index >= 0 && index < 100)
		_ideas[index] = idea;
}

std::string Brain::getIdea(int index)
{
	if (_ideas[index].empty())
		return ("");
	return (_ideas[index]);
}