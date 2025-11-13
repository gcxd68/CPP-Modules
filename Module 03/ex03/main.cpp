/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:13:03 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/13 11:05:54 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

#define MAGENTA	"\033[35m"
#define RESET	"\033[0m"

int main()
{
	std::cout << MAGENTA << "=== TEST 1: CONSTRUCTION CHAIN ===" << RESET << std::endl;
	DiamondTrap diamond1("Gemma");
	std::cout << std::endl;

	std::cout << MAGENTA << "=== TEST 2: WHO AM I ===" << RESET << std::endl;
	diamond1.whoAmI();
	std::cout << std::endl;

	std::cout << MAGENTA << "=== TEST 3: DIAMONDTRAP ATTACKS ===" << RESET << std::endl;
	for (int i = 0; i < 3; i++)
		diamond1.attack("an enemy");
	std::cout << std::endl;

	std::cout << MAGENTA << "=== TEST 4: TAKING DAMAGE ===" << RESET << std::endl;
	diamond1.takeDamage(30);
	diamond1.takeDamage(40);
	std::cout << std::endl;

	std::cout << MAGENTA << "=== TEST 5: REPAIRING ===" << RESET << std::endl;
	diamond1.beRepaired(20);
	diamond1.beRepaired(15);
	std::cout << std::endl;

	std::cout << MAGENTA << "=== TEST 6: SPECIAL ABILITIES ===" << RESET << std::endl;
	diamond1.guardGate();
	diamond1.highFivesGuys();
	std::cout << std::endl;

	std::cout << MAGENTA << "=== TEST 7: EXHAUSTING ENERGY ===" << RESET << std::endl;
	for (int i = 0; i < 45; i++)
		diamond1.attack("an enemy");
	std::cout << "[ Trying to attack with no energy left ] ";
	diamond1.attack("should_fail");
	std::cout << "[ Trying to repair with no energy left ] ";
	diamond1.beRepaired(1);
	std::cout << std::endl;

	std::cout << MAGENTA << "=== TEST 8: DEATH SCENARIO ===" << RESET << std::endl;
	DiamondTrap diamond2("Doomed");
	diamond2.takeDamage(50);
	diamond2.takeDamage(60);
	std::cout << "[ Trying to attack while dead ] ";
	diamond2.attack("should_fail");
	std::cout << "[ Trying to repair while dead ] ";
	diamond2.beRepaired(20);
	std::cout << "[ Taking damage while already dead ] ";
	diamond2.takeDamage(50);
	std::cout << std::endl;

	std::cout << MAGENTA << "=== TEST 9: COPY CONSTRUCTOR ===" << RESET << std::endl;
	DiamondTrap diamond3("ToBeCopied");
	diamond3.attack("an enemy");
	std::cout << "[ Calling copy constructor ] ";	
	DiamondTrap diamond4(diamond3);
	diamond4.whoAmI();
	diamond4.attack("an enemy");
	std::cout << std::endl;

	std::cout << MAGENTA << "=== TEST 10: COPY ASSIGNMENT OPERATOR ===" << RESET << std::endl;
	DiamondTrap diamond5("Original");
	DiamondTrap diamond6("Assigned Copy");
	diamond5.takeDamage(40);
	diamond6 = diamond5;
	diamond6.attack("an enemy");
	std::cout << std::endl;

	std::cout << MAGENTA << "=== DESTRUCTION CHAIN (reverse order) ===" << RESET << std::endl;
}
