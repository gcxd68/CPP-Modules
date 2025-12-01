/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:22:18 by eschwart          #+#    #+#             */
/*   Updated: 2025/11/21 10:55:15 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// ============================================================================
// Handlers

// Default Constructor
Span::Span() : _N(0) {}

// Custom Constructor
Span::Span( unsigned int N ) : _N(N) {}

// Copy Constructor
Span::Span( const Span &other ) : _N(other._N), _numbers(other._numbers) {}

// Assignation operator
Span &Span::operator=(const Span &other) {

	if ( this != &other ) {

		this->_N = other._N;
		this->_numbers = other._numbers;
	}
	return *this;
}

// Destructor
Span::~Span() {}

// =============================================================================
// Methods

void Span::addNumber( int number ) {

	if ( _numbers.size() >= _N )
		throw SpanFullException();

	_numbers.push_back(number);
}

unsigned int Span::longestSpan() {

	if ( _numbers.size() < 2 )
		throw NoSpanException();

	int min = *std::min_element(_numbers.begin(), _numbers.end());
	int max = *std::max_element(_numbers.begin(), _numbers.end());

	return max - min;
}

unsigned int Span::shortestSpan() {

	if ( _numbers.size() < 2 )
		throw NoSpanException();

	std::vector<int> sorted = _numbers; // copy -> no mod
	std::sort(sorted.begin(), sorted.end());

	unsigned int minSpan = sorted[1] - sorted[0];

	for ( size_t i = 0; i < sorted.size() - 1; i++ ) {

		unsigned int span = sorted[i + 1] - sorted[i];

		if ( span < minSpan )
			minSpan = span;
	}

	return minSpan;
}

// ============================================================================
// Exceptions

const char *Span::SpanFullException::what() const throw () {

	return "Span is full";
}

const char *Span::NoSpanException::what() const throw () {

	return "Not enough elements to calculate span";
}

