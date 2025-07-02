/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 13:15:28 by rothiery          #+#    #+#             */
/*   Updated: 2025/06/26 11:39:40 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
	public:
				Dog();
				Dog(Dog &original);
				~Dog();
		Dog		operator=(Dog &original);
		void	makeSound();

	private:
		Brain	*_Brain;
};
