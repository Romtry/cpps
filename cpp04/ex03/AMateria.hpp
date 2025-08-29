/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 08:57:10 by rothiery          #+#    #+#             */
/*   Updated: 2025/08/06 14:35:30 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"
#include <iostream>

class ICharacter;

class AMateria
{
	public:
							AMateria();
							AMateria(AMateria &original);
							AMateria(const std::string &type);
		virtual				~AMateria();
		AMateria			&operator=(AMateria &original);
		const std::string 	&geType() const;
		virtual	AMateria	*clone() const = 0;
		virtual	void		use(ICharacter &target);
		bool				get_equiped();
		void				set_equiped();

	protected:
		std::string _type;

	private:
		bool		_equiped;
};
