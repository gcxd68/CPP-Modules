/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:43:50 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/17 13:33:50 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>

// Default constructor
Cure::Cure(void) : AMateria("cure") {
	// std::cout << "Cure constructor called" << std::endl;
}

// Copy constructor
Cure::Cure(const Cure& other) : AMateria(other) {
	// std::cout << "Cure copy constructor called" << std::endl;
}

// Copy assignment operator
Cure& Cure::operator=(const Cure& other) {
	// std::cout << "Cure assignment operator called" << std::endl;
	AMateria::operator=(other);
	return *this;
}

// Destructor
Cure::~Cure(void) {
	// std::cout << "Cure destructor called" << std::endl;
}

// Core method(s)
AMateria* Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
