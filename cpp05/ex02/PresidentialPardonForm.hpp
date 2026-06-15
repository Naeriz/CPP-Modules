#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm& cpyfrom);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& cpyfrom);
		virtual ~PresidentialPardonForm();

		void execute(const Bureaucrat &executor) const;
};