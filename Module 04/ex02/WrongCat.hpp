/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:30:34 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/11 14:47:55 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"
# include <string>

class WrongCat : public WrongAnimal {

	public:

		// Default constructor
		WrongCat(void);

		// Parameterized constructor
		WrongCat(const std::string& type);

		// Copy constructor
		WrongCat(const WrongCat& other);

		// Copy assignment operator
		WrongCat& operator=(const WrongCat& other);

		// Destructor
		~WrongCat(void);

		// Member function(s)
		void makeSound() const;

};

#endif
