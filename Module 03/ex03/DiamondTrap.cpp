/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:14:47 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/13 21:27:49 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

// Default constructor
DiamondTrap::DiamondTrap(void)
	: ClapTrap("Unnamed_clap_name")
	, _name("Unnamed")
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	this->_hitPoints = FragTrap::DEFAULT_HIT_POINTS;
	this->_energyPoints = ScavTrap::DEFAULT_ENERGY_POINTS;
	this->_attackDamage = FragTrap::DEFAULT_ATTACK_DAMAGE;
}

// Parameterized constructor
DiamondTrap::DiamondTrap(const std::string& name)
	: ClapTrap(name + "_clap_name")
	, _name(name)
{
	std::cout << "DiamondTrap " << this->_name << " constructor called" << std::endl;
	this->_hitPoints = FragTrap::DEFAULT_HIT_POINTS;
	this->_energyPoints = ScavTrap::DEFAULT_ENERGY_POINTS;
	this->_attackDamage = FragTrap::DEFAULT_ATTACK_DAMAGE;
}

// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other)
	, _name(other._name)
{
	std::cout << "DiamondTrap copy constructor called for " << this->_name << std::endl;
}

// Copy assignment operator
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
		this->_name = other._name;
	}
	return *this;
}

// Destructor
DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap " << this->_name << " destructor called" << std::endl;
}

// Member function(s)
void DiamondTrap::whoAmI(void) {
	std::cout
		<< "I am DiamondTrap " << this->_name 
		<< " and my ClapTrap name is " << ClapTrap::_name
		<< std::endl;
}
