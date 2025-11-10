/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:13:03 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/10 13:18:35 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

#define MAGENTA "\033[35m"
#define RESET	"\033[0m"

int main()
{
	std::cout << MAGENTA << "=== TEST 1: CONSTRUCTION CHAIN ===" << RESET << std::endl;
	ClapTrap clap1("Bob");
	std::cout << std::endl;

	std::cout << MAGENTA << "=== TEST 2: CLAPTRAP ATTACKS ===" << RESET << std::endl;
	for (int i = 0; i < 3; i++)
		clap1.attack("an enemy");
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
	for (int i = 0; i < 5; i++)
		clap1.attack("an enemy");
	std::cout << "[ Trying to attack with no energy left ] " << RESET;
	clap1.attack("should_fail");
	std::cout << "[ Trying to repair with no energy left ] " << RESET;
	clap1.beRepaired(1);
	std::cout << std::endl;

	std::cout << MAGENTA << "=== TEST 6: DEATH SCENARIO ===" << RESET << std::endl;
	ClapTrap clap2("Doomed");
	clap2.takeDamage(5);
	clap2.takeDamage(10);
	std::cout << "[ Trying to attack while dead ] " << RESET;
	clap2.attack("should_fail");
	std::cout << "[ Trying to repair while dead ] " << RESET;
	clap2.beRepaired(5);
	std::cout << "[ Taking damage while already dead ] " << RESET;
	clap2.takeDamage(5);
	std::cout << std::endl;

	std::cout << MAGENTA << "=== TEST 7: COPY CONSTRUCTOR ===" << RESET << std::endl;
	ClapTrap clap3("ToBeCopied");
	clap3.attack("an enemy");
	std::cout << "[ Calling copy constructor ] " << RESET;
	ClapTrap clap4(clap3);
	clap4.attack("an enemy");
	std::cout << std::endl;

	std::cout << MAGENTA << "=== TEST 8: ASSIGNMENT OPERATOR ===" << RESET << std::endl;
	ClapTrap clap5("Original");
	ClapTrap clap6("Assigned Copy");
	clap5.takeDamage(2);
	clap6 = clap5;
	clap6.attack("an enemy");
	std::cout << std::endl;

	std::cout << MAGENTA << "=== TEST 9: DEFAULT CONSTRUCTOR ===" << RESET << std::endl;
	ClapTrap clap7;
	clap7.attack("an enemy");
	std::cout << std::endl;

	std::cout << MAGENTA << "=== DESTRUCTORS WILL BE CALLED NOW ===" << RESET << std::endl;
}
