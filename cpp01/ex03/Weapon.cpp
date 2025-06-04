/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 08:59:00 by rothiery          #+#    #+#             */
/*   Updated: 2025/05/05 15:11:19 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string &type)
	:	_type(type)
{}

void	Weapon::setType(std::string newtype)
{
	this->_type = newtype;
}

const std::string	&Weapon::getType()
{
	return(this->_type);
}
