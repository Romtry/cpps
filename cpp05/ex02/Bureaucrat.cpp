/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 09:13:38 by rothiery          #+#    #+#             */
/*   Updated: 2025/08/11 12:48:46 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, short Grade)
	: _name(name), _grade(Grade)
{
	std::cout << "Bureaucrat constructor called " << this->_name << " created" << std::endl;
	if (Grade < 1)
		throw (GradeTooHighException());
	else if (Grade > 150)
		throw (GradeTooLowException());
}

Bureaucrat::Bureaucrat(const Bureaucrat &original)
	: _name(original._name), _grade(original._grade)
{
	std::cout << "Bureaucrat copy constructor called " << this->_name << " created" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

short	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

void Bureaucrat::incrementGrade()
{
	try
	{
		if (this->_grade <= 1)
			throw(GradeTooLowException());
		else
			this->_grade--;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void Bureaucrat::decrementGrade()
{
	try
	{
		if (this->_grade >= 150)
			throw(GradeTooLowException());
		else
			this->_grade++;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void Bureaucrat::signForm(Form f) const
{
	f.beSigned(*this);
}


const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("GradeTooHighException called grade is now 1");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("GradeTooLowException called grade is now 150");
}

std::ostream		&operator<<(std::ostream& os, const Bureaucrat &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
	return (os);
}
