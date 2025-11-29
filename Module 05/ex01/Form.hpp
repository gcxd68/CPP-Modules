/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:02:13 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/29 17:12:33 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <exception>
# include <iostream>
# include <string>

class Bureaucrat;

class Form {
	
	private:

		static const unsigned int	HIGHEST_GRADE = 1;
		static const unsigned int	LOWEST_GRADE = 150;
		const std::string			_name;
		bool						_isSigned;
		const unsigned int			_reqSignGrade;
		const unsigned int			_reqExecGrade;

	public:

		// Default constructor
		Form(void);

		// Parameterized constructor
		Form(const std::string& name, unsigned int reqSignGrade, unsigned int reqExecGrade);

		// Copy constructor
		Form(const Form& other);

		// Copy assignment operator
		Form& operator=(const Form& other);

		// Destructor
		~Form(void);

		// Accessor(s)
		const std::string&	getName(void) const;
		bool				getSignedStatus(void) const;
		unsigned int		getReqSignGrade(void) const;
		unsigned int		getReqExecGrade(void) const;

		// Core method(s)
		void				beSigned(const Bureaucrat& b);

		// Exception class(es)
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

};

// Overload of insertion operator
std::ostream&	operator<<(std::ostream& os, const Form& f);

#endif
