/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 12:30:03 by gdosch            #+#    #+#             */
/*   Updated: 2025/12/19 10:39:41 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>

class BitcoinExchange {

	private:

		// Attribute(s)
		std::map<std::string, float> _database;

		// Core method(s)
		void loadDatabase(const std::string& csvData);

	public:

		// Default constructor
		BitcoinExchange(void);

		// Parameterized constructor
		BitcoinExchange(const std::string& csvFile);

		// Copy constructor
		BitcoinExchange(const BitcoinExchange& other);

		// Copy assignment operator
		BitcoinExchange& operator=(const BitcoinExchange& other);

		// Destructor
		~BitcoinExchange(void);

		// Core method(s)
		void processInput(const std::string& inputFile);

};

#endif
