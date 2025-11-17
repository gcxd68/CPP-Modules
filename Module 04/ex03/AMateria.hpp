/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:14:54 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/17 13:34:01 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>

// Forward declaration
class ICharacter;

class AMateria
{
	protected:

		// Attribute(s)
		std::string _type;

	public:

		// Default constructor
		AMateria(void);

		// Parameterized constructor
		AMateria(std::string const & type);

		// Copy constructor
		AMateria(const AMateria& other);

		// Copy assignment operator
		AMateria& operator=(const AMateria& other);

		// Destructor
		virtual ~AMateria(void);

		std::string const & getType() const; //Returns the materia type

		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
