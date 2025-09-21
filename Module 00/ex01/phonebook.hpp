/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 18:12:33 by gdosch            #+#    #+#             */
/*   Updated: 2025/09/21 14:02:56 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"
# include <iostream>
# include <iomanip>

class PhoneBook {
private:
	Contact		_contacts[8];
	int			_contactCount;
	int			_nextIndex;

	std::string	_truncateString(const std::string& str) const;
	std::string	_getInput(const std::string& prompt) const;
	std::string	_getPhoneNumber() const;
	void		_handleEOF() const;

public:
	PhoneBook();

	void		addContact();
	void		searchContacts() const;
	void		displayAllContacts() const;
	void		displayContact(int index) const;
	void		run();
};

#endif
