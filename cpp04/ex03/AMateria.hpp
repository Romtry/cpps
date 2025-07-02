/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 08:57:10 by rothiery          #+#    #+#             */
/*   Updated: 2025/06/30 10:58:46 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"
#include <iostream>

class AMateria
{
	public:
							AMateria();
							AMateria(AMateria &original);
							AMateria(const std::string &type);
							~AMateria();
		AMateria			&operator=(AMateria &original);
		const std::string 	&geType() const;
		virtual	AMateria	*clone() const = 0;
		virtual	void		use(ICharacter &target);

	protected:
		std::string type;

	private:
		
};
