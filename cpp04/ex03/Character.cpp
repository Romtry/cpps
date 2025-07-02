/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 12:44:41 by rothiery          #+#    #+#             */
/*   Updated: 2025/07/02 10:15:00 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	static int number = 0;
	number++;
	this->name = "Player " + std::to_string(number);
	std::cout << "Character constructor called" << std::endl;
}

Character::Character(Character &original)
{
	for (unsigned int i = 0; i < 4; i++)
	{
		this->inventory[i] = original.inventory[i]->clone();
	}
	this->name = original.name;
	this->type = original.type;
	std::cout << "Character copy constructor called" << std::endl;
}

Character::~Character()
{
	for (unsigned int i = 0; this->floor[i]; i++)
	{
		delete this->floor[i];
	}
	for (unsigned int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
			delete this->inventory[i];
	}
	std::cout << this->name << " destructor called" << std::endl;
}

const std::string	&Character::getName()
{
	return (this->name);
}

void	Character::equip(AMateria *m)
{
	for (unsigned int i = 0; i < 4; i++)
	{
		if (!this->inventory[i])
		{
			this->inventory[i] = m;
			return;
		}
	}
}

void	Character::unequip(int idx)
{
	if (this->inventory[idx])
	{
		this->floor[count] = this->inventory[idx];
		this->count++;
	}
}

void	Character::use(int idx, ICharacter &target)
{
	if (!this->inventory[idx])
		return;
	this->inventory[idx]->use(target);
}

Character	&Character::operator=(Character &original)
{
	for (unsigned int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
			delete this->inventory[i];
	}
	for (unsigned int i = 0; i < 4; i++)
	{
		if (original.inventory[i])
			this->inventory[i] = original.inventory[i]->clone();
	}
	this->name = original.name;
	this->type = original.type;
}
