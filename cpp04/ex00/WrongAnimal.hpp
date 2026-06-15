#pragma once

#include <iostream>
#include <string>

class WrongAnimal{
	protected: 
		std::string _type;
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal& cpyfrom);
		WrongAnimal& operator=(const WrongAnimal& cpyfrom);
		virtual ~WrongAnimal();
		void makeSound() const;
		std::string getType() const;
};