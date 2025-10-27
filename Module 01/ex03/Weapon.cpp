/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:50:32 by gdosch            #+#    #+#             */
/*   Updated: 2025/09/30 13:50:33 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

// Constructor
Weapon::Weapon(const std::string& type) : _type(type) {}

// Destructor
Weapon::~Weapon() {}

// Accessors
const std::string&	Weapon::getType() const {
	return this->_type;
}

void	Weapon::setType(const std::string& type) {
	this->_type = type;
}
