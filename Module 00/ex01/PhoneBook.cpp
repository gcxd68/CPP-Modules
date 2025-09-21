/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:16:16 by gdosch            #+#    #+#             */
/*   Updated: 2025/09/21 10:38:04 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>

PhoneBook::PhoneBook() : _contactCount(0), _nextIndex(0) {
}

PhoneBook::~PhoneBook() {
}

void PhoneBook::_handleEOF() const {
	std::cout << std::endl << "EOF detected, exiting" << std::endl;
	exit(0);
}

std::string PhoneBook::_getInput(const std::string& prompt) const
{
	std::string input;
	
	while (input.empty())
	{
		std::cout << prompt;
		if (!std::getline(std::cin, input))
			_handleEOF();
		if (input.empty())
			std::cout << "\t" << "Field cannot be empty, try again" << std::endl;
	}
	return input;
}

std::string PhoneBook::_truncateString(const std::string& str) const {
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void PhoneBook::addContact() {
	Contact newContact;

	std::cout
		<< std::endl
		<< "\t" << "ADDING NEW CONTACT" << std::endl;
	newContact.setFirstName(_getInput("\tFirst name: "));
	newContact.setLastName(_getInput("\tLast name: "));
	newContact.setNickname(_getInput("\tNickname: "));
	newContact.setPhoneNumber(_getInput("\tPhone number: "));
	newContact.setDarkestSecret(_getInput("\tDarkest secret: "));
	this->_contacts[this->_nextIndex] = newContact;
	this->_nextIndex = (this->_nextIndex + 1) % 8;
	if (this->_contactCount < 8)
		this->_contactCount++;
	std::cout << std::endl << "Contact added successfully" << std::endl;
}

void PhoneBook::displayAllContacts() const {
	std::cout
		<< std::endl
		<< "\t" << std::setw(10) << "Index" << "|"
		<< std::setw(10) << "First Name" << "|"
		<< std::setw(10) << "Last Name" << "|"
		<< std::setw(10) << "Nickname" << std::endl
		<< "\t" << "----------|----------|----------|----------" << std::endl;
	for (int i = 0; i < this->_contactCount; i++)
		std::cout
			<< "\t" << std::setw(10) << i + 1 << "|"
			<< std::setw(10) << _truncateString(this->_contacts[i].getFirstName()) << "|"
			<< std::setw(10) << _truncateString(this->_contacts[i].getLastName()) << "|"
			<< std::setw(10) << _truncateString(this->_contacts[i].getNickname()) << std::endl;
	std::cout << std::endl;
}

void PhoneBook::displayContact(int index) const {
	const Contact& contact = this->_contacts[index];
	std::cout
		<< std::endl
		<< "\t" << "CONTACT DETAILS" << std::endl
		<< "\t" << "First name: " << contact.getFirstName() << std::endl
		<< "\t" << "Last name: " << contact.getLastName() << std::endl
		<< "\t" << "Nickname: " << contact.getNickname() << std::endl
		<< "\t" << "Phone number: " << contact.getPhoneNumber() << std::endl
		<< "\t" << "Darkest secret: " << contact.getDarkestSecret() << std::endl
		<< std::endl;
}

void PhoneBook::searchContacts() const
{
	if (!this->_contactCount)
	{
		std::cout << "No contacts in the phonebook" << std::endl;
		return;
	}
	displayAllContacts();
	std::string input;
	std::cout << "Enter the index of the contact to display: ";
	if (!std::getline(std::cin, input))
		_handleEOF();
	else if (input.length() != 1 || input[0] < '1' || input[0] - '0' > this->_contactCount)
		std::cout << "Invalid index" << std::endl;
	else
		displayContact(input[0] - '1');
}

void PhoneBook::run() {
	std::string command;
	while (true)
	{
		std::cout << "Please use ADD, SEARCH, or EXIT: ";
		if (!std::getline(std::cin, command))
			_handleEOF();
		else if (command == "EXIT")
			break;
		else if (command == "ADD")
			addContact();
		else if (command == "SEARCH")
			searchContacts();
		else
			std::cout << "Invalid command" << std::endl;
	}
}
