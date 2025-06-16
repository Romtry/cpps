/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:06:04 by rothiery          #+#    #+#             */
/*   Updated: 2025/06/12 14:42:01 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap
{
	public:
				FragTrap();
				FragTrap(std::string Name);
				~FragTrap();
		void	highFivesGuys(void);
	private:
};
