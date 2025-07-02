/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 09:49:35 by rothiery          #+#    #+#             */
/*   Updated: 2025/06/30 10:11:25 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "Materia constructor called" << std::endl;
}

AMateria::AMateria(AMateria &original)
{
	std::cout << "Materia copy constructor called" << std::endl;
}

AMateria::AMateria(const std::string &type)
{
	this->type = type;
	std::cout << "Materia " << this->type << " type constructed" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "Destructor called" << std::endl;
}

AMateria	&AMateria::operator=(AMateria &original)
{
	this->type = original.type;
	std::cout << "AMateria = operator called" << std::endl;
}

const std::string	&AMateria::geType() const
{
	return (this->type);
}

void	AMateria::use(ICharacter &target)
{
	
}
