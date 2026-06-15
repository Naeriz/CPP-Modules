#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpyfrom) : AForm(cpyfrom), _target(cpyfrom._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &cpyfrom) 
{
    if (this != &cpyfrom) {
        AForm::operator=(cpyfrom);
        _target = cpyfrom._target;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const 
{
    if (!getSigned()) 
	{
        throw NotSignedException();
    }
    if (executor.getGrade() > getExecGrade())
	{
        throw GradeTooLowException();
    }
    std::cout << "Creating shrubbery in file " << _target + "_shrubbery\n";
	std::ofstream file;
	file.open((_target + "_shrubbery").c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: Could not open file for writing.\n";
		return;
	}
	file << "     @\n";
	file << "    /*\\\n";
	file << "   /***\\\n";
	file << "  /*****\\\n";
	file << " /*******\\\n";
	file << "/*********\\\n";
	file << "   |||||\n";
	file << "   |||||\n";
	file.close();
}