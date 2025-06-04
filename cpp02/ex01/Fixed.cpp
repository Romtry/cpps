/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:50:17 by rothiery          #+#    #+#             */
/*   Updated: 2025/05/21 13:51:38 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// constructors
Fixed::Fixed()
	:	i(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &f)
	:	i(f.i)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int i)
	:	i(i << this->virgule)
{
	std::cout << "int constructor called" << std::endl;
}

Fixed::Fixed(const float f)
	:	i(roundf(f * (1 << this->virgule)))
{
	std::cout << "float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

// methods
Fixed	&Fixed::operator=(const Fixed &f)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->i = f.i;
	return (*this);
}

float	Fixed::toFloat() const
{
	return ((float)this->i / (1 << this->virgule));
}

int	Fixed::toInt() const
{
	return (this->i >> this->virgule);
}

// functions
std::ostream	&operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
