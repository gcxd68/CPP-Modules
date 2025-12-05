/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 12:30:03 by gdosch            #+#    #+#             */
/*   Updated: 2025/12/05 13:41:49 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>

class BitcoinExchange {

	private:

		std::map<std::string, float>	_database;

		void	loadDatabase(const std::string& csvData);

	public:

		BitcoinExchange();

		BitcoinExchange(const std::string& csvFile);

		BitcoinExchange(const BitcoinExchange& other);

		BitcoinExchange& operator=(const BitcoinExchange& other);

		~BitcoinExchange(void);

};

#endif