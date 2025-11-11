/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:56:47 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/11 17:26:08 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter {

	private:

		std::string			_name;
		static const int	MAX_SLOTS = 4;
		AMateria*			_inventory[MAX_SLOTS];

	public:

		// Default constructor
		Character();

		// Parameterized constructor
		Character(std::string const& name);

		// Copy constructor
		Character(const Character& other);

		// Copy assignment operator
		Character& operator=(const Character& other);

		// Destructor
		virtual ~Character();

		// Accessor(s)
		virtual std::string const& getName() const;

		// Core method(s)
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);

};

#endif
