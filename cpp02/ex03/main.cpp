/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:00:41 by rothiery          #+#    #+#             */
/*   Updated: 2025/06/02 10:37:25 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main(int argc, char **argv)
{
	if (argc != 9)
	{
		std::cout << "wrong args = [ax ay bx by cx cy px py]" << std::endl;
		return (0);
	}
	Point	a(std::atof(argv[1]), std::atof(argv[2]));
	Point	b(std::atof(argv[3]), std::atof(argv[4]));
	Point	c(std::atof(argv[5]), std::atof(argv[6]));
	Point	p(std::atof(argv[7]), std::atof(argv[8]));
	if (bsp(a, b, c, p) == true)
		std::cout << "Point p in triangle" << std::endl;
	else
		std::cout << "Point p out or in borders of triangle" << std::endl;
	return (0);
}
