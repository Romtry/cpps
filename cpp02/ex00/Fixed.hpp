/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:26:44 by rothiery          #+#    #+#             */
/*   Updated: 2025/05/21 13:26:05 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed
{
	public:
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		Fixed 	&operator=(const Fixed &f);
		Fixed();
		Fixed(Fixed &);
		~Fixed();

	private:
		int					i;
		const int static	i2 = 8;
};
