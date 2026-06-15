#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Serializer default has been contstructed\n";
}

Serializer::Serializer(const Serializer& cpyfrom)
{
	(void) cpyfrom;
	std::cout << "Copy constructor has been called\n";
}

Serializer &Serializer::operator=(const Serializer& cpyfrom)
{
	(void) cpyfrom;
	std::cout << "Assignment operator has been called\n";
	return (*this);
}

Serializer::~Serializer()
{
	std::cout << "Serialzer has been destructed\n";
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}