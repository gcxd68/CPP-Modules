/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:17:41 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/11 14:35:40 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal {

	public:

		// Default constructor
		Cat(void);

		// Parameterized constructor
		Cat(const std::string& type);

		// Copy constructor
		Cat(const Cat& other);

		// Copy assignment operator
		Cat& operator=(const Cat& other);

		// Destructor
		~Cat(void);

		// Member function(s)
		void makeSound() const;

	private:

		//Attribute(s)
		Brain* _brain;

};

#endif
