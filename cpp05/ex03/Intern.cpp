#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &cpyfrom)
{
	if (this != &cpyfrom)
		*this = cpyfrom;
}

Intern	&Intern::operator=(const Intern &cpyfrom)
{
	if (this != &cpyfrom)
		*this = cpyfrom;
	return (*this);
}

Intern::~Intern() {}

AForm	*ShrubberyForm(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*RobotomyForm(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*PresidentForm(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

//harl
AForm	*Intern::makeForm(const std::string &name, const std::string &target)
{
	AForm *(*list_forms[])(const std::string &target) = {&ShrubberyForm, &RobotomyForm, &PresidentForm};
	std::string list[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

	int	i = 0;
	while (i < 3)
	{
		if (name == list[i])
		{
			std::cout << "Intern creates " << name << " now\n";
			return (list_forms[i](target));
		}
		i++;
	}
	std::cout << "Intern couldnt find any form called " << name << " in the database.\n";
	return (NULL);
}