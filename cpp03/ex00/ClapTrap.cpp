/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 09:38:54 by rothiery          #+#    #+#             */
/*   Updated: 2025/06/04 12:58:59 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string Name)
	:	_Name(Name)
{
	this->_AttackDamage = 0;
	this->_energyPoints = 10;
	this->_hitPoints = 10;
	std::cout << this->_Name << " has been created" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << this->_Name << " destructed" << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << this->_Name << " is dead, dead ClapTrap cant attack" << std::endl;
		return ;
	}
	else if (this->_energyPoints <= 0)
	{
		std::cout << this->_Name << " has not enought energy for attack" << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << this->_Name << " attack " << target << " with " << this->_AttackDamage << " damages " << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << this->_Name << " is dead, dead ClapTrap cant take damages" << std::endl;
		return ;
	}
	this->_hitPoints -= amount;
	std::cout << this->_Name << " took " << amount << " damages" << std::endl;
	if (this->_hitPoints <= 0)
	{
		std::cout << this->_Name << " is now dead" << std::endl;
		return ;
	}
	std::cout << this->_Name << " now have " << this->_hitPoints << " hitPoints" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << this->_Name << " dont have enought energy to repaired himself" << std::endl;
		return ;
	}
	this->_hitPoints += amount;
	this->_energyPoints--;
	std::cout << this->_Name << " repaired " << amount << " hitPoints" << std::endl;
}
