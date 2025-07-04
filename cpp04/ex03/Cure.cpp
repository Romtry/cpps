/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:26:30 by rothiery          #+#    #+#             */
/*   Updated: 2025/07/02 14:26:14 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
	this->_type = "cure";
	std::cout << "Cure construtor called" << std::endl;
}

Cure::Cure(Cure &original)
{
	this->_type = original._type;
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}

Cure	&Cure::operator=(Cure &original)
{
	this->_type = original._type;
	return (*this);
}

AMateria	*Cure::clone() const
{
	Cure *clone = new Cure();
	return (clone);
}

void		Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
