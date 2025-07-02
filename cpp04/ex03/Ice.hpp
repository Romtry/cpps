/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:17:25 by rothiery          #+#    #+#             */
/*   Updated: 2025/06/30 12:40:30 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Ice: public AMateria
{
	public:
					Ice();
					Ice(Ice &original);
					~Ice();
		Ice			&operator=(Ice &original);
		AMateria	*clone() const;
		void		use(ICharacter &target);

	protected:
		
	private:
		
};
