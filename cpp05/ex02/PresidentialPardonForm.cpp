#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5),  _target("Default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5),  _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cpyfrom) : AForm(cpyfrom), _target(cpyfrom._target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &cpyfrom) 
{
    if (this != &cpyfrom) {
        AForm::operator=(cpyfrom);
        _target = cpyfrom._target;
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const 
{
    if (!getSigned()) 
	{
        throw NotSignedException();
    }
    if (executor.getGrade() > getExecGrade())
	{
        throw GradeTooLowException();
    }
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox\n";
}