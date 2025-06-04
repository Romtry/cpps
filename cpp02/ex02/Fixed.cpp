/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:50:17 by rothiery          #+#    #+#             */
/*   Updated: 2025/05/27 13:30:34 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// constructors
Fixed::Fixed()
	:	i(0)
{}

Fixed::Fixed(const Fixed &f)
	:	i(f.i)
{}

Fixed::Fixed(const int i)
	:	i(i << this->virgule)
{}

Fixed::Fixed(const float f)
	:	i(roundf(f * (1 << this->virgule)))
{}

Fixed::~Fixed()
{}

// methods
Fixed	&Fixed::operator=(const Fixed &f)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->i = f.i;
	return (*this);
}

bool	Fixed::operator>(const Fixed &f) const
{
	if (this->i > f.i)
		return (true);
	return (false);
}

bool	Fixed::operator<(const Fixed &f) const
{
	if (this->i < f.i)
		return (true);
	return (false);
}

bool	Fixed::operator>=(const Fixed &f) const
{
	if (this->i >= f.i)
		return (true);
	return (false);
}

bool	Fixed::operator<=(const Fixed &f) const
{
	if (this->i <= f.i)
		return (true);
	return (false);
}

bool	Fixed::operator==(const Fixed &f) const
{
	if (this->i == f.i)
		return (true);
	return (false);
}

bool	Fixed::operator!=(const Fixed &f) const
{
	if (this->i != f.i)
		return (true);
	return (false);
}

Fixed	Fixed::operator+(const Fixed &f) const
{
	Fixed	a;

	a = (this->toFloat() + f.toFloat());
	return (a);
}

Fixed	Fixed::operator-(const Fixed &f) const
{
	Fixed	a;

	a = (this->toFloat() - f.toFloat());
	return (a);
}

Fixed	Fixed::operator*(const Fixed &f) const
{
	Fixed	a;
 
	a = (this->toFloat() * f.toFloat());
	return (a);
}

Fixed	Fixed::operator/(const Fixed &f) const
{
	Fixed	a;
 
	a = (this->toFloat() / f.toFloat());
	return (a);
}

Fixed	Fixed::operator++()
{
	this->i += 1;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp;

	temp = *this;
	this->i += 1;
	return (temp);
}

Fixed	Fixed::operator--()
{
	this->i -= 1;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp;

	temp = *this;
	this->i -= 1;
	return (temp);
}

Fixed	Fixed::min(Fixed &a, Fixed &b) 
{
	if (a < b)
		return (a);
	return (b);
}

Fixed	Fixed::min(const Fixed &a, const Fixed &b) 
{
	if (a < b)
		return (a);
	return (b);
}

Fixed	Fixed::max(Fixed &a, Fixed &b) 
{
	if (a > b)
		return (a);
	return (b);
}

Fixed	Fixed::max(const Fixed &a, const Fixed &b) 
{
	if (a > b)
		return (a);
	return (b);
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
