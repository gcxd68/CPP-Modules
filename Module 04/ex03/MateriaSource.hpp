/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:54:43 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/17 14:10:56 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include <string>

// Forward declaration(s)
class AMateria;

class MateriaSource : public IMateriaSource {

	private:

		// Constant(s)
		static const int	MAX_TEMPLATES = 4;

		// Attribute(s)
		AMateria*			_templates[MAX_TEMPLATES];

	public:

		// Default constructor
		MateriaSource(void);

		// Copy constructor
		MateriaSource(const MateriaSource& other);

		// Copy assignment operator
		MateriaSource& operator=(const MateriaSource& other);

		// Destructor
		virtual ~MateriaSource();

		// Interface implementation
		virtual void learnMateria(AMateria*);
		virtual AMateria* createMateria(std::string const & type);

};

#endif
