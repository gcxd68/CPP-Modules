/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:36:11 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/24 15:48:32 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

	private:

	
		std::string _target;
	
	public:

		// Default constructor
		ShrubberyCreationForm(void);

		// Parameterized constructor
		ShrubberyCreationForm(const std::string& target);

		// Copy constructor
		ShrubberyCreationForm(const ShrubberyCreationForm& other);

		// Copy assignment operator
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

		// Destructor
		~ShrubberyCreationForm(void);

		// Core method(s)
		void execute(Bureaucrat const & executor) const;

};

#endif
