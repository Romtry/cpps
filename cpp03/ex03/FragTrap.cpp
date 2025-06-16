/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:11:17 by rothiery          #+#    #+#             */
/*   Updated: 2025/06/12 14:48:37 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
	:	ClapTrap()
{
	this->_name = "FragTrap";
	this->_attackDamage = 30;
	this->_energyPoints = 100;
	this->_hitPoints = 101;
	std::cout << this->_name << " has been created in Fragtrap" << std::endl;
}

FragTrap::FragTrap(std::string Name)
	:	ClapTrap(Name)
{
	this->_name = Name;
	this->_attackDamage = 30;
	this->_energyPoints = 100;
	this->_hitPoints = 100;
	std::cout << this->_name << " has been created in Fragtrap" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << this->_name << " FragTrap destructed" << std::endl;
}

void	FragTrap::highFivesGuys()
{
	std::cout << this->_name << " asking high-five" << std::endl;
}
