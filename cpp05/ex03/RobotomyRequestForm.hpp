# pragma once

# include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &original);
		~RobotomyRequestForm();
		RobotomyRequestForm &operator=(const RobotomyRequestForm &original);
		void execute(const Bureaucrat &b) const;
};
