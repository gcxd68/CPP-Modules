/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 09:18:43 by gdosch            #+#    #+#             */
/*   Updated: 2025/12/04 14:06:19 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

// Unused special member functions
ScalarConverter::ScalarConverter(void) {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }
ScalarConverter::~ScalarConverter(void) {}

// File-scope static function(s)
static bool isChar(const std::string& literal, char& parsedChar) {
	parsedChar = static_cast<char>(literal[0]);
	return (literal.length() == 1 && !std::isdigit(literal[0]) && std::isprint(literal[0]));
}

static bool isInt(const std::string& literal, int& parsedInt) {
	char *endptr;
	long parsedLong = std::strtol(literal.c_str(), &endptr, 10);
	parsedInt = static_cast<int>(parsedLong);
	return (!*endptr && parsedLong >= std::numeric_limits<int>::min() && parsedLong <= std::numeric_limits<int>::max());
}

static bool isFloat(const std::string& literal, float& parsedFloat) {
	char *endptr;
	parsedFloat = std::strtof(literal.c_str(), &endptr);
	return (literal.find_first_of("0123456789") == std::string::npos || literal.find('.') != std::string::npos)
		&& endptr[0] == 'f' && !endptr[1];
}

static bool isDouble(const std::string& literal, double& parsedDouble) {
	char *endptr;
	parsedDouble = std::strtod(literal.c_str(), &endptr);
	return !*endptr;
}

static void printTypes(double value) {
	if (std::isnan(value) || std::isinf(value)) {
		std::cout << "char: impossible\nint: impossible" << std::endl;
		if (value < 0)
			std::cout << "float: -inff\ndouble: -inf" << std::endl;
		else if (value > 0)
			std::cout << "float: +inff\ndouble: +inf" << std::endl;
		else
			std::cout << "float: nanf\ndouble: nan" << std::endl;
		return;
	}
	if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(value)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	if (value == static_cast<int>(value))
		std::cout << "float: " << std::fixed << std::setprecision(1) << value << "f" << std::endl;
	else
		std::cout << "float: " << std::setprecision(std::numeric_limits<float>::digits10) << value << "f" << std::endl;
	if (value == static_cast<int>(value))
		std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
	else
		std::cout << "double: " << std::setprecision(std::numeric_limits<double>::digits10) << value << std::endl;
}

// Core method(s)
void ScalarConverter::convert(const std::string& literal) {
	if (literal.empty()) {
		std::cout << "Error: empty literal" << std::endl;
		return;
	}
	char	parsedChar;
	int		parsedInt;
	float	parsedFloat;
	double	value;
	if (isChar(literal, parsedChar))
		value = parsedChar;
	else if (isInt(literal, parsedInt))
		value = parsedInt;
	else if (isFloat(literal, parsedFloat))
		value = parsedFloat;
	else if (isDouble(literal, value))
		;
	else {
		std::cout << "Error: invalid literal" << std::endl;
		return;
	}
	printTypes(value);
}
