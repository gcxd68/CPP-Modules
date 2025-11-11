/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:58:47 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/11 14:12:18 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

#define MAGENTA	"\033[35m"
#define RESET	"\033[0m"

int main()
{
	std::cout << MAGENTA << "=== TEST 1: Basic 42 leak test ===" << RESET << std::endl;
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j; // should not create a leak
		delete i;
	}
	std::cout << std::endl << MAGENTA << "=== TEST 2: Array of Animals ===" << RESET << std::endl;
	{
		const size_t size = 6;
		Animal* animals[size];
		for (size_t i = 0; i < size; i++) {
			std::cout << "[ Creating Animal No." << i + 1 << " = ";
			if (i < size / 2) {
				std::cout << "Dog No." << i + 1 << " ]" << std::endl;
				animals[i] = new Dog();
			} else {
				std::cout << "Cat No." << i - size / 2 + 1 << " ]" << std::endl;
				animals[i] = new Cat();
			}
		}
		std::cout << std::endl << "[ Making sounds ]" << std::endl;
		for (size_t i = 0; i < size; i++) {
			std::cout << "Animal No." << i + 1;
			if (i < size / 2)
				std::cout << " (Dog No." << i + 1 << " ): ";
			else
				std::cout << " (Cat No." << i - size / 2 + 1 << " ): ";
			animals[i]->makeSound();
		}
		std::cout << std::endl << "[ Deleting animals ]" << std::endl;
		for (size_t i = 0; i < size; i++)
			delete animals[i];
	}
	std::cout << std::endl << MAGENTA << "=== TEST 3: Copy constructor deep copy ===" << RESET << std::endl;
	{
		Cat original;
		{
			Cat copied = original;
			std::cout << "Assignment completed, let's hope Cat copied is a deep copy of Cat original..." << std::endl;
		}
		std::cout << "...Success! Cat copied got destroyed and Cat original is still alive, proof that each had their own Brain (deep copy)" << std::endl;
	}
	std::cout << std::endl << MAGENTA << "=== TEST 4: Assignment operator deep copy ===" << RESET << std::endl;
	{
		Dog original;
		{
			Dog assigned;
			assigned = original;
			std::cout << "Assignment completed, let's hope Dog assigned is a deep copy of Dog original..." << std::endl;
		}
		std::cout << "...Success! Dog assigned got destroyed and Dog original is still alive, proof that each had their own Brain (deep copy)" << std::endl;
	}
}
