/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:58:45 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/11 17:45:19 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

// Default constructor
Brain::Brain() {
	std::cout << "Brain default Constructor called" << std::endl;
	for (size_t i = 0; i < 100; i++)
		this->ideas[i] = "Default idea";
}

// Parameterized constructor
Brain::Brain(const std::string& type) {
	std::cout << "Brain parameterized constructor called" << std::endl;
	for (size_t i = 0; i < 100; i++)
		this->ideas[i] = "I am a " + type;
}

// Copy constructor
Brain::Brain(const Brain &other) {
	std::cout << "Brain copy constructor called" << std::endl;
	for (size_t i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
}

// Copy assignment operator
Brain &Brain::operator=(const Brain &other) {
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &other)
		for (size_t i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	return *this;
}

// Destructor
Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}
