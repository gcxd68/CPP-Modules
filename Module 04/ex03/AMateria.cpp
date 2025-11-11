/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:22:15 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/11 17:41:25 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

// Default constructor
AMateria::AMateria() : _type("unknown") {
	std::cout << "AMateria default constructor called" << std::endl;
}

// Parameterized constructor
AMateria::AMateria(std::string const& type) : _type(type) {
	std::cout << "AMateria type constructor called: " << type << std::endl;
}

// Copy constructor
AMateria::AMateria(const AMateria& other) : _type(other._type) {
	std::cout << "AMateria copy constructor called" << std::endl;
}

// Copy assignment operator
AMateria& AMateria::operator=(const AMateria& other) {
	std::cout << "AMateria assignment operator called" << std::endl;
	(void)other;
	return *this;
}

// Destructor
AMateria::~AMateria() {
	std::cout << "AMateria destructor called: " << _type << std::endl;
}

// Accessor(s)
std::string const& AMateria::getType() const {
	return this->_type;
}

// Core method(s)
void AMateria::use(ICharacter& target) {
	std::cout << "AMateria used on " << target.getName() << std::endl;
}
