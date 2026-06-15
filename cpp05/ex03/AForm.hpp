#pragma once

#include <string>
#include <iostream>

class Bureaucrat; //why forward declaration needed

class AForm
{
	private:
		const std::string _name;
		bool	_signed;
		const int _signg;
		const int _execg;
	public:
		AForm();
		AForm(const std::string &name, int sg, int eg);
		AForm(const AForm& cpyfrom);
		AForm& operator=(const AForm& cpyfrom);
		virtual ~AForm();

		const std::string	&getName() const;
		bool				getSigned() const;
		int					getSignGrade() const;
		int					getExecGrade() const;
		
		void beSigned(const Bureaucrat &b);
		virtual void execute(const Bureaucrat &executor) const = 0;

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

		class	NotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, AForm &form);