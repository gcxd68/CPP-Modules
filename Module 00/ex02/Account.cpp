/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:00:51 by gdosch            #+#    #+#             */
/*   Updated: 2025/09/21 15:23:21 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void) {
	return _nbAccounts;
}

int Account::getTotalAmount(void) {
	return _totalAmount;
}

int Account::getNbDeposits(void) {
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout
		<< "accounts:" << _nbAccounts
		<< ";total:" << _totalAmount
		<< ";deposits:" << _totalNbDeposits
		<< ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void) {
	const std::time_t t = std::time(0);
	const std::tm* now = std::localtime(&t);

	std::cout
		<< "[" << (now->tm_year + 1900)
		<< std::setfill('0') << std::setw(2) << (now->tm_mon + 1)
		<< std::setfill('0') << std::setw(2) << now->tm_mday << "_"
		<< std::setfill('0') << std::setw(2) << now->tm_hour
		<< std::setfill('0') << std::setw(2) << now->tm_min
		<< std::setfill('0') << std::setw(2) << now->tm_sec << "] ";
}

Account::Account(int initial_deposit)
	: _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";created" << std::endl;
}

Account::~Account(void) {
	_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";closed" << std::endl;
}

void Account::makeDeposit(int deposit) {
	int p_amount = this->_amount;

	this->_amount += deposit;
	this->_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex
		<< ";p_amount:" << p_amount
		<< ";deposit:" << deposit
		<< ";amount:" << this->_amount
		<< ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
	const int p_amount = this->_amount;

	_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex
		<< ";p_amount:" << p_amount
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
		<< ";amount:" << this->_amount
		<< ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return true;
}

int Account::checkAmount(void) const {
	return this->_amount;
}

void Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";deposits:" << this->_nbDeposits
		<< ";withdrawals:" << this->_nbWithdrawals << std::endl;
}
