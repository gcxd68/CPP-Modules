/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:17:43 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/11 14:35:27 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal {

	public:

		// Default constructor
		Dog(void);

		// Parameterized constructor
		Dog(const std::string& type);

		// Copy constructor
		Dog(const Dog& other);

		// Copy assignment operator
		Dog& operator=(const Dog& other);

		// Destructor
		~Dog(void);

		// Member function(s)
		void makeSound() const;

	private:

		//Attribute(s)
		Brain* _brain;

};

#endif
