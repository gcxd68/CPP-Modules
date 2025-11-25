/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:48:51 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/25 11:15:29 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>

class AForm;

class Intern {

	private:

		// Helper method(s)
		AForm* createShrubberyCreationForm(const std::string& target);
		AForm* createRobotomyRequestForm(const std::string& target);
		AForm* createPresidentialPardonForm(const std::string& target);

	public:

		// Default constructor
		Intern(void);

		// Copy constructor
		Intern(const Intern&);

		// Copy assignment operator
		Intern& operator=(const Intern& other);

		// Destructor
		~Intern(void);

		// Core method(s)
		AForm* makeForm(const std::string& formName, const std::string& target);

};

#endif
