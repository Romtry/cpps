/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 09:38:54 by rothiery          #+#    #+#             */
/*   Updated: 2025/06/12 12:09:16 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	this->_name = "ClapTrap";
	this->_attackDamage = 0;
	this->_energyPoints = 10;
	this->_hitPoints = 10;
	std::cout << this->_name << " has been created" << std::endl;
}

ClapTrap::ClapTrap(std::string Name)
	:	_name(Name)
{
	this->_attackDamage = 0;
	this->_energyPoints = 10;
	this->_hitPoints = 10;
	std::cout << this->_name << " has been created" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << this->_name << " destructed" << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << this->_name << " is dead, dead ClapTrap cant attack" << std::endl;
		return ;
	}
	else if (this->_energyPoints <= 0)
	{
		std::cout << this->_name << " has not enought energy for attack" << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << this->_name << " attack " << target << " with " << this->_attackDamage << " damages " << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << this->_name << " is dead, dead ClapTrap cant take damages" << std::endl;
		return ;
	}
	this->_hitPoints -= amount;
	std::cout << this->_name << " took " << amount << " damages" << std::endl;
	if (this->_hitPoints <= 0)
	{
		std::cout << this->_name << " is now dead" << std::endl;
		return ;
	}
	std::cout << this->_name << " now have " << this->_hitPoints << " hitPoints" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << this->_name << " dont have enought energy to repaired himself" << std::endl;
		return ;
	}
	this->_hitPoints += amount;
	this->_energyPoints--;
	std::cout << this->_name << " repaired " << amount << " hitPoints" << std::endl;
}
