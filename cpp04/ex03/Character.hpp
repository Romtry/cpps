/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:55:31 by rothiery          #+#    #+#             */
/*   Updated: 2025/07/02 13:34:10 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"
#include "stdint.h"

class Character: public ICharacter
{
	public:
							Character();
							Character(Character &original);
							Character(std::string Name);
							~Character();
		Character			&operator=(Character &original);

		//? ICharacter virtual
		const std::string	&getName() const;
		void				equip(AMateria *m);
		void				unequip(int idx);
		void 				use(int idx, ICharacter &target);

	protected:
		std::string	_name;
		AMateria	*_inventory[4];

	private:
		AMateria		*_floor[UINT16_MAX];
		unsigned short	_count;

};
