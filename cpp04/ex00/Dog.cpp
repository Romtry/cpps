/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 09:36:29 by rothiery          #+#    #+#             */
/*   Updated: 2025/06/19 11:05:36 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
	:	Animal("Dog")
{
	std::cout << this->type << " Dog constructed" << std::endl;
}

Dog::Dog(Dog &original)
{
	this->type = original.type;
}

Dog::~Dog()
{
	std::cout << this->type << " Dog destructed" << std::endl;
}

void	Dog::makeSound()
{
	std::cout << "Wouf" << std::endl;
}

Dog	Dog::operator=(Dog &original)
{
	this->type = original.type;
	return (*this);
}
