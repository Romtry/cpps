/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rothiery <rothiery@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 10:26:42 by rothiery          #+#    #+#             */
/*   Updated: 2025/07/04 11:43:50 by rothiery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int	main()
{
	IMateriaSource* src = new MateriaSource();
	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");
	ICharacter* p1 = new Character();
	ICharacter* p2 = new Character();
	ICharacter* p3 = new Character();
	AMateria* tmp = NULL;

	tmp = src->createMateria("ice");
	tmp = src->createMateria("cure");
	tmp = src->createMateria("test");

	tmp = new Ice();
	src->learnMateria(tmp);
	delete tmp;
	tmp = new Cure();
	src->learnMateria(tmp);
	delete tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);

	tmp = src->createMateria("test");
	me->equip(tmp);

	tmp = src->createMateria("cure");
	me->equip(tmp);

	tmp = src->createMateria("cure");
	p1->equip(tmp);

	tmp = src->createMateria("cure");
	p2->equip(tmp);

	tmp = src->createMateria("cure");
	p3->equip(tmp);
	tmp = src->createMateria("cure");
	p3->equip(tmp);
	tmp = src->createMateria("cure");
	p3->equip(tmp);
	tmp = src->createMateria("cure");
	p3->equip(tmp);

	std::cout << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << std::endl;

	delete bob;
	delete me;
	delete src;
	delete p1;
	delete p2;
	delete p3;

	return (0);
}
