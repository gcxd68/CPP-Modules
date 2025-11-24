/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:48:51 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/24 15:50:28 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include <string>

class Intern {

	public:
		// Default constructor
		Intern(void);

		// Copy constructor
		Intern(const Intern& other);

		// Copy assignment operator
		Intern& operator=(const Intern& other);

		// Destructor
		~Intern(void);

		// Core method
		AForm* makeForm(const std::string& formName, const std::string& target);

	private:
		// Helper methods for form creation
		AForm* createShrubberyCreationForm(const std::string& target);
		AForm* createRobotomyRequestForm(const std::string& target);
		AForm* createPresidentialPardonForm(const std::string& target);
};

#endif
