#pragma once

#include <iostream>
#include <string>

class Bureaucrat
{
	private: 
		const	std::string _name;
		int					_grade;
		void	setGrade(int grade);
	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade); //better way than past
		Bureaucrat(const Bureaucrat& cpyfrom);
		Bureaucrat& operator=(const Bureaucrat& cpyfrom);
		~Bureaucrat();

		const std::string	&getName() const; //const ref so readonly, no const = modifiable in main cuz ref
		int					getGrade() const;

		void				IncGrade();
		void				DecGrade();

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw(); //use of virtual, what()?
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, Bureaucrat *b);
