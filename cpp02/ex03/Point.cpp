/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:30:36 by rothiery          #+#    #+#             */
/*   Updated: 2025/06/02 10:15:31 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point()
	:	x(0), y(0)
{}

Point::Point(float x, float y)
	:	x(x), y(y)
{}

Point::Point(const Point &p)
	:	x(p.x), y(p.y)
{}

Point::~Point()
{}

Fixed	Point::getx()
{
	return (Point::x);
}

Fixed	Point::gety()
{
	return (Point::y);
}

Point	&Point::operator=(const Point &p)
{
	(Fixed)this->x = p.x;
	(Fixed)this->y = p.y;

	return (*this);
}
