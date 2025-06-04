/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:53:11 by rothiery          #+#    #+#             */
/*   Updated: 2025/05/14 11:31:27 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include "iostream"

class Zombie
{
	public:
		void			announce();
		Zombie(std::string name);
		~Zombie();

	private:
		std::string		name;
};

Zombie	*newZombie(std::string name);
void 	randomChump(std::string name);

#endif
