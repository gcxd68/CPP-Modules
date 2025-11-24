/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:36:09 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/24 15:14:31 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm {

	private:

		//Attribute(s)
		std::string _target;
	
	public:

		// Default constructor
		RobotomyRequestForm(void);

		// Parameterized constructor
		RobotomyRequestForm(const std::string& target);

		// Copy constructor
		RobotomyRequestForm(const RobotomyRequestForm& other);

		// Copy assignment operator
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

		// Destructor
		~RobotomyRequestForm(void);

		// Core method(s)
		void execute(Bureaucrat const & executor) const;

};

#endif
