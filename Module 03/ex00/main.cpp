/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:13:03 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/07 14:07:22 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

#define MAGENTA "\033[35m"
#define RESET	"\033[0m"

int main()
{
	std::cout << MAGENTA << "=== TEST 1: CONSTRUCTION ===" << RESET << std::endl;
	ClapTrap clap1("Bob");
	std::cout << std::endl;

	std::cout << MAGENTA << "=== TEST 2: BASIC ATTACKS ===" << RESET << std::endl;
	for (int i = 0; i < 3; i++)
		clap1.attack("the enemy");
	std::cout << std::endl;

	std::cout << MAGENTA << "=== TEST 3: TAKING DAMAGE ===" << RESET << std::endl;
	clap1.takeDamage(2);
	clap1.takeDamage(3);
	std::cout << std::endl;

	std::cout << MAGENTA << "=== TEST 4: REPAIRING ===" << RESET << std::endl;
	clap1.beRepaired(4);
	clap1.beRepaired(1);
	std::cout << std::endl;

	std::cout << MAGENTA << "=== TEST 5: EXHAUSTING ENERGY ===" << RESET << std::endl;
	// Bob has used 5 energy points (3 attacks + 2 repairs)
	// He has 5 energy points left, let's use them all
	for (int i = 0; i < 5; i++)
		clap1.attack("an enemy");
	std::cout << "[ Trying to attack with no energy left ] " << RESET;
	clap1.attack("should_fail");
	std::cout << "[ Trying to repair with no energy left ] " << RESET;
	clap1.beRepaired(1);
	std::cout << std::endl;

	std::cout << MAGENTA << "=== TEST 6: DEATH SCENARIO ===" << RESET << std::endl;
	ClapTrap clap2("Alice");
	clap2.takeDamage(5);   // Alice has 5 HP left
	clap2.takeDamage(10);  // Alice takes more damage than remaining HP (dies)
	std::cout << "[ Trying to attack while dead ] " << RESET;
	clap2.attack("should_fail");
	std::cout << "[ Trying to repair while dead ] " << RESET;
	clap2.beRepaired(5);
	std::cout << "[ Taking damage while already dead ] " << RESET;
	clap2.takeDamage(5);
	std::cout << std::endl;

	std::cout << MAGENTA << "=== TEST 7: COPY CONSTRUCTOR ===" << RESET << std::endl;
	ClapTrap clap3("Charlie");
	clap3.attack("an enemy");
	std::cout << "[ Calling copy constructor ] " << RESET;
	ClapTrap clap4(clap3);
	clap4.attack("an enemy");
	std::cout << std::endl;

	std::cout << MAGENTA << "=== TEST 8: ASSIGNMENT OPERATOR ===" << RESET << std::endl;
	ClapTrap clap5("David");
	ClapTrap clap6("Eve");
	clap6 = clap5;  // Assignment operator
	clap6.attack("an enemy");
	std::cout << std::endl;

	std::cout << MAGENTA << "=== TEST 9: DEFAULT CONSTRUCTOR ===" << RESET << std::endl;
	ClapTrap clap7;
	clap7.attack("an enemy");
	std::cout << std::endl;

	std::cout << MAGENTA << "=== DESTRUCTORS WILL BE CALLED NOW ===" << RESET << std::endl;
}
