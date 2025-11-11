/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:17:32 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/11 17:42:11 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>

// Default constructor
AAnimal::AAnimal(void) : type("Undefined") {
	std::cout << "AAnimal default constructor called" << std::endl;
}

// Parameterized constructor
AAnimal::AAnimal(const std::string& type) : type(type) {
	std::cout << "AAnimal parameterized constructor called" << std::endl;
}

// Copy constructor
AAnimal::AAnimal(const AAnimal& other) : type(other.type) {
	std::cout << "AAnimal copy constructor called" << std::endl;
}

// Copy assignment operator
AAnimal& AAnimal::operator=(const AAnimal& other) {
	std::cout << "AAnimal copy assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

// Destructor
AAnimal::~AAnimal(void) {
	std::cout << "AAnimal destructor called" << std::endl;
}

// Accessor(s)
std::string	AAnimal::getType() const {
	return this->type;
}
