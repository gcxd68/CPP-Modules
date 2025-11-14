/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:13:14 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/13 21:24:07 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

// Default constructor
ClapTrap::ClapTrap(void)
	: _name("Unnamed")
	, _hitPoints(DEFAULT_HIT_POINTS)
	, _energyPoints(DEFAULT_ENERGY_POINTS)
	, _attackDamage(DEFAULT_ATTACK_DAMAGE)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

// Parameterized constructor
ClapTrap::ClapTrap(const std::string& name)
	: _name(name)
	, _hitPoints(DEFAULT_HIT_POINTS)
	, _energyPoints(DEFAULT_ENERGY_POINTS)
	, _attackDamage(DEFAULT_ATTACK_DAMAGE)
{
	std::cout << "ClapTrap " << this->_name << " constructor called" << std::endl;
}

// Copy constructor
ClapTrap::ClapTrap(const ClapTrap& other)
	: _name(other._name)
	, _hitPoints(other._hitPoints)
	, _energyPoints(other._energyPoints)
	, _attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap copy constructor called for " << this->_name << std::endl;
}

// Copy assignment operator
ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return *this;
}

// Destructor
ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap " << this->_name << " destructor called" << std::endl;
}

// Member function(s)
void ClapTrap::attack(const std::string& target)
{
	if (!this->_hitPoints) {
		std::cout << "ClapTrap " << this->_name << " is dead and cannot attack!" << std::endl;
		return;
	}
	if (!this->_energyPoints) {
		std::cout << "ClapTrap " << this->_name << " has no energy left to attack!" << std::endl;
		return;
	}
	this->_energyPoints--;
	std::cout
		<< "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage
		<< " points of damage! (" << this->_hitPoints << " HP, " << this->_energyPoints << " EP left)"
		<< std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (!this->_hitPoints) {
		std::cout << "ClapTrap " << this->_name << " is already dead!" << std::endl;
		return;
	}
	if (this->_hitPoints > amount)
		this->_hitPoints -= amount;
	else
		this->_hitPoints = 0;
	std::cout
		<< "ClapTrap " << this->_name << " takes " << amount << " points of damage! ("
		<< this->_hitPoints << " HP, " << this->_energyPoints << " EP left)"
		<< std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (!this->_hitPoints) {
		std::cout << "ClapTrap " << this->_name << " is dead and cannot be repaired!" << std::endl;
		return;
	}
	if (!this->_energyPoints) {
		std::cout << "ClapTrap " << this->_name << " has no energy left to repair!" << std::endl;
		return;
	}
	this->_energyPoints--;
	if (amount > ~(unsigned int)0 - this->_hitPoints)
		this->_hitPoints = ~(unsigned int)0;
	else
		this->_hitPoints += amount;
	std::cout
		<< "ClapTrap " << this->_name << " repairs itself and gains " << amount
		<< " hit points! (" << this->_hitPoints << " HP, " << this->_energyPoints << " EP left)"
		<< std::endl;
}
