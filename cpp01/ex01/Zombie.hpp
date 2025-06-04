/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:53:11 by rothiery          #+#    #+#             */
/*   Updated: 2025/04/30 12:54:09 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include "iostream"

class Zombie
{
	public:
	void	announce();
	void	setname(std::string name);
	~Zombie();

	private:
	std::string		name;
};

Zombie	*newZombie(std::string name);
Zombie	*zombieHorde(int N,std::string name);
void 	randomChump(std::string name);

#endif
