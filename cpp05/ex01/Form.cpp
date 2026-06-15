#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Basic"), _signed(false), _signg(150), _execg(1)
{
		std::cout << "Form default has been constructed\n";
}

Form::Form(const std::string &name, int signg, int execg) : _name(name), _signed(false), _signg(signg), _execg(execg)
{
	if (signg < 1 || execg < 1)
		throw Form::GradeTooHighException();
	if (signg > 150 || execg > 150)
		throw Form::GradeTooLowException();
	std::cout << *this << "\n";
}

Form::Form(const Form &cpyfrom) : _name(cpyfrom._name), _signed(cpyfrom._signed), _signg(cpyfrom._signg), _execg(cpyfrom._execg)
{
	std::cout << "Copy constructor has been called\n";
}

Form &Form::operator=(const Form& cpyfrom)
{
	if (this != &cpyfrom)
		_signed = cpyfrom.getSigned();
	std::cout << "assignment operator has been called\n";
	return (*this);
}

Form::~Form()
{
	std::cout << "Form has been destructed\n";
}

const std::string &Form::getName() const
{
	return (_name);
}

bool	Form::getSigned() const
{
	return (_signed);
}

int Form::getSignGrade() const
{
	return (_signg);
}

int Form::getExecGrade() const
{
	return (_execg);
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _signg)
		throw Form::GradeTooLowException();
	_signed = true;
	std::cout << "Bureaucrat " << b.getName() << " signed Form " << _name << "\n";
}

std::ostream &operator<<(std::ostream &os, Form &form)
{
	os << "Form: " << form.getName() << ", Signed: ";
	if (form.getSigned())
		os << "Yes";
	else
		os << "No";
	os << ", Sign Grade: " << form.getSignGrade() << ", Execute Grade: " << form.getExecGrade();
	return (os);
}