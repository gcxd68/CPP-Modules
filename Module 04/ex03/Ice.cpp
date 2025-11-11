/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:28:28 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/11 17:28:43 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>

// Default constructor
Ice::Ice() : AMateria("ice") {
	std::cout << "Ice constructor called" << std::endl;
}

// Copy constructor
Ice::Ice(const Ice& other) : AMateria(other) {
	std::cout << "Ice copy constructor called" << std::endl;
}

// Copy assignment operator
Ice& Ice::operator=(const Ice& other) {
	std::cout << "Ice assignment operator called" << std::endl;
	AMateria::operator=(other);
	return *this;
}

// Destructor
Ice::~Ice() {
	std::cout << "Ice destructor called" << std::endl;
}

// Core method(s)
AMateria* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
