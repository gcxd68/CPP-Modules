/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 09:18:43 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/28 13:00:52 by gdosch           ###   ########.fr       */
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
static bool isPrintableChar(const std::string& literal, char& parsedChar) {
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
	return endptr[0] == 'f' && !endptr[1];
}

static bool isDouble(const std::string& literal, double& parsedDouble) {
	char *endptr;
	parsedDouble = std::strtod(literal.c_str(), &endptr);
	return !*endptr;
}

static void printTypes(double value) {
	std::string types[] = {"char", "int", "float", "double"};
	for (size_t i = 0; i < sizeof(types) / sizeof(*types); i++) {
		std::cout << types[i] << ": ";
		if (i < 2 && (std::isnan(value) || std::isinf(value)
			|| (i == 0 && (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max()))
			|| value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max()))
			std::cout << "impossible";
		else if (i == 0 && !std::isprint(static_cast<int>(value)))
			std::cout << "Non displayable";
		else if (std::isnan(value) || std::isinf(value))
			std::cout << (value > 0 ? "+inf" : value < 0 ? "-inf" : "nan") << (i == 2 ? "f" : "");
		else if (i == 0)
			std::cout << "'" << static_cast<char>(value) << "'";
		else if (i == 1)
			std::cout << static_cast<int>(value);
		else if (value == static_cast<int>(value))
			std::cout << std::fixed << std::setprecision(1) << value << (i == 2 ? "f" : "");
		else if (i == 2)
			std::cout << std::setprecision(std::numeric_limits<float>::digits10) << value << "f";
		else
			std::cout << std::setprecision(std::numeric_limits<double>::digits10) << value;
		std::cout << std::endl;
	}
}

// Core method(s)
void ScalarConverter::convert(const std::string& literal) {
	if (literal.empty()) {
		std::cout << "Error: empty literal" << std::endl;
		return;
	}
	double	value;
	char	parsedChar;
	int		parsedInt;
	float	parsedFloat;
	if (literal == "-inff" || literal == "+inff")
		value = ((literal[0] == '-' ? -1 : 1) * std::numeric_limits<float>::infinity());
	else if (literal == "nanf")
		value = (std::numeric_limits<float>::quiet_NaN());
	else if (literal == "-inf" || literal == "+inf")
		value = (literal[0] == '-' ? -1 : 1) * std::numeric_limits<double>::infinity();
	else if (literal == "nan")
		value = std::numeric_limits<double>::quiet_NaN();
	else if (isPrintableChar(literal, parsedChar))
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
