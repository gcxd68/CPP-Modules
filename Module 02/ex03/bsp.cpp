/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:09:19 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/03 11:09:20 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed orientedArea(const Point& p1, const Point& p2, const Point& p3) {
	return (p2.getX() - p1.getX()) * (p3.getY() - p1.getY())
		- (p3.getX() - p1.getX()) * (p2.getY() - p1.getY());
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed	d1 = orientedArea(point, a, b);
	Fixed	d2 = orientedArea(point, b, c);
	Fixed	d3 = orientedArea(point, c, a);
	bool	allPositive = (d1 > 0) && (d2 > 0) && (d3 > 0);
	bool	allNegative = (d1 < 0) && (d2 < 0) && (d3 < 0);

	return allPositive || allNegative;
}
