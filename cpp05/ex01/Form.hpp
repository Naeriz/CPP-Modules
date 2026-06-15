#pragma once

#include <string>
#include <iostream>

class Bureaucrat; //why forward declaration needed

class Form
{
	private:
		const std::string _name;
		bool	_signed;
		const int _signg;
		const int _execg;
	public:
		Form();
		Form(const std::string &name, int sg, int eg);
		Form(const Form& cpyfrom);
		Form& operator=(const Form& cpyfrom);
		~Form();

		const std::string	&getName() const;
		bool				getSigned() const;
		int					getSignGrade() const;
		int					getExecGrade() const;
		
		void beSigned(const Bureaucrat &b);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, Form &form);