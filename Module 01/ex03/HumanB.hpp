/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:51:12 by gdosch            #+#    #+#             */
/*   Updated: 2025/09/30 13:51:13 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>

// Forward declaration
class Weapon;

class HumanB {

	public:

		// Constructor / Destructor
		explicit HumanB(const std::string& name);
		~HumanB();	

		// Accessor(s)
		void	setWeapon(Weapon& weapon);

		// Core method(s)
		void	attack() const;

	private:

		// Attribute(s)
		std::string	_name;
		Weapon*		_weapon;

};

#endif
