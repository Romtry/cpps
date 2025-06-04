/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 13:33:01 by rothiery          #+#    #+#             */
/*   Updated: 2025/06/02 10:23:32 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	wich_side(Point A, Point B, Point P)
{
	std::cout << P.gety() << std::endl;
	Point	vecab((B.getx() - A.getx()).toFloat(), (B.gety() - A.gety()).toFloat());
	Point	vecap((P.getx() - A.getx()).toFloat(), (P.gety() - A.gety()).toFloat());

	return ((vecab.getx() * vecap.gety() - vecab.gety() * vecap.getx()).toInt());
}

bool	same_side(int C, int P)
{
	if (P == 0)
		return (false);
	else if (C < 0)
	{
		if (P < 0)
			return (true);
		else
			return (false);
	}
	else
	{
		if (P > 0)
			return (true);
		else
			return (false);
	}
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	if(same_side(wich_side(a, b, c), wich_side(a, b, point)))
	{
		if (same_side(wich_side(a, c, b), wich_side(a, c, point)))
		{
			if (same_side(wich_side(c, b, a), wich_side(c, b, point)))
				return (true);
		}
	}
	return (false);
}
