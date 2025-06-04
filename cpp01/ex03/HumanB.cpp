/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:19:11 by rothiery          #+#    #+#             */
/*   Updated: 2025/05/14 17:02:47 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string &name)
	:	_name(name)
{
	HumanB::_weapon = NULL;
}

void	HumanB::setWeapon(Weapon &type)
{
	_weapon = &type;
}

void	HumanB::attack()
{
	if (!HumanB::_weapon)
	{
		std::cout << "no weapons" << std::endl;
		return ;
	}
	std::cout << this->_name << " attacks with their " << (*_weapon).getType() << std::endl;
}
