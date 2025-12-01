/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:03:13 by eschwart          #+#    #+#             */
/*   Updated: 2025/11/17 15:44:31 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <iostream>
#include <climits>
#include <cmath>
#include <cctype>
#include <cstdlib>

// ============================================================================
// Handlers

// Default Constructor
ScalarConverter::ScalarConverter() {}

// Copy Constructor
ScalarConverter::ScalarConverter( const ScalarConverter &other ) {

	(void)other;
}

// Assignation operator
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {

	(void)other;
	return *this;
}

// Destructor
ScalarConverter::~ScalarConverter() {}

// =============================================================================
// Methods

bool ScalarConverter::isChar( const std::string &str ) {

	return( str.length() == 1 && !std::isdigit(str[0]) );
}

bool ScalarConverter::isInt( const std::string &str ) {

	if ( str.empty()) return false;

	char *endptr;
	long val = std::strtol(str.c_str(), &endptr, 10);

	return (
		*endptr == '\0' && // string total
		val >= INT_MIN && // no underflow
		val <= INT_MAX); // no overflow
}

bool ScalarConverter::isFloat( const std::string &str ) {

	if ( str.length() < 2 )
		return false;

	if ( str[str.length() - 1]  != 'f' )
		return false;

	std::string numberPart = str.substr(0, str.length() - 1);

	char *endptr;
	std::strtod(numberPart.c_str(), &endptr);

	return (*endptr == '\0');
}

bool ScalarConverter::isDouble( const std::string &str ) {

	if ( str.empty() )
		return false;

	if ( str[str.length() - 1] == 'f' )
		return false;

	char *endptr;
	std::strtod(str.c_str(), &endptr);

	return (*endptr == '\0');
}

bool ScalarConverter::isSpecial( const std::string &str ) {

	return(
		str == "nan" || str == "nanf" ||
		str == "+inf" || str=="-inf" ||
		str == "+inff" || str == "-inff" );
}

void ScalarConverter::convertFromChar( const char &c ) {

	// Convert to char
	if ( std::isprint(c) )
		std::cout << "char: '" << c << "'\n";

	else
		std::cout << "char: Non displayable\n";

	// Convert to int
	std::cout << "int: " << static_cast<int>(c) << "\n";

	// Convert to float
	std::cout << "float: " << static_cast<float>(c) << ".0f\n";

	// Convert to double
	std::cout << "double: " << static_cast<double>(c) << ".0\n";
}

void ScalarConverter::convertFromInt( const int &nbr ) {

	// Convert to char
	if ( nbr >= 0 && nbr <= 127 )
	{
		if ( std::isprint(static_cast<char>(nbr)) )
			std::cout << "char: '" << static_cast<char>(nbr) << "'\n";
		else
			std::cout << "char: Non displayable\n";
	}

	else
		std::cout << "char: Impossible\n";

	// Convert to int
	std::cout << "int: " << nbr << "\n";

	// Convert to float
	std::cout << "float: " << static_cast<float>(nbr) << ".0f\n";

	// Convert to double
	std::cout << "double: " << static_cast<double>(nbr) << ".0\n";
}

void ScalarConverter::convertFromFloat( const float &f ) {

	// Convert to char
	if ( f == static_cast<int>(f) && f >= 0 && f <= 127 )
	{
		if ( std::isprint(static_cast<char>(f)) )
			std::cout << "char: '" << static_cast<char>(f) << "'\n";
		else
			std::cout << "char: Non displayable\n";
	}

	else
		std::cout << "char: impossible\n";

	// Convert to int
	if ( f >= static_cast<float>(INT_MIN) && f <= static_cast<float>(INT_MAX) && f == static_cast<int>(f) )

		std::cout << "int: " << static_cast<int>(f) << "\n";
	else
		std::cout << "int: impossible\n";

	// Convert to float
	if ( f == static_cast<int>(f) )
		std::cout << "float: " << f << ".0f\n";

	else
		std::cout << "float: " << f << "f\n";

	// Convert to double
	if ( f == static_cast<int>(f) )
		std::cout << "double: " << static_cast<double>(f) << ".0\n";

	else
		std::cout << "double: " << static_cast<double>(f) << "\n";
}

void ScalarConverter::convertFromDouble( const double &ff ) {

	// Convert to char
	if ( ff == static_cast<int>(ff) && ff >= 0 && ff <= 127 )
	{
		if ( std::isprint(static_cast<char>(ff)) )
			std::cout << "char: '" << static_cast<char>(ff) << "'\n";
		else
			std::cout << "char: Non displayable\n";
	}

	else
		std::cout << "char: impossible\n";

	// Convert to int
	if ( ff >= static_cast<double>(INT_MIN) && ff <= static_cast<double>(INT_MAX) && ff == static_cast<int>(ff) )
		std::cout << "int: " << static_cast<int>(ff) << "\n";

	else
		std::cout << "int: impossible\n";

	// Convert to float
	if ( ff == static_cast<int>(ff) )
		std::cout << "float: " << static_cast<float>(ff) << ".0f\n";

	else
		std::cout << "float: " << static_cast<float>(ff) << "f\n";


	// Convert to double
	if ( ff == static_cast<int>(ff) )
		std::cout << "double: " << ff << ".0\n";

	else
		std::cout << "double: " << ff << "\n";
}

void ScalarConverter::convert( const std::string &literal ) {

	if ( isSpecial(literal) )
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";

		if ( literal == "nan" || literal == "nanf" )
		{
			std::cout << "float: nanf\n";
			std::cout << "double: nan\n";
		}

		else if ( literal == "+inf" )
		{
			std::cout << "float: +inff\n";
			std::cout << "double: +inf\n";
		}

		else if (literal == "-inf" )
		{
			std::cout << "float: -inff\n";
			std::cout << "double: -inf\n";
		}

		else if ( literal == "+inff" )
		{
			std::cout << "float: +inff\n";
			std::cout << "double: +inf\n";
		}

		else if (literal == "-inff" )
		{
			std::cout << "float: -inff\n";
			std::cout << "double: -inf\n";
		}
	}

	else if ( isChar(literal) )
	{
		char c = literal[0];
		convertFromChar(c);
	}

	else if ( isInt(literal) )
	{
		char *endptr;
		long val = std::strtol(literal.c_str(), &endptr, 10);
		int nbr = static_cast<int>(val);
		convertFromInt(nbr);
	}

	else if ( isFloat(literal) )
	{
		float f = static_cast<float>(std::atof(literal.c_str()));
		convertFromFloat(f);
	}

	else if ( isDouble(literal) )
	{
		double ff = (std::atof(literal.c_str()));
		convertFromDouble(ff);
	}

	else
		std::cout << "Error: WTF is that...\n";
}
