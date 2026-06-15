#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm& cpyfrom);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& cpyfrom);
		virtual ~ShrubberyCreationForm();

		void execute(const Bureaucrat &executor) const;
};