/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:13:03 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/13 11:04:36 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

#define MAGENTA	"\033[35m"
#define RESET	"\033[0m"

int main()
{
	std::cout << MAGENTA << "=== TEST 1: CONSTRUCTION CHAIN ===" << RESET << std::endl;
	ScavTrap scav1("Jack");
	std::cout << std::endl;

	std::cout << MAGENTA << "=== TEST 2: SCAVTRAP ATTACKS ===" << RESET << std::endl;
	for (int i = 0; i < 3; i++)
		scav1.attack("an enemy");
	std::cout << std::endl;

	std::cout << MAGENTA << "=== TEST 3: TAKING DAMAGE ===" << RESET << std::endl;
	scav1.takeDamage(30);
	scav1.takeDamage(40);
	std::cout << std::endl;

	std::cout << MAGENTA << "=== TEST 4: REPAIRING ===" << RESET << std::endl;
	scav1.beRepaired(20);
	scav1.beRepaired(15);
	std::cout << std::endl;

	std::cout << MAGENTA << "=== TEST 5: GUARD GATE ===" << RESET << std::endl;
	scav1.guardGate();
	std::cout << std::endl;

	std::cout << MAGENTA << "=== TEST 6: EXHAUSTING ENERGY ===" << RESET << std::endl;
	for (int i = 0; i < 45; i++)
		scav1.attack("an enemy");
	std::cout << "[ Trying to attack with no energy left ] ";
	scav1.attack("should_fail");
	std::cout << "[ Trying to repair with no energy left ] ";
	scav1.beRepaired(1);
	std::cout << std::endl;

	std::cout << MAGENTA << "=== TEST 7: DEATH SCENARIO ===" << RESET << std::endl;
	ScavTrap scav2("Doomed");
	scav2.takeDamage(50);
	scav2.takeDamage(60);
	std::cout << "[ Trying to attack while dead ] ";
	scav2.attack("should_fail");
	std::cout << "[ Trying to repair while dead ] ";
	scav2.beRepaired(5);
	std::cout << "[ Taking damage while already dead ] ";
	scav2.takeDamage(5);
	std::cout << std::endl;

	std::cout << MAGENTA << "=== TEST 8: COPY CONSTRUCTOR ===" << RESET << std::endl;
	ScavTrap scav3("ToBeCopied");
	scav3.attack("an enemy");
	std::cout << "[ Calling copy constructor ] ";	
	ScavTrap scav4(scav3);
	scav4.attack("an enemy");
	std::cout << std::endl;

	std::cout << MAGENTA << "=== TEST 9: ASSIGNMENT OPERATOR ===" << RESET << std::endl;
	ScavTrap scav5("Original");
	ScavTrap scav6("Assigned Copy");
	scav5.takeDamage(30);
	scav6 = scav5;
	scav6.attack("an enemy");
	std::cout << std::endl;

	std::cout << MAGENTA << "=== TEST 10: DEFAULT CONSTRUCTOR ===" << RESET << std::endl;
	ScavTrap scav7;
	scav7.attack("an enemy");
	std::cout << std::endl;

	std::cout << MAGENTA << "=== DESTRUCTION CHAIN (reverse order) ===" << RESET << std::endl;
}
