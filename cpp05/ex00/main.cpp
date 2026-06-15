#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	*a = new Bureaucrat();
	try
	{
		a->IncGrade();
	}
	catch(const std::exception &e)
	{
		std::cerr << a->getName() << " failed: " << e.what() << "\n";
	}

	std::cout << a << "\n";

	try
	{
		a->DecGrade();
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << a->getName() << " failed: " << e.what() << "\n";
	}

	std::cout << a << "\n";

	try
	{
		a->DecGrade();
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << a->getName() << " failed: " << e.what() << "\n";
	}

	Bureaucrat	*b = new Bureaucrat("Bob", 1);

	try
	{
		b->IncGrade();
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << b->getName() << " failed: " << e.what() << "\n";
	}

	delete a;
	delete b;
}
