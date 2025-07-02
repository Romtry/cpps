/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:55:31 by rothiery          #+#    #+#             */
/*   Updated: 2025/07/02 09:24:22 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character: public AMateria, public ICharacter
{
	public:
							Character();
							Character(Character &original);
							~Character();
		const std::string	&getName();
		void				equip(AMateria *m);
		void				unequip(int idx);
		void 				use(int idx, ICharacter &target);
		Character			&operator=(Character &original);

	protected:
		std::string	name;
		AMateria	*inventory[4];

	private:
		AMateria	*floor[UINT16_MAX];
		u_int16_t	count;

};
