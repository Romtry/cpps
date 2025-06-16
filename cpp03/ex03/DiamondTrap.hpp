/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 09:09:40 by rothiery          #+#    #+#             */
/*   Updated: 2025/06/12 14:42:29 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap
{
	public:
				DiamondTrap();
				DiamondTrap(std::string name);
				~DiamondTrap();
		void	whoami();
		void	attack(const std::string &target);

	private:
		std::string	_name;
};
