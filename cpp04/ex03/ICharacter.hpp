/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 09:04:45 by rothiery          #+#    #+#             */
/*   Updated: 2025/06/30 10:59:33 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class ICharacter
{
	public:
		virtual 					~ICharacter() {}
		const virtual std::string	&getName() const = 0;
		virtual void 				equip(AMateria *m) = 0;
		virtual void 				unequip(int idx) = 0;
		virtual void 				use(int idx, ICharacter &target) = 0;

	protected:
		
	private:
		
};
