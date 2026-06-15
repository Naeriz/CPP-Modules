#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern& cpyfrom);
		Intern& operator=(const Intern& cpyfrom);
		~Intern();

		AForm *makeForm(const std::string &name, const std::string &target);
};