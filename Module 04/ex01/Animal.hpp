/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:17:36 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/11 13:56:36 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal {

	public:

		// Default constructor
		Animal(void);

		// Parameterized constructor
		Animal(const std::string& type);

		// Copy constructor
		Animal(const Animal& other);

		// Copy assignment operator
		Animal& operator=(const Animal& other);

		// Destructor
		virtual ~Animal(void);

		// Accessor(s)
		std::string getType() const;

		// Core method(s)
		virtual void makeSound() const;

	protected:

		//Attributes
		std::string type;

};

#endif
