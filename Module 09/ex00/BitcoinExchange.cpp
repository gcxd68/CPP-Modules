/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 12:30:05 by gdosch            #+#    #+#             */
/*   Updated: 2025/12/05 12:57:53 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {
	const std::string& csvFile = "data.csv";
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {}
		
BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::loadDatabase()