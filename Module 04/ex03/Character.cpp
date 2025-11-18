/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:56:19 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/18 12:09:02 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"
#include "Floor.hpp"
#include <iostream>
#include <string>

// Default constructor
Character::Character(void) : _name("unnamed") {
	// std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < MAX_SLOTS; i++)
		_inventory[i] = NULL;
}

// Parameterized constructor
Character::Character(const std::string& name) : _name(name) {
	// std::cout << "Character parameterized constructor called: " << name << std::endl;
	for (int i = 0; i < MAX_SLOTS; i++)
		_inventory[i] = NULL;
}

// Copy constructor
Character::Character(const Character& other) : _name(other._name) {
	// std::cout << "Character copy constructor called" << std::endl;
	for (int i = 0; i < MAX_SLOTS; i++) {
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}

// Copy assignment operator
Character& Character::operator=(const Character& other) {
	// std::cout << "Character assignment operator called" << std::endl;
	if (this != &other) {
		_name = other._name;
		for (int i = 0; i < MAX_SLOTS; i++) {
			if (_inventory[i]) {
				delete _inventory[i];
				_inventory[i] = NULL;
			}
		}
		for (int i = 0; i < MAX_SLOTS; i++) {
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	return *this;
}

// Destructor
Character::~Character() {
	// std::cout << "Character destructor called: " << _name << std::endl;
	for (int i = 0; i < MAX_SLOTS; i++) {
		if (_inventory[i])
			delete _inventory[i];
	}
}

// Accessor(s)
std::string const& Character::getName() const {
	return _name;
}

// Core method(s)
void Character::equip(AMateria* m) {
	if (!m) {
		std::cout << _name << " tried to equip NULL materia" << std::endl;
		return;
	}
	for (int i = 0; i < MAX_SLOTS; i++) {
		if (!_inventory[i]) {
			_inventory[i] = m;
			std::cout
				<< _name << " equipped '" << m->getType()
				<< "' materia in slot " << i << std::endl;
			return;
		}
	}
	std::cout
		<< _name << "'s inventory is full, cannot equip '"
		<< m->getType() << "' materia" << std::endl;
	Floor::getInstance().add(m);
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= MAX_SLOTS)
		std::cout << _name << " tried to unequip invalid slot " << idx << std::endl;
	else if (!_inventory[idx])
		std::cout << _name << " tried to unequip empty slot " << idx << std::endl;
	else {
		std::cout
			<< _name << " unequipped '" << _inventory[idx]->getType()
			<< "' materia from slot " << idx << std::endl;
		Floor::getInstance().add(_inventory[idx]);
		_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= MAX_SLOTS)
		std::cout << _name << " tried to use invalid slot: " << idx << std::endl;
	else if (!_inventory[idx])
		std::cout << _name << " tried to use empty slot: " << idx << std::endl;
	else
		_inventory[idx]->use(target);
}
