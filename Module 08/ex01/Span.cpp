/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 18:25:47 by gdosch            #+#    #+#             */
/*   Updated: 2025/12/01 15:31:06 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <limits>
#include <vector>

// Default Constructor
Span::Span()
	: _maxSize(0)
{}

// Parameterized constructor
Span::Span(unsigned int N)
	: _maxSize(N)
{}

// Copy constructor
Span::Span(const Span& other)
	: _maxSize(other._maxSize)
	, _numbers(other._numbers)
{}

// Copy assignment operator
Span& Span::operator=(const Span& other) {
	if (this != &other) {
		this->_maxSize = other._maxSize;
		this->_numbers = other._numbers;
	}
	return *this;
}

// Destructor
Span::~Span() {}

// Core method(s)
unsigned int Span::shortestSpan() const {
	if (this->_numbers.size() < 2)
		throw NoSpanException();
	std::vector<int> sorted = this->_numbers;
	std::sort(sorted.begin(), sorted.end());
	unsigned int minSpan = std::numeric_limits<unsigned int>::max();
	for (size_t i = 1; i < sorted.size(); ++i) {
		unsigned int span = sorted[i] - sorted[i - 1];
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

unsigned int Span::longestSpan() const {
	if (this->_numbers.size() < 2)
		throw NoSpanException();
	int min = *std::min_element(this->_numbers.begin(), this->_numbers.end());
	int max = *std::max_element(this->_numbers.begin(), this->_numbers.end());
	return max - min;
}

// Accessor(s)
void Span::addNumber(int number) {
	if (this->_numbers.size() >= this->_maxSize)
		throw ContainerFullException();
	this->_numbers.push_back(number);
}

size_t Span::size() const {
	return this->_numbers.size();
}

int& Span::operator[](size_t index) {
	if (index >= this->_numbers.size())
		throw OutOfRangeException();
	return this->_numbers[index];
}

const int& Span::operator[](size_t index) const {
	if (index >= this->_numbers.size())
		throw OutOfRangeException();
	return this->_numbers[index];
}

// Custom exception(s)
const char* Span::ContainerFullException::what() const throw() {
	return "Container is full, cannot add more numbers";
}

const char* Span::NoSpanException::what() const throw() {
	return "Not enough numbers to calculate span";
}

const char* Span::OutOfRangeException::what() const throw() {
	return "Index out of range";
}
