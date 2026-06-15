#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
	public:
		WrongCat();
		WrongCat(std::string _type);
		WrongCat(const WrongCat& cpyfrom);
		WrongCat& operator=(const WrongCat& cpyfrom);
		~WrongCat();
		void makeSound() const;
};