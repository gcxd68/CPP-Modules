/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:17:42 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/11 17:47:15 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

// Default constructor
Dog::Dog(void) : Animal("Dog") {
	std::cout << "Dog default constructor called" << std::endl;
}

// Parameterized constructor
Dog::Dog(const std::string& type) : Animal(type) {
	std::cout << "Dog parameterized constructor called" << std::endl;
}

// Copy constructor
Dog::Dog(const Dog& other) : Animal(other.type) {
	std::cout << "Dog copy constructor called" << std::endl;
}

// Copy assignment operator
Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

// Destructor
Dog::~Dog(void) {
	std::cout << "Dog destructor called" << std::endl;
}

// Member function(s)
void	Dog::makeSound() const {
	std::cout << "Woof! Woof!" << std::endl;
}
