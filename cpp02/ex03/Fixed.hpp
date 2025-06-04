/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:26:44 by rothiery          #+#    #+#             */
/*   Updated: 2025/06/02 10:12:16 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>
#include <cstdlib>

class Fixed
{
	public:
		Fixed();
		Fixed(const int i);
		Fixed(const float f);
		Fixed(const Fixed &f);
		~Fixed();
		Fixed 			&operator=(const Fixed &f);
		bool			operator>(const Fixed &f) const;
		bool			operator<(const Fixed &f) const;
		bool			operator>=(const Fixed &f) const;
		bool			operator<=(const Fixed &f) const;
		bool			operator==(const Fixed &f) const;
		bool			operator!=(const Fixed &f) const;
		Fixed			operator+(const Fixed &f) const;
		Fixed			operator-(const Fixed &f) const;
		Fixed			operator*(const Fixed &f) const;
		Fixed			operator/(const Fixed &f) const;
		Fixed			operator++();
		Fixed			operator++(int);
		Fixed			operator--();
		Fixed			operator--(int);

		static Fixed	min(Fixed &a, Fixed &b);
		static Fixed	min(const Fixed &a, const Fixed &b);
		static Fixed	max(Fixed &a, Fixed &b);
		static Fixed	max(const Fixed &a, const Fixed &b);
		float			toFloat()	const;
		int				toInt()		const;

	private:
		int					i;
		const static int	virgule = 8;
};

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed);
