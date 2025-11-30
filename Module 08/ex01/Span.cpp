/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 18:25:47 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/30 18:35:30 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// ========================================================================== //
//                          Constructors & Destructor                         //
// ========================================================================== //

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span() {}

// ========================================================================== //
//                              Member Functions                              //
// ========================================================================== //

/**
 * Add a single number to the Span
 * Throws ContainerFullException if already at maximum capacity
 */
void Span::addNumber(int number) {
	if (_numbers.size() >= _maxSize) {
		throw ContainerFullException();
	}
	_numbers.push_back(number);
}

/**
 * Find the shortest span (distance) between all stored numbers
 * Approach: Sort the vector, then find minimum difference between adjacent elements
 * Throws NoSpanException if less than 2 numbers stored
 */
int Span::shortestSpan() const {
	if (_numbers.size() < 2) {
		throw NoSpanException();
	}

	// Create a sorted copy to find adjacent differences
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	int minSpan = std::numeric_limits<int>::max();
	
	// Check difference between each adjacent pair
	for (size_t i = 1; i < sorted.size(); ++i) {
		int span = sorted[i] - sorted[i - 1];
		if (span < minSpan) {
			minSpan = span;
		}
	}

	return minSpan;
}

/**
 * Find the longest span (distance) between all stored numbers
 * Approach: Simply find max - min
 * Throws NoSpanException if less than 2 numbers stored
 */
int Span::longestSpan() const {
	if (_numbers.size() < 2) {
		throw NoSpanException();
	}

	int min = *std::min_element(_numbers.begin(), _numbers.end());
	int max = *std::max_element(_numbers.begin(), _numbers.end());

	return max - min;
}

// ========================================================================== //
//                                 Exceptions                                 //
// ========================================================================== //

const char* Span::ContainerFullException::what() const throw() {
	return "Container is full, cannot add more numbers";
}

const char* Span::NoSpanException::what() const throw() {
	return "Not enough numbers to calculate span";
}
