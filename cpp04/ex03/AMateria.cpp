/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 09:49:35 by rothiery          #+#    #+#             */
/*   Updated: 2025/07/04 08:50:55 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	this->_equiped = false;
	std::cout << "Materia constructor called" << std::endl;
}

AMateria::AMateria(AMateria &original)
{
	this->_equiped = false;
	this->_type = original._type;
	std::cout << "Materia copy constructor called" << std::endl;
}

AMateria::AMateria(const std::string &type)
{
	this->_equiped = false;
	this->_type = type;
	std::cout << "Materia " << this->_type << " type constructed" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "Destructor called" << std::endl;
}

AMateria	&AMateria::operator=(AMateria &original)
{
	this->_type = original._type;
	std::cout << "AMateria = operator called" << std::endl;
	return (*this);
}

const std::string	&AMateria::geType() const
{
	return (this->_type);
}

void	AMateria::use(ICharacter &target)
{
	(void)target;
}

bool	AMateria::get_equiped()
{
	return (this->_equiped);
}

void	AMateria::set_equiped()
{
	this->_equiped = true;
}
