/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 14:15:25 by rothiery          #+#    #+#             */
/*   Updated: 2025/05/05 15:01:10 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string &name, Weapon &type)
	: _weapon(type), _name(name)
{}

void	HumanA::attack()
{
	std::cout << this->_name << " attacks with their " << _weapon.getType() << std::endl;
}
