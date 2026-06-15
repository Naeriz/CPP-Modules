#pragma once

#include <iostream>
#include <string>

class Brain{
	private:
		std::string _ideas[100];
	public:
		Brain();
		Brain(std::string type);
		Brain(const Brain& cpyfrom);
		Brain& operator=(const Brain& cpyfrom);
		~Brain();
		void setIdea(std::string idea, int index);
		std::string getIdea(int index);
};