/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:25:35 by rothiery          #+#    #+#             */
/*   Updated: 2025/06/04 12:54:54 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// int	main()
// {
// 	ClapTrap	one("ct 1");
// 	ClapTrap	two("ct 2");
// 	ClapTrap	tree("ct 3");
// 	ClapTrap	four("ct 4");

// 	two.takeDamage(5);
// 	one.takeDamage(10);
// 	tree.takeDamage(15);
// 	one.takeDamage(5);
// 	one.attack("ct 2");
// 	four.attack("ct 1");
// 	four.beRepaired(1);
// 	four.attack("ct 1");
// 	four.beRepaired(1);
// 	four.attack("ct 1");
// 	four.beRepaired(1);
// 	four.attack("ct 1");
// 	four.beRepaired(1);
// 	four.attack("ct 1");
// 	four.beRepaired(1);
// 	four.attack("ct 1");
// 	four.beRepaired(1);
// 	four.takeDamage(0);
// }

int	main()
{
	ScavTrap	one("st 1");

	one.attack("test");
	one.beRepaired(1);
	one.takeDamage(1);
	one.guardGate();
}
