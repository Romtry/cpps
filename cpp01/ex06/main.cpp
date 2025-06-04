/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:48:16 by rothiery          #+#    #+#             */
/*   Updated: 2025/05/14 10:16:25 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	std::string	arg;
	Harl		harl;

	if (argc != 2)
	{
		std::cout << "need 1 arg : ./harlFilter [level]" << std::endl;
		return (0);
	}
	arg = argv[1];
	harl.complain(arg);
	return (0);
}
