/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:56:47 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/17 13:47:07 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include <string>

// Forward declaration(s)
class AMateria;

class Character : public ICharacter {

	private:

		// Constant(s)
		static const int	MAX_SLOTS = 4;

		// Attribute(s)
		AMateria*			_inventory[MAX_SLOTS];
		std::string			_name;

	public:

		// Default constructor
		Character(void);

		// Parameterized constructor
		Character(const std::string& name);

		// Copy constructor
		Character(const Character& other);

		// Copy assignment operator
		Character& operator=(const Character& other);

		// Destructor
		virtual ~Character();

		// Accessor(s)
		virtual std::string const & getName() const;

		// Interface implementation
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);

};

#endif
