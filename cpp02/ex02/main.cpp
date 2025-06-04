/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:00:41 by rothiery          #+#    #+#             */
/*   Updated: 2025/05/27 13:25:26 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// int	main()
// {
// 	Fixed 		a;
// 	const Fixed	b(Fixed(5.05f) * Fixed(2));

// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;

// 	std::cout << b << std::endl;

// 	std::cout << Fixed::max( a, b ) << std::endl;
// 	return (0);
// }

void	compar_test(Fixed a, Fixed b, Fixed c)
{
	if (a > b)
		std::cout << "NOPE" << std::endl;
	else
		std::cout << "YES" << std::endl;
	if (b > a)
		std::cout << "YES" << std::endl;
	else
		std::cout << "NOPE" << std::endl;
	if (b < a)
		std::cout << "NOPE" << std::endl;
	else
		std::cout << "YES" << std::endl;
	if (a < b)
		std::cout << "YES" << std::endl;
	else
		std::cout << "NOPE" << std::endl;
	if (a >= b)
		std::cout << "NOPE" << std::endl;
	else
		std::cout << "YES" << std::endl;
	if (b >= a && a >= c)
		std::cout << "YES" << std::endl;
	else
		std::cout << "NOPE" << std::endl;
	if (b <= a)
		std::cout << "NOPE" << std::endl;
	else
		std::cout << "YES" << std::endl;
	if (a <= b && a <= c)
		std::cout << "YES" << std::endl;
	else
		std::cout << "NOPE" << std::endl;
	if (a == b)
		std::cout << "NOPE" << std::endl;
	else
		std::cout << "YES" << std::endl;
	if (a == c)
		std::cout << "YES" << std::endl;
	else
		std::cout << "NOPE" << std::endl;
	if (a != c)
		std::cout << "NOPE" << std::endl;
	else
		std::cout << "YES" << std::endl;
	if (a != b)
		std::cout << "YES" << std::endl;
	else
		std::cout << "NOPE" << std::endl;
}

void	operator_test(Fixed a, Fixed b)
{
	std::cout << a << " + " << b << " = " << a + b << std::endl;
	std::cout << a << " - " << b << " = " << a - b << std::endl;
	std::cout << a << " * " << b << " = " << a * b << std::endl;
	std::cout << a << " / " << b << " = " << a / b << std::endl;
}

void	incerment_test(Fixed a)
{
	std::cout << "a = " << a << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << "a++ = " << a++ << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "--a = " << --a << std::endl;
	std::cout << "a-- = " << a-- << std::endl;
	std::cout << "a = " << a << std::endl;
}

void	minmaxtest(Fixed a, Fixed b)
{
	const Fixed	a2(1);
	const Fixed	a3(1.5f);

	std::cout << "min(" << a << ", " << b << ") = " << a.min(a, b) << std::endl;
	std::cout << "min(" << a2 << "const, " << a3 << "const) = " << a.min(a2, a3) << std::endl;
	std::cout << "max(" << a << ", " << b << ") = " << a.max(a, b) << std::endl;
	std::cout << "max(" << a2 << "const, " << a3 << "const) = " << a.max(a2, a3) << std::endl;
}

int	main()
{
	Fixed	a(1);
	Fixed	b(1.5f);
	Fixed	c(1);

	std::cout << "a = " << a << "\nb = " << b << "\nc = " << c << std::endl;
	compar_test(a, b, c);
	operator_test(a, b);
	incerment_test(a);
	minmaxtest(a, b);
}
