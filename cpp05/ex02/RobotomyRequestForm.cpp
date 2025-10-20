#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm(target, 72, 45)
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &original)
	: AForm("RobotomyRequestForm", 72, 45)
{
	this->setSign(original.getSign());
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &original)
{
	this->setSign(original.getSign());
	std::cout << "RobotomyRequestForm = operator called" << std::endl;
	return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat &b) const
{
	if (this->getSign() == false)
		throw (GradeTooHighException());
	if (b.getGrade() > this->getGradeExec())
		throw (GradeExecTooHigh());
	bool randomNum = rand() % 1;
	if (randomNum == true)
		std::cout << b.getName() << " has been robotomized" << std::endl;
	else
		std::cout << b.getName() << " robotomy failed" << std::endl;
}
