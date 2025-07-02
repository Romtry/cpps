/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:26:30 by rothiery          #+#    #+#             */
/*   Updated: 2025/06/30 12:41:44 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
	this->type = "cure";
	std::cout << "Cure construtor called" << std::endl;
}

Cure::Cure(Cure &original)
{
	this->type = original.type;
	std::cout << "Cure copy constructor called" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}

AMateria	*Cure::clone() const
{
	Cure *clone = new Cure();
	return (clone);
}

void		use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Cure	&Cure::operator=(Cure &original)
{
	this->type = original.type;
}
