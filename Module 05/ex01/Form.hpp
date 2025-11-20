/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 10:02:13 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/20 11:53:57 by gdosch           ###   ########.fr       */
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

		const std::string	_name;
		bool				_is_signed;
		const unsigned int	_required_sign_grade;
		const unsigned int	_required_exec_grade;

	public:

		Form(void);

		Form(const std::string& name, unsigned int sign_req, unsigned int exec_req);

		Form(const Form& other);

		Form& operator=(const Form& other);

		~Form(void);

		const std::string&	getName(void) const;
		bool				getSignedStatus(void) const;
		unsigned int		getRequiredSignGrade(void) const;
		unsigned int		getRequiredExecGrade(void) const;

		void				beSigned(const Bureaucrat& b);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& os, const Form& f);

#endif
