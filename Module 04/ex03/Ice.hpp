/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:27:44 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/11 17:38:16 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria {

	public:

		// Default constructor
		Ice();
		
		// Copy constructor
		Ice(const Ice& other);

		// Copy assignment operator
		Ice& operator=(const Ice& other);

		// Destructor
		virtual ~Ice();

		// Core method(s)
		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);

};

#endif
