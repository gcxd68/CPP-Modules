/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 09:18:43 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/27 13:50:12 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

// Default constructor
ScalarConverter::ScalarConverter(void) {}

// Copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter&) {}

// Copy assignment operator
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) {
	return *this;
}

// Destructor
ScalarConverter::~ScalarConverter(void) {}

// File-scope static function(s)
static bool isPrintableChar(const std::string& literal) {
	return (literal.length() == 1 && !std::isdigit(literal[0]) && std::isprint(literal[0]));
}

static bool isInt(const std::string& literal) {
	char *endptr;
	long val = std::strtol(literal.c_str(), &endptr, 10);
	return (!*endptr && val >= std::numeric_limits<int>::min() && val <= std::numeric_limits<int>::max());
}

static bool isFloatOrDouble(const std::string& literal) {
	char *endptr;
	std::strtod(literal.c_str(), &endptr);
	if (literal[literal.length() - 1] == 'f')
		return endptr[0] == 'f' && !endptr[1];
	else
		return !*endptr;
}

static bool isImpossible(double value, double min, double max) {
	return std::isnan(value) || std::isinf(value) || value < min || value > max;
}

static void printChar(double value) {
	std::cout << "char: ";
	if (isImpossible(value, std::numeric_limits<char>::min(), std::numeric_limits<char>::max()))
		std::cout << "impossible";
	else if (!std::isprint(static_cast<int>(value)))
		std::cout << "Non displayable";
	else
		std::cout << "'" << static_cast<char>(value) << "'";
	std::cout << std::endl;
}

static void printInt(double value) {
	std::cout << "int: ";
	if (isImpossible(value, std::numeric_limits<int>::min(), std::numeric_limits<int>::max()))
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(value);
	std::cout << std::endl;
}

static void printFloat(double value) {
	std::cout << "float: ";
	float f = static_cast<float>(value);
	if (std::isnan(value))
		std::cout << "nanf";
	else if (std::isinf(value))
		std::cout << (value > 0 ? "+inff" : "-inff");
	else
		std::cout << std::fixed << std::setprecision(1) << f << "f";
	std::cout << std::endl;
}

static void printDouble(double value) {
	std::cout << "double: ";
	if (std::isnan(value))
		std::cout << "nan";
	else if (std::isinf(value))
		std::cout << (value > 0 ? "+inf" : "-inf");
	else
		std::cout << std::fixed << std::setprecision(1) << value;
	std::cout << std::endl;
}

static void printAllTypes(double value) {
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}

// Core method(s)
void ScalarConverter::convert(const std::string& literal) {
	if (literal.empty()) {
		std::cout << "Error: empty literal" << std::endl;
		return;
	}
	double value;
	if (literal == "-inff" || literal == "+inff")
		value = static_cast<double>((literal[0] == '-' ? -1.0f : 1.0f) * std::numeric_limits<float>::infinity());
	else if (literal == "nanf")
		value = static_cast<double>(std::numeric_limits<float>::quiet_NaN());
	else if (literal == "-inf" || literal == "+inf")
		value = (literal[0] == '-' ? -1.0 : 1.0) * std::numeric_limits<double>::infinity();
	else if (literal == "nan")
		value = std::numeric_limits<double>::quiet_NaN();
	else if (isPrintableChar(literal))
		value = static_cast<double>(literal[0]);
	else if (isInt(literal))
		value = static_cast<double>(std::atoi(literal.c_str()));
	else if (isFloatOrDouble(literal))
		value = std::strtod(literal.c_str(), NULL);
	else {
		std::cout << "Error: invalid literal" << std::endl;
		return;
	}
	printAllTypes(value);
}
