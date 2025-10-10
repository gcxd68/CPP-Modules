/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 11:19:08 by gdosch            #+#    #+#             */
/*   Updated: 2025/10/10 11:19:11 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <string>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void ) {
	return Account::_nbAccounts;
}

int	Account::getTotalAmount( void ) {
	return Account::_totalAmount;
}

int	Account::getNbDeposits( void ) {
	return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals( void ) {
	return Account::_totalNbWithdrawals;
}

void	Account::_displayTimestamp( void ) {
	std::time_t	time = std::time(NULL);
	std::tm		*localTime = std::localtime(&time);
	char		time_str[19];

	std::strftime(time_str, sizeof(time_str), "[%Y%m%d_%H%M%S] ", localTime);
	std::cout << std::string(time_str);
}

void	Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout
		<< "accounts:"		<< _nbAccounts
		<< ";total:"		<< _totalAmount
		<< ";deposits:"		<< _totalNbDeposits
		<< ";withdrawals:"	<< _totalNbWithdrawals	<< std::endl;
}

Account::Account( int initial_deposit )
	: _accountIndex(_nbAccounts),
	  _amount(initial_deposit),
	  _nbDeposits(0),
	  _nbWithdrawals(0) {
	_nbAccounts++;
	this->_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout
		<< "index:"		<< this->_accountIndex
		<< ";amount:"	<< this->_amount
		<< ";created"	<< std::endl;
}

Account::~Account( void ) {
	_displayTimestamp();
	std::cout
		<< "index:"		<< this->_accountIndex
		<< ";amount:"	<< this->_amount
		<< ";closed"	<< std::endl;
}

void	Account::makeDeposit( int deposit ) {
	const int	p_amount = this->_amount;

	this->_amount += deposit;
	this->_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout
		<< "index:"			<< this->_accountIndex
		<< ";p_amount:"		<< p_amount
		<< ";deposit:"		<< deposit
		<< ";amount:"		<< this->_amount
		<< ";nb_deposits:"	<< this->_nbDeposits	<< std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	const int	p_amount = this->_amount;

	_displayTimestamp();
	std::cout
		<< "index:"			<< this->_accountIndex
		<< ";p_amount:"		<< p_amount
		<< ";withdrawal:";
	if (withdrawal > this->_amount) {
		std::cout << "refused" << std::endl;
		return false;
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	std::cout
		<< withdrawal
		<< ";amount:"			<< this->_amount
		<< ";nb_withdrawals:"	<< this->_nbWithdrawals	<< std::endl;
	return true;
}

int		Account::checkAmount( void ) const {
	return this->_amount;
}

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout
		<< "index:"			<< this->_accountIndex
		<< ";amount:"		<< this->_amount
		<< ";deposits:"		<< this->_nbDeposits
		<< ";withdrawals:"	<< this->_nbWithdrawals	<< std::endl;
}
