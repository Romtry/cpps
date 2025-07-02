/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 13:44:44 by rothiery          #+#    #+#             */
/*   Updated: 2025/06/19 11:05:24 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
	:	Animal("Cat")
{
	std::cout << this->type << " Cat constructed" << std::endl;
}

Cat::Cat(Cat &original)
{
	this->type = original.type;
}

Cat::~Cat()
{
	std::cout << this->type << " Cat destructed" << std::endl;
}

void	Cat::makeSound()
{
	std::cout << "Miaou" << std::endl;
}

Cat	Cat::operator=(Cat &original)
{
	this->type = original.type;
	return (*this);
}
