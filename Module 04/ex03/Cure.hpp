/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:43:53 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/17 13:33:47 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria {

	public:

		// Default constructor
		Cure(void);

		// Copy constructor
		Cure(const Cure& other);

		// Copy assignment operator
		Cure& operator=(const Cure& other);

		// Destructor
		virtual ~Cure(void);

		// Core method(s)
		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);

};

#endif
