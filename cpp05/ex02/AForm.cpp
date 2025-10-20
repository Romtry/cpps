#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string &name, const short grade_sign, const short grade_exec)
	: _signed(false), _grade_sign(grade_sign), _grade_exec(grade_exec), _name(name)
{
	std::cout << "Form constructor called " << this->_name << " created with grade_exec : " << this->_grade_exec << std::endl;
	if (grade_exec < 1 || grade_sign < 1)
		throw (GradeTooHighException());
	if (grade_exec > 150 || grade_sign > 150)
		throw (GradeTooLowException());
}

AForm::AForm(const AForm &original)
: _signed(original.getSign()), _grade_sign(original.getGradeSign()), _grade_exec(original.getGradeExec()), _name(original.getName())
{
	std::cout << "Form copy constructor called " << this->_name << " created with grade_exec : " << this->_grade_exec << std::endl;
}

AForm::~AForm()
{
	std::cout << "Form destructor called" << std::endl;
}

short	AForm::getGradeSign() const
{
	return (this->_grade_sign);
}

short	AForm::getGradeExec() const
{
	return (this->_grade_exec);
}

bool AForm::getSign() const
{
	return (this->_signed);
}

std::string AForm::getName() const
{
	return (this->_name);
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= this->_grade_sign)
	{
		this->_signed = true;
		std::cout << b.getName() << " signed " << this->getName() << std::endl;
	}
	else
	{
		std::cout << b.getName() << " couldn't sign " << this->getName() << " because " << std::endl;
		throw (GradeTooLowException());
	}
}

void AForm::setSign(const bool s)
{
	this->_signed = s;
}

const char *AForm::FormNotSign::what() const throw()
{
	return ("Form not signed");
}

const char *AForm::GradeExecTooHigh::what() const throw()
{
	return ("Bureaucrat grade too low for exec");
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("GradeTooHighException");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("GradeTooLowException");
}

std::ostream		&operator<<(std::ostream& os, const AForm &f)
{
	if (f.getSign())
		std::cout << f.getName() << " is signed";
	else
		std::cout << f.getName() << " is not signed";

	os << ", Form grade sign is " << f.getGradeSign() << " and grade exec is " << f.getGradeExec() << std::endl;
	return (os);
}
