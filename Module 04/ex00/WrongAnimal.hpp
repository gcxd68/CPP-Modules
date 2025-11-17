/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:30:32 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/16 10:21:45 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class WrongAnimal {

	public:

		// Default constructor
		WrongAnimal(void);

		// Parameterized constructor
		WrongAnimal(const std::string& type);

		// Copy constructor
		WrongAnimal(const WrongAnimal& other);

		// Copy assignment operator
		WrongAnimal& operator=(const WrongAnimal& other);

		// Destructor
		virtual ~WrongAnimal(void);

		// Accessor(s)
		std::string	getType() const;

		// Core method(s)
		void makeSound() const;

	protected:

		//Attributes
		std::string	type;

};

#endif
