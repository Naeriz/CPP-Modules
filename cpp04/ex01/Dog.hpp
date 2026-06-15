#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal{
	private: 
		Brain* _brain;
	public:
		Dog();
		Dog(std::string _type);
		Dog(const Dog& cpyfrom);
		Dog& operator=(const Dog& cpyfrom);
		~Dog();
		void makeSound() const;
		Brain *getBrain() const;
};