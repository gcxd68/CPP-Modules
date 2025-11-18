/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:53:39 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/18 11:37:53 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>

#define MAGENTA "\033[35m"
#define RESET "\033[0m"

int main()
{
	{
		std::cout << MAGENTA << "=== 42 TEST ===" << RESET << std::endl;
	
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}
	{
		std::cout << std::endl << MAGENTA << "=== TEST EQUIP / UNEQUIP ===" << RESET << std::endl;

		ICharacter* character = new Character("Hero");
		
		character->equip(new Ice());
		character->equip(new Cure());
		character->equip(new Ice());
		character->equip(new Cure());
		
		std::cout << "[ Trying to equip a 5th materia in full inventory ]" << std::endl;
		AMateria* overflow = new Ice();
		character->equip(overflow);

		std::cout << "[ Base unequip ] ";
		character->unequip(2);
		std::cout << "[ Invalid slot ] ";
		character->unequip(10);
		std::cout << "[ Empty slot ] ";
		character->unequip(2);
		
		delete character;
	}
	{
		std::cout << std::endl << MAGENTA << "=== TEST DEEP COPY CHARACTER ===" << RESET << std::endl;
		
		Character* original = new Character("Clone");
		original->equip(new Ice());
		original->equip(new Cure());

		Character* copy = new Character(*original);
		std::cout << "[ Original Clone was copied ; replica Clone owns its own cloned materias ]" << std::endl;

		std::cout << "[ Original Clone uses slot 0 on replica Clone ] ";
		original->use(0, *copy);
		std::cout << "[ Replica Clone uses slot 0 on original Clone ] ";
		copy->use(0, *original);

		delete original;
		std::cout << "[ Replica Clone still alive after original Clone destroyed ] ";
		copy->use(1, *copy);
		
		delete copy;
	}
	{
		std::cout << std::endl << MAGENTA << "=== TEST MATERIA SOURCE ===" << RESET << std::endl;

		MateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		std::cout << "[ Full MateriaSource tries to learn a 5th template ]" << std::endl;
		src->learnMateria(new Ice());

		std::cout << "[ MateriaSource creates ice & cure materias ]" << std::endl;
		AMateria* created_ice  = src->createMateria("ice");
		AMateria* created_cure = src->createMateria("cure");

		std::cout << "[ MateriaSource tries to create a materia of an unknown type ]" << std::endl;
		AMateria* unknown = src->createMateria("fire");
		if (!unknown)
			std::cout << "[ createMateria(\"fire\") returned NULL ]" << std::endl;
		else {
			std::cout << "[ createMateria(\"fire\") did not return NULL ]" << std::endl;
			delete unknown;
		}

		delete created_ice;
		delete created_cure;

		std::cout << "[ Creating a deep copy of MateriaSource ]" << std::endl;
		MateriaSource* src2 = new MateriaSource(*src);

		std::cout << "[ Original MateriaSource tries to create ice ] ";
		AMateria* m1 = src->createMateria("ice");
		std::cout << "[ Copy MateriaSource tries to create ice ] ";
		AMateria* m2 = src2->createMateria("ice");

		delete m1;
		delete m2;

		std::cout << "[ Destroying original MateriaSource ]" << std::endl;
		delete src;
		std::cout << "[ Copy still alive after src destroyed ] ";
		AMateria* m3 = src2->createMateria("ice");
		
		delete m3;
		delete src2;
	}
	{
		std::cout << std::endl << MAGENTA << "=== TEST ASSIGNMENT OPERATOR ===" << RESET << std::endl;
		std::cout << "[ Creating and equiping Hero ]" << std::endl;
		Character hero("Hero");
		hero.equip(new Ice());
		hero.equip(new Cure());

		std::cout << "[ Creating and equiping Villain ]" << std::endl;
		Character villain("Villain");
		villain.equip(new Cure());

		std::cout << "[ Assignment operator deletes Villain's old materias and deep copies Hero's ]" << std::endl;
		villain = hero;

		std::cout << "[ Villain (copy of Hero) uses slot 0 ] ";
		villain.use(0, hero);
		std::cout << "[ Villain (copy of Hero) uses slot 1 ] ";
		villain.use(1, hero);
	}
}
