/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:30:30 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/11 17:46:25 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

// Default constructor
WrongAnimal::WrongAnimal(void) : type("Undefined") {
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

// Parameterized constructor
WrongAnimal::WrongAnimal(const std::string& type) : type(type) {
	std::cout << "WrongAnimal parameterized constructor called" << std::endl;
}

// Copy constructor
WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

// Copy assignment operator
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

// Destructor
WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string	WrongAnimal::getType() const {
	return this->type;
}

// Member function(s)
void	WrongAnimal::makeSound() const {
	std::cout << "*Generic animal sound*" << std::endl;
}
