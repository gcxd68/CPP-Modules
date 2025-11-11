/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:17:42 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/11 17:46:17 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

// Default constructor
Dog::Dog(void) : Animal("Dog") {
	std::cout << "Dog default constructor called" << std::endl;
	this->_brain = new Brain("Dog");
}

// Parameterized constructor
Dog::Dog(const std::string& type) : Animal(type) {
	std::cout << "Dog parameterized constructor called" << std::endl;
	this->_brain = new Brain(type);
}

// Copy constructor
Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->_brain = new Brain(*other._brain);
}

// Copy assignment operator
Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other) {
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
		this->type = other.type;
	}
	return *this;
}

// Destructor
Dog::~Dog(void) {
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
}

// Member function(s)
void	Dog::makeSound() const {
	std::cout << "Woof! Woof!" << std::endl;
}
