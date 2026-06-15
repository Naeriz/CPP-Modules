#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Intern		intern;
	AForm		*form;
	Bureaucrat	bureaucrat("John", 45);

	form = intern.makeForm("ShrubberyCreationForm", "Garden");
	if (form)
	{
		delete form;
	}

	std::cout << "\n";
	form = intern.makeForm("RobotomyRequestForm", "Bender");
	if (form)
	{
		try
		{
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << "\n";
		}
		delete form;
	}

	std::cout << "\n";
	form = intern.makeForm("PresidentialPardonForm", "Zaphod");
	if (form)
	{
		delete form;
	}

	std::cout << "\n";
	form = intern.makeForm("UnknownForm", "Target");
	if (form)
	{
		delete form;
	}

	return 0;
}
