#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	*a = new Bureaucrat("Alice", 50);
	Bureaucrat	*b = new Bureaucrat("Bob", 100);
	Form		form("s1106", 50, 4);

	try
	{
		b->signForm(form);
	}
	catch (const std::exception &e)
	{
		std::cerr << b->getName() << " failed to sign " << form.getName() << ": " << e.what() << "\n";
	}

	try
	{
		a->signForm(form);
	}
	catch (const std::exception &e)
	{
		std::cerr << a->getName() << " failed to sign " << form.getName() << ": " << e.what() << "\n";
	}

	std::cout << a << "\n";
	std::cout << b << "\n";
	std::cout << form << "\n";

	delete a;
	delete b;

	return 0;
}