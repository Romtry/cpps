/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 11:45:11 by rothiery          #+#    #+#             */
/*   Updated: 2025/06/19 11:45:30 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include "WrongAnimal.hpp"

class WCat : public WAnimal
{
	public:
				WCat();
				WCat(WCat &original);
				~WCat();
		WCat		operator=(WCat &original);
		void	makeSound();
};
