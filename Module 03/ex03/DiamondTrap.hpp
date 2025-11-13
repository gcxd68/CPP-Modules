/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 12:14:42 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/13 11:56:46 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {

	public:

		// Default constructor
		DiamondTrap(void);

		// Parameterized constructor
		DiamondTrap(const std::string& name);

		// Copy constructor
		DiamondTrap(const DiamondTrap& other);

		// Copy assignment operator
		DiamondTrap& operator=(const DiamondTrap& other);

		// Destructor
		~DiamondTrap(void);

		// Member function(s)
		void	whoAmI(void);

		// Using declaration
		using	ScavTrap::attack;

	private:

		std::string	_name;  // Nom propre du DiamondTrap

};

#endif
