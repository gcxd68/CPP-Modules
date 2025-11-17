/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:54:25 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/17 15:02:23 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Floor.hpp"
#include <iostream>
#include <string>

// Default constructor
MateriaSource::MateriaSource(void) {
	// std::cout << "MateriaSource default constructor called" << std::endl;
	for (int i = 0; i < MAX_TEMPLATES; i++)
		_templates[i] = NULL;
}

// Copy constructor
MateriaSource::MateriaSource(const MateriaSource& other) {
	// std::cout << "MateriaSource copy constructor called" << std::endl;
	for (int i = 0; i < MAX_TEMPLATES; i++) {
		if (other._templates[i])
			_templates[i] = other._templates[i]->clone();
		else
			_templates[i] = NULL;
	}
}

// Copy assignment operator
MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
	// std::cout << "MateriaSource assignment operator called" << std::endl;
	if (this != &other) {
		for (int i = 0; i < MAX_TEMPLATES; i++) {
			if (_templates[i]) {
				delete _templates[i];
				_templates[i] = NULL;
			}
		}
		for (int i = 0; i < MAX_TEMPLATES; i++) {
			if (other._templates[i])
				_templates[i] = other._templates[i]->clone();
			else
				_templates[i] = NULL;
		}
	}
	return *this;
}

// Destructor
MateriaSource::~MateriaSource() {
	// std::cout << "MateriaSource destructor called" << std::endl;
	for (int i = 0; i < MAX_TEMPLATES; i++) {
		if (_templates[i])
			delete _templates[i];
	}
}

// Core method(s)
void MateriaSource::learnMateria(AMateria* m) {
	if (!m) {
		std::cout << "MateriaSource tried to learn NULL materia" << std::endl;
		return;
	}
	for (int i = 0; i < MAX_TEMPLATES; i++) {
		if (!_templates[i]) {
			_templates[i] = m->clone();
			std::cout << "MateriaSource learned '" << m->getType() << "' in slot " << i << std::endl;
			delete m;
			return;
		}
	}
	std::cout << "MateriaSource is full, cannot learn '" << m->getType() << "'" << std::endl;
	Floor::getInstance().add(m);
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < MAX_TEMPLATES; i++) {
		if (_templates[i] && _templates[i]->getType() == type) {
			std::cout << "MateriaSource created a materia of type '" << type << "'" << std::endl;
			return _templates[i]->clone();
		}
	}
	std::cout << "MateriaSource cannot create materia of unknown type '" << type << "'" << std::endl;
	return NULL;
}
