/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:50:46 by gdosch            #+#    #+#             */
/*   Updated: 2025/09/30 13:50:47 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>

// Forward declaration
class Weapon;

class HumanA {

	public:

		// Constructor / Destructor
		HumanA(const std::string& name, Weapon& weapon);
		~HumanA();

		// Core method(s)
		void	attack() const;

	private:

		// Attribute(s)
		std::string	_name;
		Weapon&		_weapon;

};

#endif
