/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:54:43 by gdosch            #+#    #+#             */
/*   Updated: 2025/11/11 17:25:40 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource {

	private:

		static const int	MAX_TEMPLATES = 4;
		AMateria*			_templates[MAX_TEMPLATES];

	public:

		// Default constructor
		MateriaSource();

		// Copy constructor
		MateriaSource(const MateriaSource& other);

		// Copy assignment operator
		MateriaSource& operator=(const MateriaSource& other);

		// Destructor
		virtual ~MateriaSource();

		// Interface implementation
		virtual void learnMateria(AMateria* m);
		virtual AMateria* createMateria(std::string const& type);

};

#endif
