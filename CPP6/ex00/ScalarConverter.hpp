/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschwart <eschwart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:03:01 by eschwart          #+#    #+#             */
/*   Updated: 2025/11/17 11:12:24 by eschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class ScalarConverter {

	private:

		// =====================================================================
		// Handlers

		// Default Constructor
		ScalarConverter( void );
		// Copy Constructor
		ScalarConverter( const ScalarConverter &other );
		// Assignation operator
		ScalarConverter&operator=(const ScalarConverter &other);
		// Destructor
		~ScalarConverter( void );

		// =====================================================================
		// Methods

		static bool isChar( const std::string &str );
		static bool isInt( const std::string &str );
		static bool isFloat( const std::string &str );
		static bool isDouble( const std::string &str );
		static bool isSpecial( const std::string &str );

		static void convertFromChar( const char &c );
		static void convertFromInt( const int &nbr );
		static void convertFromFloat( const float &f);
		static void convertFromDouble( const double &ff );

	public:

		// =====================================================================
		// Methods

		static void convert( const std::string &literal );
};
