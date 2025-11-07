/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 11:13:11 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/07 14:43:58 by gdosch           ###   ########.fr       */
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
	ClapTrap&	operator=(const ClapTrap& other);

	// Destructor
	~ClapTrap(void);

	// Member function(s)
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

protected:

	//Attribute(s)
	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;

};

#endif
