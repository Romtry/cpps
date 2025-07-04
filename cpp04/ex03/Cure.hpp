/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:25:32 by rothiery          #+#    #+#             */
/*   Updated: 2025/07/02 14:26:28 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Cure: public AMateria
{
	public:
					Cure();
					Cure(Cure &original);
					~Cure();
		Cure		&operator=(Cure &original);
		AMateria	*clone() const;
		void		use(ICharacter &target);

	protected:
		
	private:
		
};
