/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 14:25:48 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/07 14:46:03 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

// Default constructor
ScavTrap::ScavTrap(void)
	: ClapTrap()
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

// Parameterized constructor
ScavTrap::ScavTrap(const std::string& name)
	: ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << this->_name << " constructor called" << std::endl;
}

// Copy constructor
ScavTrap::ScavTrap(const ScavTrap& other)
	: ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called for " << this->_name << std::endl;
}

// Copy assignment operator
ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

// Destructor
ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap " << this->_name << " destructor called" << std::endl;
}

// Member function(s)
void ScavTrap::attack(const std::string& target) {
	if (!this->_hitPoints) {
		std::cout << "ScavTrap " << this->_name << " is dead and cannot attack!" << std::endl;
		return;
	}
	if (!this->_energyPoints) {
		std::cout << "ScavTrap " << this->_name << " has no energy left to attack!" << std::endl;
		return;
	}
	this->_energyPoints--;
	std::cout << "ScavTrap " << this->_name << " fiercely attacks " << target 
		<< ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode!" << std::endl;
}
