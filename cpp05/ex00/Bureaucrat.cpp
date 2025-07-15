/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 09:13:38 by rothiery          #+#    #+#             */
/*   Updated: 2025/07/15 10:12:21 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string &name, short Grade)
	: Name(name), Grade(Grade)
{
	std::cout << "Bureaucrat constructor called " << this->Name << " created" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat &original)
	: Name(original.Name), Grade(original.Grade)
{
	std::cout << "Bureaucrat copy constructor called " << this->Name << " created" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

short	Bureaucrat::getGrade()
{
	return (this->Grade);
}

std::string	Bureaucrat::getName()
{
	return (this->Name);
}

void	Bureaucrat::GradeTooHighException()
{
	this->Grade = 1;
	std::cout << "GradeTooHighException called grade is now 1" << std::endl;
}

void	Bureaucrat::GradeTooLowException()
{
	this->Grade = 150;
	std::cout << "GradeToolowException called grade is now 150" << std::endl;
}
