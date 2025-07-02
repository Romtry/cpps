/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 10:26:42 by rothiery          #+#    #+#             */
/*   Updated: 2025/06/30 08:53:18 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

#define NUMBER 10

int	main()
{
	Animal* (j[NUMBER]);

	for (int i = 0; i < NUMBER / 2; i++)
		j[i] = new Cat();

	for (size_t i = NUMBER / 2; i < NUMBER; i++)
		j[i] = new Dog();

	for (size_t i = 0; i < NUMBER; i++)
		delete j[i];

	Dog* z = new Dog();
	Dog* y = new Dog(*z);
	delete z;
	delete y;
	Cat* a = new Cat();
	Cat* b = new Cat(*a);
	delete a;
	delete b;

	return (0);
}
