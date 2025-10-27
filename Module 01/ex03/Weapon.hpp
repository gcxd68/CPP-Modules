/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:48:40 by gdosch            #+#    #+#             */
/*   Updated: 2025/09/30 13:48:41 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>

class Weapon {

	public:

		// Constructor / Destructor
		Weapon(const std::string& type);
		~Weapon();		

		// Accessor(s)
		const std::string&	getType() const;
		void				setType(const std::string& type);

	private:

		// Attribute(s)
		std::string _type;

};

#endif
