/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 09:18:41 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/27 13:05:34 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

class ScalarConverter {

	private:

		// Default constructor
		ScalarConverter(void);

		// Copy constructor
		ScalarConverter(const ScalarConverter&);

		// Copy assignment operator
		ScalarConverter& operator=(const ScalarConverter&);

		// Destructor
		~ScalarConverter(void);

	public:

		// Core method(s)
		static void convert(const std::string &literal);
	
};

#endif
