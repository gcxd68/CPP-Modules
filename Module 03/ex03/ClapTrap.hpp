/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:13:11 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/13 11:54:57 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap {

	public:

		// Default constructor
		ClapTrap(void);

		// Parameterized constructor
		ClapTrap(const std::string& name);

		// Copy constructor
		ClapTrap(const ClapTrap& other);

		// Copy assignment operator
		ClapTrap& operator=(const ClapTrap& other);

		// Destructor
		~ClapTrap(void);

		// Member function(s)
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

	protected:

		// Constant(s)
		static const unsigned int	DEFAULT_HIT_POINTS = 10;
		static const unsigned int	DEFAULT_ENERGY_POINTS = 10;
		static const unsigned int	DEFAULT_ATTACK_DAMAGE = 0;

		//Attribute(s)
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;

};

#endif
