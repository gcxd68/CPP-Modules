/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:51:21 by gdosch            #+#    #+#             */
/*   Updated: 2025/09/30 13:51:22 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

// Constructor
HumanB::HumanB(const std::string& name) : _name(name), _weapon(NULL) {
	std::cout << this->_name << " shows up" << std::endl;
}

// Denstructor
HumanB::~HumanB() {}

// Accessor(s)
void	HumanB::setWeapon(Weapon& weapon) {
	this->_weapon = &weapon;
	std::cout << this->_name << " grabs a " << this->_weapon->getType() << std::endl;
}

// Core method(s)
void	HumanB::attack() const {
	std::cout << this->_name;
	if (this->_weapon)
		std::cout << " attacks with their " << this->_weapon->getType();
	else
		std::cout << " cannot attack, he has no weapon!";
	std::cout << std::endl;
}
