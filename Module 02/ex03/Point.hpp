/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:08:30 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/10 15:33:19 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {

public:

	// Default constructor
	Point(void);

	// Parameterized Constructor
	Point(const float x, const float y);

	// Copy constructor
	Point(const Point& other);

	// Copy assignment operator
	Point&	operator=(const Point& other);

	// Destructor
	~Point(void);

	// Accessors
	const Fixed&	getX(void) const;
	const Fixed&	getY(void) const;

private:

	// Attributes
	const Fixed	_x;
	const Fixed	_y;

};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
