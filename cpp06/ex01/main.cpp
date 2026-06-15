#include "Serializer.hpp"

int main(void)
{
	Data data;
	data.name = "test";

	std::cout << "Data's name is : " << data.name << "\n";
	std::cout << "Original address of Data: " << &data << "\n";
	uintptr_t saddress = Serializer::serialize(&data);
	std::cout << "Serialized address of Data: " << saddress << "\n";

	Data* deserial = Serializer::deserialize(saddress);
	std::cout << "Deserialized address of Data: " << deserial << "\n";

	std::cout << "Data's name is still: " << deserial->name << "\n";
	return 0;
}