#pragma once

#include "Animal.hpp"

class Cat : public Animal{
	public:
		Cat();
		Cat(std::string _type);
		Cat(const Cat& cpyfrom);
		Cat& operator=(const Cat& cpyfrom);
		~Cat();
		void makeSound() const;
};