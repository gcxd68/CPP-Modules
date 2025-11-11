/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:53:39 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/11 17:15:50 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>

#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

int main()
{
	std::cout << MAGENTA << "=== BASIC TEST FROM SUBJECT ===" << RESET << std::endl;
	{
		IMateriaSource* src = new MateriaSource();
		
		// learnMateria clone l'objet, donc on doit delete après
		AMateria* ice = new Ice();
		AMateria* cure = new Cure();
		src->learnMateria(ice);
		src->learnMateria(cure);
		delete ice;   // Obligatoire car learnMateria a cloné
		delete cure;  // Obligatoire car learnMateria a cloné

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

	std::cout << std::endl << MAGENTA << "=== TEST INVENTORY FULL ===" << RESET << std::endl;
	{
		ICharacter* character = new Character("Hero");
		
		character->equip(new Ice());
		character->equip(new Cure());
		character->equip(new Ice());
		character->equip(new Cure());
		
		// Inventaire plein, doit gérer la mémoire
		AMateria* overflow = new Ice();
		character->equip(overflow);  // Échoue
		delete overflow;  // On doit delete car equip a échoué
		
		delete character;
	}

	std::cout << std::endl << MAGENTA << "=== TEST UNEQUIP (memory leak test) ===" << RESET << std::endl;
	{
		ICharacter* character = new Character("Hero");
		AMateria* floor[10];  // Floor pour stocker materias unequipped
		int floorCount = 0;
		
		character->equip(new Ice());
		character->equip(new Cure());
		AMateria* temp = new Ice();
		character->equip(temp);
		
		// Unequip ne delete pas, on doit sauver l'adresse
		floor[floorCount++] = temp;
		character->unequip(2);  // temp est maintenant sur le floor
		
		character->unequip(10);  // Slot invalide
		character->unequip(3);   // Slot vide
		
		delete character;
		
		// Nettoyer le floor
		for (int i = 0; i < floorCount; i++)
			delete floor[i];
	}

	std::cout << std::endl << MAGENTA << "=== TEST DEEP COPY CHARACTER ===" << RESET << std::endl;
	{
		Character* original = new Character("Original");
		original->equip(new Ice());
		original->equip(new Cure());

		Character* copy = new Character(*original);
		
		std::cout << CYAN << "Original uses slot 0 on copy:" << RESET << std::endl;
		original->use(0, *copy);
		
		std::cout << CYAN << "Copy uses slot 1 on original:" << RESET << std::endl;
		copy->use(1, *original);

		delete original;  // Original détruit
		std::cout << CYAN << "Copy still alive after original destroyed:" << RESET << std::endl;
		copy->use(0, *copy);  // Doit toujours fonctionner (deep copy)

		delete copy;
	}

	std::cout << std::endl << MAGENTA << "=== TEST MATERIA SOURCE ===" << RESET << std::endl;
	{
		MateriaSource* src = new MateriaSource();
		
		AMateria* ice = new Ice();
		AMateria* cure = new Cure();
		AMateria* ice2 = new Ice();
		AMateria* cure2 = new Cure();
		AMateria* ice3 = new Ice();
		
		src->learnMateria(ice);
		src->learnMateria(cure);
		src->learnMateria(ice2);
		src->learnMateria(cure2);
		src->learnMateria(ice3);  // Should fail - full
		
		delete ice;
		delete cure;
		delete ice2;
		delete cure2;
		delete ice3;
		
		AMateria* created_ice = src->createMateria("ice");
		AMateria* created_cure = src->createMateria("cure");
		AMateria* unknown = src->createMateria("fire");  // Should return NULL
		
		if (created_ice)
			delete created_ice;
		if (created_cure)
			delete created_cure;
		if (unknown)
			delete unknown;
		
		delete src;
	}

	std::cout << std::endl << MAGENTA << "=== TEST ASSIGNMENT OPERATOR ===" << RESET << std::endl;
	{
		Character hero("Hero");
		hero.equip(new Ice());
		hero.equip(new Cure());
		
		Character villain("Villain");
		villain.equip(new Ice());
		
		villain = hero;  // Assignment should delete villain's old materias
		
		std::cout << CYAN << "Villain (copy of Hero) uses materias:" << RESET << std::endl;
		villain.use(0, hero);
		villain.use(1, hero);
	}

	std::cout << std::endl << MAGENTA << "=== TEST MATERIA SOURCE DEEP COPY ===" << RESET << std::endl;
	{
		MateriaSource* src1 = new MateriaSource();
		AMateria* ice = new Ice();
		src1->learnMateria(ice);
		delete ice;
		
		MateriaSource* src2 = new MateriaSource(*src1);
		
		AMateria* m1 = src1->createMateria("ice");
		AMateria* m2 = src2->createMateria("ice");
		
		std::cout << CYAN << "Both sources can create ice independently" << RESET << std::endl;
		
		delete m1;
		delete m2;
		delete src1;
		
		std::cout << CYAN << "src2 still alive after src1 destroyed" << RESET << std::endl;
		AMateria* m3 = src2->createMateria("ice");
		delete m3;
		
		delete src2;
	}
}
