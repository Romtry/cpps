/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:10:36 by rothiery          #+#    #+#             */
/*   Updated: 2025/06/02 10:11:17 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(float x, float y);
		~Point();
		Point(const Point&p);
		Fixed	getx();
		Fixed	gety();
		Point &operator=(const Point&p);

	private:
		const Fixed x;
		const Fixed y;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);
