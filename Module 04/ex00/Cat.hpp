/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 09:17:41 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/11 13:57:21 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include <string>

class Cat : public Animal {

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

};

#endif
