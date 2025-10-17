/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 13:22:48 by gdosch            #+#    #+#             */
/*   Updated: 2025/09/29 13:22:50 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>

class Zombie {

public:
	// Constructor
	Zombie( const std::string &name );

	// Destructor
	~Zombie( void );

private:
	// Method(s)
	void		announce( void );

	// Attribute(s)
	std::string	_name;

};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif
