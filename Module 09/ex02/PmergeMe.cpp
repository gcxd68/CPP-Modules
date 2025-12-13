/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:36:39 by gdosch            #+#    #+#             */
/*   Updated: 2025/12/13 22:56:40 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <sstream>
#include <stdexcept>

// Default constructor
PmergeMe::PmergeMe(void) {}

// Copy constructor
PmergeMe::PmergeMe(const PmergeMe& other)
	: _vec(other._vec)
	, _deq(other._deq)
{}

// Copy assignment operator
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		_vec = other._vec;
		_deq = other._deq;
	}
	return *this;
}

// Destructor
PmergeMe::~PmergeMe(void) {}

// Core method(s)
void PmergeMe::parseInput(int argc, char** argv) {
	if (argc < 2)
		throw std::runtime_error("Error: no input provided");
	for (int i = 1; i < argc; i++) {
		char* end;
		long num = std::strtol(argv[i], &end, 10);
		if (*end || num < 0 || num > std::numeric_limits<unsigned int>::max())
			throw std::runtime_error("Error");
		_vec.push_back(static_cast<unsigned int>(num));
		_deq.push_back(static_cast<unsigned int>(num));
	}
}

// Jacobsthal sequence (tk = (2^(k+1) + (-1)^k) / 3)
unsigned int PmergeMe::jacobsthal(size_t n) const {
	if (n < 2)
		return n;
	int power = 1 << (n + 1);
	int sign = (n % 2) ? -1 : 1;
	return (power + sign) / 3;
}

// Public method(s)
void PmergeMe::sortVector(void) {
	fordJohnson<std::vector<unsigned int>, std::vector<std::pair<unsigned int, unsigned int> > >(_vec);
}

void PmergeMe::sortDeque(void) {
	fordJohnson<std::deque<unsigned int>, std::deque<std::pair<unsigned int, unsigned int> > >(_deq);
}

void PmergeMe::displayBefore(void) const {
	std::cout << "Before:";
	for (size_t i = 0; i < _vec.size(); i++)
		std::cout << " " << _vec[i];
	std::cout << std::endl;
}

void PmergeMe::displayAfter(void) const {
	std::cout << "After: ";
	for (size_t i = 0; i < _vec.size(); i++)
		std::cout << " " << _vec[i];
	std::cout << std::endl;
}

size_t PmergeMe::size(void) const {
	return _vec.size();
}

void PmergeMe::verifySort(void) const {
	if (_vec.size() != _deq.size())
		throw std::runtime_error("Error: containers differ");
	for (size_t i = 0; i < _vec.size(); i++)
		if (_vec[i] != _deq[i])
			throw std::runtime_error("Error: containers differ");
	std::cout << "Both containers are identical" << std::endl;
}
