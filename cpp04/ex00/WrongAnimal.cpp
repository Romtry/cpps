/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:07:43 by rothiery          #+#    #+#             */
/*   Updated: 2025/06/19 11:43:53 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WAnimal::WAnimal()
{
	std::cout << this->type << " WAnimal constructed" << std::endl;
}

WAnimal::WAnimal(std::string type)
{
	std::cout << this->type << " WAnimal constructed" << std::endl;
	this->type = type;
}

WAnimal::WAnimal(WAnimal &original)
{
	this->type = original.type;
	std::cout << this->type << " WAnimal constructed" << std::endl;
}

WAnimal::~WAnimal()
{
	std::cout << this->type << " WAnimal destructed" << std::endl;
}

std::string	WAnimal::getType()
{
	return (this->type);
}

void	WAnimal::makeSound()
{
	std::cout << "WAnimal noise" << std::endl;
}

WAnimal	WAnimal::operator=(WAnimal &original)
{
	this->type = original.type;
	return (*this);
}
