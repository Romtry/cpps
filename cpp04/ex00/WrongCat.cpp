/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:45:47 by rothiery          #+#    #+#             */
/*   Updated: 2025/06/19 11:46:22 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WCat::WCat()
	:	WAnimal("WCat")
{
	std::cout << this->type << " WCat constructed" << std::endl;
}

WCat::WCat(WCat &original)
{
	this->type = original.type;
}

WCat::~WCat()
{
	std::cout << this->type << " WCat destructed" << std::endl;
}

void	WCat::makeSound()
{
	std::cout << "Miaou" << std::endl;
}

WCat	WCat::operator=(WCat &original)
{
	this->type = original.type;
	return (*this);
}
