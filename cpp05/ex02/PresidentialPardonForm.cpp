#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm(target, 25, 5)
{
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &original)
	: AForm("PresidentialPardonForm", 25, 5)
{
	this->setSign(original.getSign());
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &original)
{
	this->setSign(original.getSign());
	std::cout << "PresidentialPardonForm = operator called" << std::endl;
	return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat &b) const
{
	if (this->getSign() == false)
		throw (GradeTooHighException());
	if (b.getGrade() > this->getGradeExec())
		throw (GradeExecTooHigh());
	std::cout << b.getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
