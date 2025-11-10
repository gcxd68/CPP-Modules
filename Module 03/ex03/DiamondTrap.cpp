/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:14:47 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/10 14:18:38 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

// Default constructor
DiamondTrap::DiamondTrap(void)
	: ClapTrap("Unnamed_clap_name")
	, FragTrap()
	, ScavTrap()
	, _name("Unnamed")
{
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

// Parameterized constructor
DiamondTrap::DiamondTrap(const std::string& name)
	: ClapTrap(name + "_clap_name")
	, FragTrap(name)
	, ScavTrap(name)
	, _name(name)
{
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << this->_name << " constructor called" << std::endl;
}

// Copy constructor
DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other)
	, FragTrap(other)
	, ScavTrap(other)
	, _name(other._name)
{
	std::cout << "DiamondTrap copy constructor called for " << this->_name << std::endl;
}

// Copy assignment operator
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
		this->_name = other._name;
	}
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	return *this;
}

// Destructor
DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap " << this->_name << " destructor called" << std::endl;
}

// Member function(s)
void DiamondTrap::whoAmI(void) {
	std::cout << "I am DiamondTrap " << this->_name 
		<< " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}
