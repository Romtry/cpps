/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:32:20 by rothiery          #+#    #+#             */
/*   Updated: 2025/05/14 17:00:39 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	std::string str, name;

	str = "crude spiked club";
	name = "Bob";
	{
		Weapon club = Weapon(str);
		HumanA bob(name, club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	str = "crude spiked club";
	name = "Jim";
	{
		Weapon club2 = Weapon(str);
		HumanB jim(name);
		jim.attack();
		jim.setWeapon(club2);
		jim.attack();
		club2.setType("some other type of club");
		jim.attack();
	}
	return 0;
}
