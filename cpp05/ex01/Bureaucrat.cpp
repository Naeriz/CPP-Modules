#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("Intern"), _grade(150) {
	std::cout << "Bureaucrat default has been constructed\n";
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
	std::cout << "Bureaucrat " << _name << " has been constructed\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpyfrom) 
{
	*this = cpyfrom;
	std::cout << "Copy constructor has been called\n";
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat& cpyfrom)
{
	if (this != &cpyfrom)
		_grade = cpyfrom.getGrade();
	std::cout << "assignment operator has been called\n";
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat has been destructed\n";
}

const std::string	&Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const //const ref can look at int but not touch
{
	return (_grade);
}

void	Bureaucrat::IncGrade()
{
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void	Bureaucrat::DecGrade()
{
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

void	Bureaucrat::signForm(Form &form) const
{
	form.beSigned(*this);
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
}


std::ostream& operator<<(std::ostream& os, Bureaucrat *b)
{
	os << b->getName() << ", Bureaucrat grade: " << b->getGrade() << ".";
	return (os);
}