/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:36:04 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/25 11:20:51 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm {

	private:

		//Attribute(s)
		static const unsigned int	SIGN_GRADE = 25;
		static const unsigned int	EXEC_GRADE = 5;
		std::string					_target;

	public:

		// Default constructor
		PresidentialPardonForm(void);

		// Parameterized constructor
		PresidentialPardonForm(const std::string& target);

		// Copy constructor
		PresidentialPardonForm(const PresidentialPardonForm& other);

		// Copy assignment operator
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

		// Destructor
		~PresidentialPardonForm(void);

		// Core method(s)
		void execute(Bureaucrat const & executor) const;

};

#endif
