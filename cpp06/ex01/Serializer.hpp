#pragma once

#include <iostream>
#include <string>
#include <stdint.h>

typedef struct s_data
{
	std::string name;
} Data;

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer& cpyfrom);
		Serializer& operator=(const Serializer& cpyfrom);
		~Serializer();
	public:
		static uintptr_t serialize(Data *ptr);
		static Data* deserialize(uintptr_t raw);
};