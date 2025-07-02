/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:19:26 by rothiery          #+#    #+#             */
/*   Updated: 2025/06/30 12:42:18 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	this->type = "ice";
	std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(Ice &original)
{
	this->type = original.type;
	std::cout << "Ice copy constructor called" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
}

Ice	&Ice::operator=(Ice &original)
{
	this->type = original.type;
}

AMateria	*Ice::clone() const
{
	Ice *clone = new Ice();
	return (clone);
}

void		use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

void	Ice::AMateria::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
