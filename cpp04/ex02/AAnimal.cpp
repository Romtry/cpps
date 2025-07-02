/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 09:43:23 by rothiery          #+#    #+#             */
/*   Updated: 2025/06/26 14:19:31 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

Animal::Animal()
{
	std::cout << this->type << " Animal constructed" << std::endl;
}

Animal::Animal(std::string type)
{
	std::cout << this->type << " Animal constructed" << std::endl;
	this->type = type;
}

Animal::Animal(Animal &original)
{
	this->type = original.type;
	std::cout << this->type << " Animal constructed" << std::endl;
}

Animal::~Animal()
{
	std::cout << this->type << " Animal destructed" << std::endl;
}

std::string	Animal::getType()
{
	return (this->type);
}

void	Animal::makeSound()
{
	std::cout << "Animal noise" << std::endl;
}

Animal	&Animal::operator=(Animal &original)
{
	this->type = original.type;
	std::cout << "Animal operator = used" << std::endl;
	return (*this);
}
