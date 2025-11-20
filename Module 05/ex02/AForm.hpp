/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:02:13 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/20 13:58:02 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <exception>
# include <iostream>
# include <string>

class Bureaucrat;

class AForm {
	
	private:

		const std::string	_name;
		bool				_isSigned;
		const unsigned int	_requiredSignGrade;
		const unsigned int	_requiredExecGrade;

	public:

		// Default constructor
		AForm(void);

		// Parameterized constructor
		AForm(const std::string& name, unsigned int sign_req, unsigned int exec_req);

		// Copy constructor
		AForm(const AForm& other);

		// Copy assignment operator
		AForm& operator=(const AForm& other);

		// Destructor
		~AForm(void);

		// Accessor(s)
		const std::string&	getName(void) const;
		bool				getSignedStatus(void) const;
		unsigned int		getRequiredSignGrade(void) const;
		unsigned int		getRequiredExecGrade(void) const;

		// Core method(s)
		void				beSigned(const Bureaucrat& b);
		virtual void		execute(Bureaucrat const & executor) const = 0;

		// Exception class(es)
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class FormNotSignedException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

};

// Overload of insertion operator
std::ostream&	operator<<(std::ostream& os, const AForm& f);

#endif
