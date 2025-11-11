/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:17:32 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/11 17:46:53 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

// Default constructor
Animal::Animal(void) : type("Undefined") {
	std::cout << "Animal default constructor called" << std::endl;
}

// Parameterized constructor
Animal::Animal(const std::string& type) : type(type) {
	std::cout << "Animal parameterized constructor called" << std::endl;
}

// Copy constructor
Animal::Animal(const Animal& other) : type(other.type) {
	std::cout << "Animal copy constructor called" << std::endl;
}

// Copy assignment operator
Animal& Animal::operator=(const Animal& other) {
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

// Destructor
Animal::~Animal(void) {
	std::cout << "Animal destructor called" << std::endl;
}

// Accessor(s)
std::string	Animal::getType() const {
	return this->type;
}

// Core method(s)
void	Animal::makeSound() const {
	std::cout << "*Generic animal sound*" << std::endl;
}
