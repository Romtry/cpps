# pragma once

# include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &original);
		~PresidentialPardonForm();
		PresidentialPardonForm &operator=(const PresidentialPardonForm &original);
		void execute(const Bureaucrat &b) const;
};
