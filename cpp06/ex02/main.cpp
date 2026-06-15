#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	srand(time(NULL));
	int random = rand() % 3;
	if (random == 0)
		return (new A);
	if (random == 1)
		return (new B);
	if (random == 2)
		return (new C);
	return (NULL);
}

void identify(Base *p)
{
	if (dynamic_cast<A*> (p)) //same as !- nullptr
		std::cout << "Unknown turns out to be: A\n";
	else if (dynamic_cast<B *>(p))
		std::cout << "Unknown turns out to be: B\n";
	else if (dynamic_cast<C *>(p))
		std::cout << "Unknown turns out to be: C\n";
	else
		std::cout << "Unknown turns out to be: uhh???\n";
}

void identify(Base &p)
{
	static int i = 0;
	try
	{
		if (i == 0)
			dynamic_cast<A&>(p);
		if (i == 1)
			dynamic_cast<B&>(p);
		if (i == 2)
			dynamic_cast<C&>(p);
	}
	catch (std::exception &e) 
	{
		if (i < 2)
		{
			i++;
			identify(p);
			return ;
		}
		else
		{
			std::cout << "Unknown turns out to be: uhh???\n";
			return;
		}
	}
	if (i == 0)
		std::cout << "Unknown turns out to be: A\n";
	if (i == 1)
		std::cout << "Unknown turns out to be: B\n";
	if (i == 2)
		std::cout << "Unknown turns out to be: C\n";
	
}

int main(void)
{
	Base *unknown = generate();

	identify(*unknown);
	identify(unknown);
	delete (unknown);
}