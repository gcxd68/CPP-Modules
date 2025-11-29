/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:36:09 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/29 18:15:30 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm {

	private:

		//Attribute(s)
		static const unsigned int	SIGN_GRADE = 72;
		static const unsigned int	EXEC_GRADE = 45;
		std::string					_target;
	
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
