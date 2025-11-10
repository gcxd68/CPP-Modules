/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 10:20:40 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/10 13:59:15 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

// Default constructor
FragTrap::FragTrap(void) : ClapTrap() {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

// Parameterized constructor
FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << this->_name << " constructor called" << std::endl;
}

// Copy constructor
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "FragTrap copy constructor called for " << this->_name << std::endl;
}

// Copy assignment operator
FragTrap& FragTrap::operator=(const FragTrap& other) {
	if (this != &other)
		ClapTrap::operator=(other);
	std::cout << "FragTrap copy assignment operator called" << std::endl;
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
