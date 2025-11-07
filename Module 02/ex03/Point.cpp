/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:08:38 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/03 11:08:38 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Default constructor
Point::Point(void) : _x(0), _y(0) {}

// Parameterized Constructor
Point::Point(const float x, const float y) : _x(x), _y(y) {}

// Copy constructor
Point::Point(const Point& other) : _x(other._x), _y(other._y) {}

// Copy assignment operator
Point& Point::operator=(const Point& other) {
	(void)other;
	return *this;
}

// Destructor
Point::~Point(void) {}

const Fixed& Point::getX(void) const {
	return this->_x;
}

const Fixed& Point::getY(void) const {
	return this->_y;
}
