#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45),  _target("Default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpyfrom) : AForm(cpyfrom), _target(cpyfrom._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &cpyfrom) 
{
    if (this != &cpyfrom) {
        AForm::operator=(cpyfrom);
        _target = cpyfrom._target;
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const 
{
	srand(time(0)); //seed
    if (!getSigned()) 
	{
        throw NotSignedException();
    }
    if (executor.getGrade() > getExecGrade())
	{
        throw GradeTooLowException();
    }
	std::cout << "DrrrRRRRRRrrrrRRrRRRRr...\n";
	if (rand() % 2)
		std::cout << _target << " drrr..got successfully robotomized :)\n";
	else
		std::cout  << "...dr?.. " << _target << "'s robotomy failed :(\n";
}