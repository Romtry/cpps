/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:56:53 by rothiery          #+#    #+#             */
/*   Updated: 2025/06/12 12:10:56 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	_name = "ScavTrap";
	this->_attackDamage = 20;
	this->_energyPoints = 50;
	this->_hitPoints = 100;
	std::cout << this->_name << " has been created in scavtrap" << std::endl;
}

ScavTrap::ScavTrap(std::string Name)
	:	ClapTrap(Name)
{
	this->_name = Name;
	this->_attackDamage = 20;
	this->_energyPoints = 50;
	this->_hitPoints = 100;
	std::cout << this->_name << " has been created in scavtrap" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_hitPoints <= 0)
	{
		std::cout << this->_name << " is dead, dead ScavTrap cant attack" << std::endl;
		return ;
	}
	else if (this->_energyPoints <= 0)
	{
		std::cout << this->_name << " has not enought energy for the ScavTrap to attack" << std::endl;
		return ;
	}
	this->_energyPoints--;
	std::cout << this->_name << " ScavTrap attack " << target << " with " << this->_attackDamage << " damages " << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << this->_name << " is in gate keeper mode" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << this->_name << " scavtrap destructed" << std::endl;
}
