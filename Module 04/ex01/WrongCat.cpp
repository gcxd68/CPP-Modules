/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:30:33 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/11 17:46:37 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

// Default constructor
WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {
	std::cout << "WrongCat default constructor called" << std::endl;
}

// Parameterized constructor
WrongCat::WrongCat(const std::string& type) : WrongAnimal(type) {
	std::cout << "WrongCat parameterized constructor called" << std::endl;
}

// Copy constructor
WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	std::cout << "WrongCat copy constructor called" << std::endl;
}

// Copy assignment operator
WrongCat& WrongCat::operator=(const WrongCat& other) {
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	if (this != &other)
		WrongAnimal::operator=(other);
	return *this;
}

// Destructor
WrongCat::~WrongCat(void) {
	std::cout << "WrongCat destructor called" << std::endl;
}

// Member function(s)
void	WrongCat::makeSound() const {
	std::cout << "Meow! Meow!" << std::endl;
}
