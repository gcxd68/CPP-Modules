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

class PhoneBook {
private:
	Contact		_contacts[8];
	int			_contactCount;
	int			_nextIndex;

	std::string	_truncateString(const std::string& str) const;
	std::string	_getInput(const std::string& prompt) const;
	std::string	_getPhoneNumber(void) const;
	void		_handleEOF(void) const;

public:
	PhoneBook();

	void		addContact(void);
	void		searchContacts(void) const;
	void		displayAllContacts(void) const;
	void		displayContact(int index) const;
	void		run(void);
};

#endif
