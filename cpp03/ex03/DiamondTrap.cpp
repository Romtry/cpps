/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 09:09:20 by rothiery          #+#    #+#             */
/*   Updated: 2025/06/16 12:42:08 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
	:	ClapTrap("DiamondTrap_clap_name"), ScavTrap(), FragTrap()
{
	this->_name = "DiamondTrap";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(std::string name)
	:	ClapTrap(), ScavTrap(), FragTrap()
{
	ClapTrap::_name = name + "_clap_name";
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << this->_name << " DiamondTrap destructed" << std::endl;
}

void	DiamondTrap::whoami()
{
	std::cout << "DiamondTrap name = " << _name << std::endl;
	std::cout << "ClapTrap name = " << ClapTrap::_name << std::endl;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
} 
