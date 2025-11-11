/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:17:39 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/11 17:43:27 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

// Default constructor
Cat::Cat(void) : AAnimal("Cat") {
	std::cout << "Cat default constructor called" << std::endl;
	this->_brain = new Brain("Cat");
}

// Parameterized constructor
Cat::Cat(const std::string& type) : AAnimal(type) {
	std::cout << "Cat parameterized constructor called" << std::endl;
	this->_brain = new Brain(type);
}

// Copy constructor
Cat::Cat(const Cat& other) : AAnimal(other) {
	std::cout << "Cat copy constructor called" << std::endl;
	this->_brain = new Brain(*other._brain);
}

// Copy assignment operator
Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other) {
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
		this->type = other.type;
	}
	return *this;
}

// Destructor
Cat::~Cat(void) {
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
}

// Member function(s)
void	Cat::makeSound() const {
	std::cout << "Meow! Meow!" << std::endl;
}
