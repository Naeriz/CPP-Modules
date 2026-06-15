#pragma once

#include "Animal.hpp"

class Dog : public Animal{
	public:
		Dog();
		Dog(std::string _type);
		Dog(const Dog& cpyfrom);
		Dog& operator=(const Dog& cpyfrom);
		~Dog();
		void makeSound() const;
};