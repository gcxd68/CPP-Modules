/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:17:20 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/10 14:50:04 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

// Default constructor
Fixed::Fixed(void) : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

// Copy constructor
Fixed::Fixed(const Fixed& other) {
	*this = other;
	std::cout << "Copy constructor called" << std::endl;
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other)
		this->_value = other.getRawBits();
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

// Destructor
Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

// Accessors
int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits(int const raw) {
	this->_value = raw;
}
