//
// Created by rothiery on 8/25/25.
//

#include "Form.hpp"

Form::Form(const std::string &name, const short grade_sign, const short grade_exec)
	: _signed(false), _grade_sign(grade_sign), _grade_exec(grade_exec), _name(name)
{
	std::cout << "Form constructor called " << this->_name << " created with grade_sign : " << this->_grade_sign << std::endl;
	if (grade_exec < 1 || grade_sign < 1)
		throw (GradeTooHighException());
	if (grade_exec > 150 || grade_sign > 150)
		throw (GradeTooLowException());
}

Form::Form(const Form &original)
: _signed(original.getSign()), _grade_sign(original.getGradeSign()), _grade_exec(original.getGradeExec()), _name(original.getName())
{
	std::cout << "Form copy constructor called " << this->_name << " created with grade_sign : " << this->_grade_sign << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

short	Form::getGradeSign() const
{
	return (this->_grade_sign);
}

short	Form::getGradeExec() const
{
	return (this->_grade_exec);
}

bool Form::getSign() const
{
	return (this->_signed);
}

std::string Form::getName() const
{
	return (this->_name);
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= this->_grade_sign)
	{
		this->_signed = true;
		std::cout << b.getName() << " signed " << this->getName() << std::endl;
	}
	else
	{
		std::cout << b.getName() << " couldn't sign " << this->getName() << " because ";
		throw GradeTooLowException();
	}
}


const char	*Form::GradeTooHighException::what() const throw()
{
	return ("GradeTooHighException");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("GradeTooLowException");
}

std::ostream		&operator<<(std::ostream& os, const Form &f)
{
	if (f.getSign())
		std::cout << f.getName() << " is signed";
	else
		std::cout << f.getName() << " is not signed";

	os << ", Form grade sign is " << f.getGradeSign() << " and grade exec is " << f.getGradeExec() << std::endl;
	return (os);
}
