/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:13:03 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/13 11:05:48 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

#define MAGENTA	"\033[35m"
#define RESET	"\033[0m"

int main()
{
	std::cout << MAGENTA << "=== TEST 1: CONSTRUCTION CHAIN ===" << RESET << std::endl;
	FragTrap frag1("Bill");
	std::cout << std::endl;

	std::cout << MAGENTA << "=== TEST 2: FRAGTRAP ATTACKS ===" << RESET << std::endl;
	for (int i = 0; i < 3; i++)
		frag1.attack("an enemy");
	std::cout << std::endl;

	std::cout << MAGENTA << "=== TEST 3: TAKING DAMAGE ===" << RESET << std::endl;
	frag1.takeDamage(30);
	frag1.takeDamage(40);
	std::cout << std::endl;

	std::cout << MAGENTA << "=== TEST 4: REPAIRING ===" << RESET << std::endl;
	frag1.beRepaired(20);
	frag1.beRepaired(15);
	std::cout << std::endl;

	std::cout << MAGENTA << "=== TEST 5: HIGH-FIVES ===" << RESET << std::endl;
	frag1.highFivesGuys();
	std::cout << std::endl;

	std::cout << MAGENTA << "=== TEST 6: EXHAUSTING ENERGY ===" << RESET << std::endl;
	for (int i = 0; i < 95; i++)
		frag1.attack("an enemy");
	std::cout << "[ Trying to attack with no energy left ] ";
	frag1.attack("should_fail");
	std::cout << "[ Trying to repair with no energy left ] ";
	frag1.beRepaired(1);
	std::cout << std::endl;

	std::cout << MAGENTA << "=== TEST 7: DEATH SCENARIO ===" << RESET << std::endl;
	FragTrap frag2("Doomed");
	frag2.takeDamage(50);
	frag2.takeDamage(60);
	std::cout << "[ Trying to attack while dead ] ";
	frag2.attack("should_fail");
	std::cout << "[ Trying to repair while dead ] ";
	frag2.beRepaired(5);
	std::cout << "[ Taking damage while already dead ] ";
	frag2.takeDamage(5);
	std::cout << std::endl;

	std::cout << MAGENTA << "=== TEST 8: COPY CONSTRUCTOR ===" << RESET << std::endl;
	FragTrap frag3("ToBeCopied");
	frag3.attack("an enemy");
	std::cout << "[ Calling copy constructor ] ";	
	FragTrap frag4(frag3);
	frag4.attack("an anemy");
	std::cout << std::endl;

	std::cout << MAGENTA << "=== TEST 9: COPY ASSIGNMENT OPERATOR ===" << RESET << std::endl;
	FragTrap frag5("Original");
	FragTrap frag6("Assigned Copy");
	frag5.takeDamage(40);
	frag6 = frag5;
	frag6.attack("an enemy");
	std::cout << std::endl;

	std::cout << MAGENTA << "=== DESTRUCTION CHAIN (reverse order) ===" << RESET << std::endl;
}
