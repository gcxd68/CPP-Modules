/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:17:36 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/11 15:21:34 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <string>

class AAnimal {

	public:

		// Default constructor
		AAnimal(void);

		// Parameterized constructor
		AAnimal(const std::string& type);

		// Copy constructor
		AAnimal(const AAnimal& other);

		// Copy assignment operator
		AAnimal& operator=(const AAnimal& other);

		// Destructor
		virtual ~AAnimal(void);

		// Accessor(s)
		std::string getType() const;

		// Core method(s)
		virtual void makeSound() const = 0;

	protected:

		//Attributes
		std::string type;

};

#endif
