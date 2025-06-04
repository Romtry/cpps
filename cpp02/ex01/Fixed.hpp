/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:26:44 by rothiery          #+#    #+#             */
/*   Updated: 2025/05/21 13:49:45 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const int i);
		Fixed(const float f);
		Fixed(const Fixed &f);
		~Fixed();
		Fixed 	&operator=(const Fixed &f);
		float	toFloat()	const;
		int		toInt()		const;

	private:
		int					i;
		const static int	virgule = 8;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed);
