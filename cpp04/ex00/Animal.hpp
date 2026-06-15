#pragma once

#include <iostream>
#include <string>

class Animal{
	protected: 
		std::string _type;
	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal& cpyfrom);
		Animal& operator=(const Animal& cpyfrom);
		virtual ~Animal();
		virtual void makeSound() const;
		std::string getType() const;
};