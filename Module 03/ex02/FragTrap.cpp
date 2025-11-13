/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:20:40 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/13 11:40:53 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

// Default constructor
FragTrap::FragTrap(void) : ClapTrap() {
	std::cout << "FragTrap default constructor called" << std::endl;
	this->_hitPoints = DEFAULT_HIT_POINTS;
	this->_energyPoints = DEFAULT_ENERGY_POINTS;
	this->_attackDamage = DEFAULT_ATTACK_DAMAGE;
}

// Parameterized constructor
FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	std::cout << "FragTrap " << this->_name << " constructor called" << std::endl;
	this->_hitPoints = DEFAULT_HIT_POINTS;
	this->_energyPoints = DEFAULT_ENERGY_POINTS;
	this->_attackDamage = DEFAULT_ATTACK_DAMAGE;
}

// Copy constructor
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "FragTrap copy constructor called for " << this->_name << std::endl;
}

// Copy assignment operator
FragTrap& FragTrap::operator=(const FragTrap& other) {
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

// Destructor
FragTrap::~FragTrap(void) {
	std::cout << "FragTrap " << this->_name << " destructor called" << std::endl;
}

// Member function(s)
void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << this->_name << " requests a positive high five!" << std::endl;
}
