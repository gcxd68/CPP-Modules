/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:58:04 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/29 17:14:47 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <iostream>
# include <string>

class AForm;

class Bureaucrat {

	private:

		// Attribute(s)
		static const unsigned int	HIGHEST_GRADE = 1;
		static const unsigned int	LOWEST_GRADE = 150;
		const std::string	_name;
		unsigned int		_grade;

	public:

		// Default constructor
		Bureaucrat(void);

		// Parameterized constructor
		Bureaucrat(const std::string& name, unsigned int grade);

		// Copy constructor
		Bureaucrat(const Bureaucrat& other);

		// Copy assignment operator
		Bureaucrat& operator=(const Bureaucrat& other);

		// Destructor
		~Bureaucrat(void);

		// Accessor(s)
		const std::string&	getName(void) const;
		unsigned int		getGrade(void) const;

		// Core method(s)
		void	incrementGrade(void);
		void	decrementGrade(void);
		void	signForm(AForm& form);
		void	executeForm(AForm const & form) const;

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
std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
