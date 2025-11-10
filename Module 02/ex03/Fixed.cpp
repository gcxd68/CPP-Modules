/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:17:20 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/10 14:51:34 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

// Default constructor
Fixed::Fixed(void) : _value(0) {}

// Int constructor
Fixed::Fixed(const int value) : _value(value << _fractionalBits) {}

// Float constructor
Fixed::Fixed(const float value) : _value(roundf(value * (1 << _fractionalBits))) {}

// Copy constructor
Fixed::Fixed(const Fixed& other) {
	*this = other;
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other)
		this->_value = other.getRawBits();
	return *this;
}

// Destructor
Fixed::~Fixed(void) {}

// Accessors
int Fixed::getRawBits(void) const {
	return this->_value;
}

void Fixed::setRawBits(int const raw) {
	this->_value = raw;
}

// Conversion
float Fixed::toFloat(void) const {
	return (float)this->_value / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
	return this->_value >> _fractionalBits;
}

// Overload of insertion operator
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return out;
}

// Operators
bool Fixed::operator>(const Fixed& other) const {
	return this->_value > other._value;
}

bool Fixed::operator<(const Fixed& other) const {
	return this->_value < other._value;
}

bool Fixed::operator>=(const Fixed& other) const {
	return this->_value >= other._value;
}

bool Fixed::operator<=(const Fixed& other) const {
	return this->_value <= other._value;
}

bool Fixed::operator==(const Fixed& other) const {
	return this->_value == other._value;
}

bool Fixed::operator!=(const Fixed& other) const {
	return this->_value != other._value;
}

Fixed Fixed::operator+(const Fixed& other) const {
	Fixed result;
	result.setRawBits(this->_value + other._value);
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
	Fixed result;
	result.setRawBits(this->_value - other._value);
	return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
	Fixed result;
	result.setRawBits((this->_value * other._value) >> _fractionalBits);
	return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
	Fixed result;
	result.setRawBits((this->_value << _fractionalBits) / other._value);
	return result;
}

// Pre-increment operator
Fixed& Fixed::operator++(void) {
	this->_value++;
	return *this;
}

// Post-increment operator
Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	this->_value++;
	return temp;
}

// Pre-decrement operator
Fixed& Fixed::operator--(void) {
	this->_value--;
	return *this;
}

// Post-decrement operator
Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	this->_value--;
	return temp;
}

// Static member functions
Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b) ? a : b;
}
