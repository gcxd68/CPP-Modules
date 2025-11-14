/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 14:25:54 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/13 11:56:02 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

	public:

		// Default constructor
		ScavTrap(void);

		// Parameterized constructor
		ScavTrap(const std::string& name);

		// Copy constructor
		ScavTrap(const ScavTrap& other);

		// Copy assignment operator
		ScavTrap& operator=(const ScavTrap& other);

		// Destructor
		~ScavTrap(void);

		// Member function(s)
		void	attack(const std::string& target); // Override
		void	guardGate(void);

	protected:

		// Constant(s)
		static const unsigned int	DEFAULT_HIT_POINTS = 100;
		static const unsigned int	DEFAULT_ENERGY_POINTS = 50;
		static const unsigned int	DEFAULT_ATTACK_DAMAGE = 20;

};

#endif
