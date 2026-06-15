#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	Bureaucrat	bob("Bob", 1);
	Bureaucrat	john("John", 150);

	try
	{
		PresidentialPardonForm form1("Alice");
		john.signForm(form1);
		john.executeForm(form1);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << "\n";
	}

	std::cout << "\n";

	try
	{
		RobotomyRequestForm form2("Charlie");
		bob.signForm(form2);
		bob.executeForm(form2);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << "\n";
	}

	std::cout << "\n";

	try
	{
		ShrubberyCreationForm form3("Garden");
		bob.signForm(form3);
		bob.executeForm(form3);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << "\n";
	}

	return 0;
}