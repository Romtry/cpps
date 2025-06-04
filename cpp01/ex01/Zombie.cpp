/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:01:17 by rothiery          #+#    #+#             */
/*   Updated: 2025/04/30 13:11:19 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce()
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie *ret = new Zombie[N];
	for (int i = 0; i < N; i++)
		ret[i].setname(name);
	return (ret);
}

void	Zombie::setname(std::string name)
{
	Zombie::name = name;
}

Zombie	*newZombie(std::string name)
{
	Zombie	*ret;

	ret = new(Zombie);
	ret->setname(name);
	return (ret);
}

void	randomChump(std::string name)
{
	Zombie	temp;

	temp.setname(name);
	temp.announce();
}

Zombie::~Zombie()
{
	std::cout << this->name << " delete" << std::endl;
}
