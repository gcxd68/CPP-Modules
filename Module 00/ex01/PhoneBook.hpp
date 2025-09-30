/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:12:33 by gdosch            #+#    #+#             */
/*   Updated: 2025/09/21 14:34:16 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <iomanip>
# include <cstdlib>

class PhoneBook {

public:
	// Constructor
	PhoneBook( void );

	// Main loop
	void		run( void );

private:
	// Attributes
	Contact		_contacts[8];
	int			_contactCount;
	int			_nextIndex;

	// Core methods
	void		_addContact( void );
	void		_searchContacts( void ) const;
	void		_displayAllContacts( void ) const;
	void		_displayContact( int index ) const;

	// Helpers
	void		_handleEOF( void ) const;
	std::string	_getInput( const std::string& prompt ) const;
	std::string	_getPhoneNumber( void ) const;
	std::string	_truncateString( const std::string& str ) const;
};

#endif
