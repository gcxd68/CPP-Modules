/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:16:16 by gdosch            #+#    #+#             */
/*   Updated: 2025/09/21 14:55:53 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void ) : _contactCount(0), _nextIndex(0) {
}

void PhoneBook::_handleEOF( void ) const {
	std::cout << std::endl << "EOF detected, exiting" << std::endl;
	exit(EXIT_SUCCESS);
}

std::string PhoneBook::_getInput( const std::string& prompt ) const {
	std::string	input;

	while (input.empty())
	{
		std::cout << prompt;
		if (!std::getline(std::cin, input)) {
			std::cout << std::endl;
			_handleEOF();
		}
		if (input.empty())
			std::cout << "\t" << "Field cannot be empty, try again" << std::endl;
	}
	return input;
}

std::string PhoneBook::_getPhoneNumber( void ) const {
	std::string	input;

	while (true) {
		input = _getInput("\tPhone number: ");
		if (input.find_first_not_of("0123456789") == std::string::npos)
			return input;
		std::cout << "\t" << "Phone number must contain only digits, try again" << std::endl;
	}
}

std::string PhoneBook::_truncateString( const std::string& str ) const {
	return (str.length() > 10) ? str.substr(0, 9) + "." : str;
}

void PhoneBook::_addContact( void ) {
	Contact&	newContact = this->_contacts[this->_nextIndex];

	std::cout << std::endl << "\t" << "ADDING NEW CONTACT" << std::endl;
	newContact.setFirstName(_getInput("\tFirst name: "));
	newContact.setLastName(_getInput("\tLast name: "));
	newContact.setNickname(_getInput("\tNickname: "));
	newContact.setPhoneNumber(_getPhoneNumber());
	newContact.setDarkestSecret(_getInput("\tDarkest secret: "));
	this->_nextIndex = (this->_nextIndex + 1) % 8;
	if (this->_contactCount < 8)
		this->_contactCount++;
	std::cout << std::endl << "Contact added successfully" << std::endl;
}

void PhoneBook::_displayAllContacts( void ) const {
	std::cout
		<< std::endl
		<< "\t" << std::setw(10) << "Index" << "|"
		<< std::setw(10) << "First Name" << "|"
		<< std::setw(10) << "Last Name" << "|"
		<< std::setw(10) << "Nickname" << std::endl
		<< "\t" << "----------|----------|----------|----------" << std::endl;
	for (int i = 0; i < this->_contactCount; i++) {
		const Contact& contact = this->_contacts[i];
		std::cout
			<< "\t" << std::setw(10) << i + 1 << "|"
			<< std::setw(10) << _truncateString(contact.getFirstName()) << "|"
			<< std::setw(10) << _truncateString(contact.getLastName()) << "|"
			<< std::setw(10) << _truncateString(contact.getNickname()) << std::endl;
	}
	std::cout << std::endl;
}

void PhoneBook::_displayContact( int index ) const {
	const Contact&	contact = this->_contacts[index];

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

void PhoneBook::_searchContacts( void ) const {
	if (!this->_contactCount)
	{
		std::cout << "No contacts in the phonebook" << std::endl;
		return;
	}
	_displayAllContacts();
	std::string input;
	std::cout << "Enter the index of the contact to display: ";
	if (!std::getline(std::cin, input))
		_handleEOF();
	else if (input.length() == 1 && input[0] > '0' && input[0] - '1' < this->_contactCount)
		_displayContact(input[0] - '1');
	else
		std::cout << "Invalid index" << std::endl;
}

void PhoneBook::run( void ) {
	std::string	command;

	while (true)
	{
		std::cout << "Please use ADD, SEARCH or EXIT: ";
		if (!std::getline(std::cin, command))
			_handleEOF();
		else if (command == "ADD")
			_addContact();
		else if (command == "SEARCH")
			_searchContacts();
		else if (command == "EXIT")
			break;
		else
			std::cout << "Invalid command" << std::endl;
	}
}
