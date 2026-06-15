#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Basic"), _signed(false), _signg(150), _execg(1)
{
		std::cout << "AForm default has been constructed\n";
}

AForm::AForm(const std::string &name, int signg, int execg) : _name(name), _signed(false), _signg(signg), _execg(execg)
{
	if (signg < 1 || execg < 1)
		throw AForm::GradeTooHighException();
	if (signg > 150 || execg > 150)
		throw AForm::GradeTooLowException();
	std::cout << *this << "\n";
}

AForm::AForm(const AForm &cpyfrom) : _name(cpyfrom._name), _signed(cpyfrom._signed), _signg(cpyfrom._signg), _execg(cpyfrom._execg)
{
	std::cout << "Copy constructor has been called\n";
}

AForm &AForm::operator=(const AForm& cpyfrom)
{
	if (this != &cpyfrom)
		_signed = cpyfrom.getSigned();
	std::cout << "assignment operator has been called\n";
	return (*this);
}

AForm::~AForm()
{}

const std::string &AForm::getName() const
{
	return (_name);
}

bool	AForm::getSigned() const
{
	return (_signed);
}

int AForm::getSignGrade() const
{
	return (_signg);
}

int AForm::getExecGrade() const
{
	return (_execg);
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
}

const char *AForm::NotSignedException::what(void) const throw()
{
	return ("Form wasn't signed");
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _signg)
		throw AForm::GradeTooLowException();
	_signed = true;
	std::cout << "Bureaucrat " << b.getName() << " has signed AForm " << _name << "\n";
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (this->getSigned() == false)
		throw NotSignedException();
	if (executor.getGrade() > this->_execg)
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, AForm &form)
{
	os << "Form: " << form.getName() << ", Signed: ";
	if (form.getSigned())
		os << "Yes";
	else
		os << "No";
	os << ", Sign Grade: " << form.getSignGrade() << ", Execute Grade: " << form.getExecGrade();
	return (os);
}