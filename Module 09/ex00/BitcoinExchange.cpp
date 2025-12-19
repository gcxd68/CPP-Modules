/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 12:30:05 by gdosch            #+#    #+#             */
/*   Updated: 2025/12/19 10:39:33 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <ctime>

BitcoinExchange::BitcoinExchange(void) {
	loadDatabase("data.csv");
}

BitcoinExchange::BitcoinExchange(const std::string& csvFile) {
	loadDatabase(csvFile);
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
	std::getline(infile, line);
	while (std::getline(infile, line)) {
		size_t commaPos = line.find(',');
		std::string date = line.substr(0, commaPos);
		std::string valueStr = line.substr(commaPos + 1);
		float rate = std::strtof(valueStr.c_str(), NULL);
		_database[date] = rate;
	}
	infile.close();
}

static void trimWhiteSpaces(std::string& str) {
	str.erase(0, str.find_first_not_of(" \f\n\r\t\v"));
	str.erase(str.find_last_not_of(" \f\n\r\t\v") + 1);
}

static bool isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

static bool isFutureDate(int year, int month, int day) {
	time_t now = time(0);
	tm* today = localtime(&now);
	int currentYear = 1900 + today->tm_year;
	int currentMonth = 1 + today->tm_mon;
	int currentDay = today->tm_mday;
	if (year > currentYear) return true;
	if (year < currentYear)	return false;
	if (month > currentMonth) return true;
	if (month < currentMonth) return false;
	if (day > currentDay) return true;
	return false;
}

static bool isValidDate(const std::string& date) {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	std::string yearStr = date.substr(0, 4);
	std::string monthStr = date.substr(5, 2);
	std::string dayStr = date.substr(8, 2);
	if (yearStr.find_first_not_of("0123456789") != std::string::npos
		|| monthStr.find_first_not_of("0123456789") != std::string::npos
		|| dayStr.find_first_not_of("0123456789") != std::string::npos)
		return false;
	int year, month, day;
	std::istringstream(yearStr) >> year;
	std::istringstream(monthStr) >> month;
	std::istringstream(dayStr) >> day;
	if (year < 2009 || month < 1 || month > 12 || day < 1 || (year == 2009 && month == 1 && day == 1))
		return false;
	int daysInMonth[] = {31, (isLeapYear(year) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (day > daysInMonth[month - 1])
		return false;
	if (isFutureDate(year, month, day))
		return false;
	return true;
}

void BitcoinExchange::processInput(const std::string& inputFile) {
	std::ifstream infile(inputFile.c_str());
	if (!infile.is_open()) {
		std::cout << "Error: could not open input file." << std::endl;
		return;
	}
	std::string line;
	bool isFirstLine = true;
	while (std::getline(infile, line)) {
		if (isFirstLine) {
			isFirstLine = false;
			if (line == "date | value")
				continue;
			std::cout << "Error: bad or no header => " << line << std::endl;
		}
		size_t pipePos = line.find('|');
		if (pipePos == std::string::npos) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string date = line.substr(0, pipePos);
		std::string valueStr = line.substr(pipePos + 1);
		trimWhiteSpaces(date);
		trimWhiteSpaces(valueStr);
		if (!valueStr.find("1000."))
			if (valueStr.substr(5).find_first_not_of('0') != std::string::npos) {
				std::cout << "Error: too large a number." << std::endl;
				continue;
			}
		char* endPtr;
		float value = std::strtof(valueStr.c_str(), &endPtr);
		if (!isValidDate(date) || *endPtr)
			std::cout << "Error: bad input => " << line << std::endl;
		else if (value < 0 || value > 1000)
			std::cout << "Error: " << (value < 0 ? "not a positive" : "too large a") << " number." << std::endl;
		else {
			std::map<std::string, float>::const_iterator it = _database.lower_bound(date);
			if (it == _database.end() || it->first != date)
				it--;
			float result = value * it->second;
			std::cout << date << " => " << value << " = " << result << std::endl;
		}
	}
	infile.close();
}
