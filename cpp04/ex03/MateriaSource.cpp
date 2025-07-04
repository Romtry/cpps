/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:30:15 by rothiery          #+#    #+#             */
/*   Updated: 2025/07/04 09:06:19 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (unsigned int i = 0; i < 4; i++)
		this->_learned[i] = NULL;
	std::cout << "MateriaSource constructor called" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource &original)
{
	for (unsigned int i = 0; i < 4; i++)
		this->_learned[i] = NULL;
	(void)original;
	std::cout << "MateriaSource cpoy constructor called" << std::endl;
}

MateriaSource::~MateriaSource()
{
	for (unsigned int i = 0; i < 4; i++)
	{
		if (this->_learned[i])
			delete this->_learned[i];
	}
	std::cout << "MateriaSource destructor called" << std::endl;
}

MateriaSource	&MateriaSource::operator=(MateriaSource &original)
{
	(void)original;
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *m)
{
	for (unsigned int i = 0; i < 4; i++)
	{
		if (!this->_learned[i])
		{
			this->_learned[i] = m->clone();
			return;
		}
		if (i == 3)
			std::cout << "Learned too many Materias" << std::endl;
	}
}

AMateria	*MateriaSource::createMateria(const std::string &type)
{
	for (unsigned int i = 0; i < 4; i++)
	{
		if (this->_learned[i] && this->_learned[i]->geType() == type)
			return (this->_learned[i]->clone());
		if (i == 3)
			std::cout << "No " << type << " materia learned" << std::endl;
	}
	return (0);
}
