/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:08:30 by gdosch            #+#    #+#             */
/*   Updated: 2025/09/21 14:34:31 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void Contact::setFirstName( const std::string& firstName ) {
	this->_firstName = firstName;
}

void Contact::setLastName( const std::string& lastName ) {
	this->_lastName = lastName;
}

void Contact::setNickname( const std::string& nickname ) {
	this->_nickname = nickname;
}

void Contact::setPhoneNumber( const std::string& phoneNumber ) {
	this->_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret( const std::string& darkestSecret ) {
	this->_darkestSecret = darkestSecret;
}

std::string Contact::getFirstName( void ) const {
	return this->_firstName;
}

std::string Contact::getLastName( void ) const {
	return this->_lastName;
}

std::string Contact::getNickname( void ) const {
	return this->_nickname;
}

std::string Contact::getPhoneNumber( void ) const {
	return this->_phoneNumber;
}

std::string Contact::getDarkestSecret( void ) const {
	return this->_darkestSecret;
}
