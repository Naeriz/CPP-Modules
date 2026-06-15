#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal{
	private: 
		Brain* _brain;
	public:
		Cat();
		Cat(std::string _type);
		Cat(const Cat& cpyfrom);
		Cat& operator=(const Cat& cpyfrom);
		~Cat();
		void makeSound() const;
		Brain *getBrain() const;
};