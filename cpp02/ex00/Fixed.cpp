/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:50:17 by rothiery          #+#    #+#             */
/*   Updated: 2025/05/21 13:26:15 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->i = 0;
}

Fixed::Fixed(Fixed &f)
{
	std::cout << "Copy constructor called" << std::endl;
	std::cout << "Copy assignment operator called" << std::endl;
	this->setRawBits(f.getRawBits());
}

Fixed	&Fixed::operator=(const Fixed &f)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->i = f.i;
	return (*this);
}

int		Fixed::getRawBits() const
{
	std::cout << "GetRawBits member function called" << std::endl;
	return(this->i);
}

void	Fixed::setRawBits(int const raw)
{
	this->i = raw;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
