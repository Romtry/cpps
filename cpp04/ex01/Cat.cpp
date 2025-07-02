/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:44:44 by rothiery          #+#    #+#             */
/*   Updated: 2025/06/24 11:50:52 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
	:	Animal("Cat")
{
	this->_Brain = new Brain();
	std::cout << this->type << " Cat constructed" << std::endl;
}

Cat::Cat(Cat &original)
{
	std::cout << this->type << " Cat copy constructed" << std::endl;
	this->_Brain = new Brain(*original._Brain);
	this->type = original.type;
}

Cat::~Cat()
{
	delete this->_Brain;
	std::cout << this->type << " Cat destructed" << std::endl;
}

void	Cat::makeSound()
{
	std::cout << "Miaou" << std::endl;
}

Cat	Cat::operator=(Cat &original)
{
	delete this->_Brain;
	this->_Brain = new Brain(*original._Brain);
	this->type = original.type;
	std::cout << "Cat operator = used" << std::endl;
	return (*this);
}
