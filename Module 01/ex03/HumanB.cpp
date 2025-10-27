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
HumanB::HumanB(const std::string& name) : _name(name), _weapon(NULL) {}

// Denstructor
HumanB::~HumanB() {}

// Accessor(s)
void	HumanB::setWeapon(Weapon& weapon) {
	this->_weapon = &weapon;
}

// Core method(s)
void	HumanB::attack() const {
	if (this->_weapon)
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " has no weapon!" << std::endl;
}
