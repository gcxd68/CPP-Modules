/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:13:03 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/07 14:45:42 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

#define MAGENTA "\033[35m"
#define RESET	"\033[0m"

int main()
{
	std::cout << MAGENTA << "=== TEST 1: CONSTRUCTION CHAIN ===" << RESET << std::endl;
	ScavTrap scav1("Warrior");
	std::cout << std::endl;

	std::cout << MAGENTA << "=== TEST 2: SCAVTRAP ATTACKS ===" << RESET << std::endl;
	scav1.attack("target");
	scav1.attack("another target");
	std::cout << std::endl;

	std::cout << MAGENTA << "=== TEST 3: TAKING DAMAGE ===" << RESET << std::endl;
	scav1.takeDamage(30);
	scav1.takeDamage(40);
	std::cout << std::endl;

	std::cout << MAGENTA << "=== TEST 4: REPAIRING ===" << RESET << std::endl;
	scav1.beRepaired(20);
	std::cout << std::endl;

	std::cout << MAGENTA << "=== TEST 5: GUARD GATE ===" << RESET << std::endl;
	scav1.guardGate();
	std::cout << std::endl;

	std::cout << MAGENTA << "=== TEST 6: COMPARING CLAPTRAP VS SCAVTRAP ===" << RESET << std::endl;
	std::cout << "[ ClapTrap ]" << RESET << std::endl;
	ClapTrap clap("Basic");
	clap.attack("enemy");
	std::cout << "[ ScavTrap ]" << RESET << std::endl;
	ScavTrap scav2("Advanced");
	scav2.attack("enemy");
	std::cout << std::endl;

	std::cout << MAGENTA << "=== TEST 7: COPY CONSTRUCTOR ===" << RESET << std::endl;
	ScavTrap scav3(scav1);
	scav3.attack("enemy");
	std::cout << std::endl;

	std::cout << MAGENTA << "=== DESTRUCTION CHAIN (reverse order) ===" << RESET << std::endl;
}
