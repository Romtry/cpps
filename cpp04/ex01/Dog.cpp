/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 09:36:29 by rothiery          #+#    #+#             */
/*   Updated: 2025/06/24 11:50:16 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
	:	Animal("Dog")
{
	this->_Brain = new Brain();
	std::cout << this->type << " Dog constructed" << std::endl;
}

Dog::Dog(Dog &original)
{
	std::cout << this->type << " Dog copy constructed" << std::endl;
	this->_Brain = new Brain(*original._Brain);
	this->type = original.type;
}

Dog::~Dog()
{
	delete this->_Brain;
	std::cout << this->type << " Dog destructed" << std::endl;
}

void	Dog::makeSound()
{
	std::cout << "Wouf" << std::endl;
}

Dog	Dog::operator=(Dog &original)
{
	delete this->_Brain;
	this->_Brain = new Brain(*original._Brain);
	this->type = original.type;
	std::cout << "Dog operator = used" << std::endl;
	return (*this);
}
