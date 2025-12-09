/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 12:30:05 by gdosch            #+#    #+#             */
/*   Updated: 2025/12/09 12:56:08 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange(void) {
	loadDatabase("data.csv");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
	: _database(other._database)
{}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other)
		this->_database = other._database;
	return *this;
}

BitcoinExchange::~BitcoinExchange(void) {}

void BitcoinExchange::loadDatabase(const std::string& csvFile) {
	std::ifstream infile(csvFile.c_str());
	if (!infile.is_open()) {
		std::cout << "Error: could not open database file." << std::endl;
		return;
	}
	
	std::string line;
	std::getline(infile, line); // Skip header "date,exchange_rate"
	
	while (std::getline(infile, line)) {
		size_t commaPos = line.find(',');
		if (commaPos == std::string::npos)
			continue;
		
		std::string date = line.substr(0, commaPos);
		std::string valueStr = line.substr(commaPos + 1);
		
		char* endPtr;
		float rate = std::strtof(valueStr.c_str(), &endPtr);
		
		_database[date] = rate;
	}
	
	infile.close();
}

void BitcoinExchange::processInput(const std::string& inputFile) {
	std::ifstream infile(inputFile.c_str());
	if (!infile.is_open()) {
		std::cout << "Error: could not open file." << std::endl;
		return;
	}
	
	std::string line;
	std::getline(infile, line); // Skip header "date | value"
	
	while (std::getline(infile, line)) {
		size_t pipePos = line.find('|');
		if (pipePos == std::string::npos) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		
		std::string date = line.substr(0, pipePos);
		std::string valueStr = line.substr(pipePos + 1);
		
		// Trim whitespaces
		date.erase(0, date.find_first_not_of(" \t"));
		date.erase(date.find_last_not_of(" \t") + 1);
		valueStr.erase(0, valueStr.find_first_not_of(" \t"));
		valueStr.erase(valueStr.find_last_not_of(" \t") + 1);
		
		// Validate date format
		if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}
		
		// Convert value to float
		char* endPtr;
		float value = std::strtof(valueStr.c_str(), &endPtr);
		
		if (*endPtr != '\0') {
			std::cout << "Error: bad input => " << valueStr << std::endl;
			continue;
		}
		
		// Check value range
		if (value < 0) {
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		
		if (value > 1000) {
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}
		
		// Find closest date in database
		std::map<std::string, float>::const_iterator it = _database.lower_bound(date);
		
		if (it == _database.end() || it->first != date) {
			if (it == _database.begin()) {
				std::cout << "Error: date too early => " << date << std::endl;
				continue;
			}
			--it;
		}
		
		// Calculate result
		float result = value * it->second;
		
		std::cout << date << " => " << value << " = " << result << std::endl;
	}
	
	infile.close();
}
