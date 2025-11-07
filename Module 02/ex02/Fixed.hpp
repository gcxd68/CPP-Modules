/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:17:13 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/01 15:17:14 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {

public:

	// Default constructor
	Fixed(void);

	// Int constructor
	Fixed(const int value);

	// Float constructor
	Fixed(const float value);

	// Copy constructor
	Fixed(const Fixed& other);

	// Copy assignment operator
	Fixed&	operator=(const Fixed& other);

	// Destructor
	~Fixed(void);

	// Accessors
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	// Conversion
	float	toFloat(void) const;
	int		toInt(void) const;

	//Operators
	bool	operator>(const Fixed& other) const;
	bool	operator<(const Fixed& other) const;
	bool	operator>=(const Fixed& other) const;
	bool	operator<=(const Fixed& other) const;
	bool	operator==(const Fixed& other) const;
	bool	operator!=(const Fixed& other) const;
	Fixed	operator+(const Fixed& other) const;
	Fixed	operator-(const Fixed& other) const;
	Fixed	operator*(const Fixed& other) const;
	Fixed	operator/(const Fixed& other) const;
	Fixed&	operator++(void); // Pre-increment
	Fixed	operator++(int); // Post-increment
	Fixed&	operator--(void); // Pre-decrement
	Fixed	operator--(int); // Post-decrement

	// Static member functions
	static Fixed&		min(Fixed& a, Fixed& b);
	static const Fixed&	min(const Fixed& a, const Fixed& b);
	static Fixed&		max(Fixed& a, Fixed& b);
	static const Fixed&	max(const Fixed& a, const Fixed& b);

private:

	//Attributes
	int					_value;
	static const int	_fractionalBits = 8;

};

// Overload of insertion operator
std::ostream&	operator<<(std::ostream& out, const Fixed& fixed);

#endif
