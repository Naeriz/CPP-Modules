#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm& cpyfrom);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& cpyfrom);
		virtual ~RobotomyRequestForm();

		void execute(const Bureaucrat &executor) const;
};