/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:50:58 by gdosch            #+#    #+#             */
/*   Updated: 2025/09/30 13:50:59 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>

// Constructor
HumanA::HumanA(const std::string& name, Weapon& weapon) : _name(name), _weapon(weapon) {
	std::cout << this->_name << " shows up with a " << this->_weapon.getType() << std::endl;
}

// Destructor
HumanA::~HumanA() {}

// Core method(s)
void HumanA::attack() const {
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
