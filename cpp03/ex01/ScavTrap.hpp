/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:56:42 by rothiery          #+#    #+#             */
/*   Updated: 2025/06/12 14:28:52 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap
{
	public:
				ScavTrap();
				ScavTrap(std::string Name);
				~ScavTrap();
		void	guardGate();
		void	attack(const std::string &target);

	private:

};
