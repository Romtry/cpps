/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 12:44:41 by rothiery          #+#    #+#             */
/*   Updated: 2025/07/04 10:09:08 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <sstream>

Character::Character()
{
	std::ostringstream test;
	static int number = 0;

	for (unsigned int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	for (unsigned int i = 0; i < 4; i++)
		this->_floor[i] = NULL;
	number++;
	test << "Player " << number;
	this->_name = test.str();
	std::cout << "Character constructor called" << std::endl;
}

Character::Character(Character &original)
{
	for (unsigned int i = 0; i < 4; i++)
		this->_inventory[i] = original._inventory[i]->clone();
	for (unsigned int i = 0; i < 4; i++)
		this->_floor[i] = NULL;
	this->_name = original._name;
	std::cout << "Character copy constructor called" << std::endl;
}

Character::Character(std::string Name)
{
	for (unsigned int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	for (unsigned int i = 0; i < 4; i++)
		this->_floor[i] = NULL;
	this->_name = Name;
}

Character::~Character()
{
	for (unsigned int i = 0; this->_floor[i]; i++)
	{
		delete this->_floor[i];
	}
	for (unsigned int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
	std::cout << this->_name << " destructor called" << std::endl;
}

Character	&Character::operator=(Character &original)
{
	for (unsigned int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
	for (unsigned int i = 0; i < 4; i++)
	{
		if (original._inventory[i])
			this->_inventory[i] = original._inventory[i]->clone();
	}
	this->_name = original._name;
	return (*this);
}

const std::string	&Character::getName() const
{
	return (this->_name);
}

void	Character::equip(AMateria *m)
{
	if (!m)
		return;
	else if (m->get_equiped() ==  true)
	{
		std::cout << "this materia is already equiped !" << std::endl;
		return;
	}
	for (unsigned int i = 0; i < 4; i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			m->set_equiped();
			return;
		}
	}
}

void	Character::unequip(int idx)
{
	if (this->_inventory[idx])
	{
		this->_floor[this->_count] = this->_inventory[idx];
		this->_count++;
	}
}

void	Character::use(int idx, ICharacter &target)
{
	if (!this->_inventory[idx])
		return;
	this->_inventory[idx]->use(target);
}
