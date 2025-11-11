/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:50:03 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/11 11:49:22 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

#define MAGENTA	"\033[35m"
#define RESET	"\033[0m"

int main()
{
	std::cout << MAGENTA << "=== CORRECT POLYMORPHISM ===" << RESET << std::endl;
	std::cout << "[ Construction ]" << std::endl;
	const Animal* meta = new Animal();
	const Animal* i = new Cat();
	const Animal* j = new Dog();
	std::cout << std::endl << "[ Types ]" << std::endl;
	std::cout << "Animal:\t";
	std::cout << meta->getType() << std::endl;
	std::cout << "Cat:\t";
	std::cout << i->getType() << std::endl;
	std::cout << "Dog:\t";
	std::cout << j->getType() << std::endl;
	std::cout << std::endl << "[ Sounds ]" << std::endl;
	std::cout << "Animal:\t";
	meta->makeSound();
	std::cout << "Cat:\t";
	i->makeSound();
	std::cout << "Dog:\t";
	j->makeSound();
	std::cout << std::endl << "[ Destruction ]" << std::endl;
	delete meta;
	delete j;
	delete i;
	std::cout << std::endl << MAGENTA << "=== WRONG POLYMORPHISM ===" << RESET << std::endl;
	std::cout << "[ Construction ]" << std::endl;
	const WrongAnimal* wrong_meta = new WrongAnimal();
	const WrongAnimal* wrong_cat = new WrongCat();
	std::cout << std::endl << "[ Wrong sounds ]" << std::endl;
	std::cout << "WrongAnimal:\t";
	wrong_meta->makeSound();
	std::cout << "WrongCat:\t";
	wrong_cat->makeSound();
	std::cout << std::endl << "[ Destruction ]" << std::endl;
	delete wrong_meta;
	delete wrong_cat;
}
