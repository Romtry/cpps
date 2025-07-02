/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:25:32 by rothiery          #+#    #+#             */
/*   Updated: 2025/06/30 11:10:11 by rothiery         ###   ########.fr       */
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

	protected:
		
	private:
		
};
