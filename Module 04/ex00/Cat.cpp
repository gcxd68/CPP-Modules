/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:17:39 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/11 17:47:08 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

// Default constructor
Cat::Cat(void) : Animal("Cat") {
	std::cout << "Cat default constructor called" << std::endl;
}

// Parameterized constructor
Cat::Cat(const std::string& type) : Animal(type) {
	std::cout << "Cat parameterized constructor called" << std::endl;
}

// Copy constructor
Cat::Cat(const Cat& other) : Animal(other.type) {
	std::cout << "Cat copy constructor called" << std::endl;
}

// Copy assignment operator
Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

// Destructor
Cat::~Cat(void) {
	std::cout << "Cat destructor called" << std::endl;
}

// Member function(s)
void	Cat::makeSound() const {
	std::cout << "Meow! Meow!" << std::endl;
}
