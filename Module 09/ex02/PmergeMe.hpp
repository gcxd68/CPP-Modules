/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:36:36 by gdosch            #+#    #+#             */
/*   Updated: 2025/12/16 13:22:40 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <cstddef>
# include <deque>
# include <list>

typedef std::deque<unsigned int> UIntDeque;
typedef std::deque<std::pair<unsigned int, unsigned int> > UIntPairDeque;
typedef std::list<unsigned int> UIntList;
typedef std::list<std::pair<unsigned int, unsigned int> > UIntPairList;

class PmergeMe {

	private:

		// Attributes
		UIntDeque _deque;
		UIntList _list;

		// Ford-Johnson for std::deque
		void createPairs(UIntDeque& seq, UIntPairDeque& pairs) const;
		void sortPairs(UIntPairDeque& pairs) const;
		void buildMainChain(const UIntPairDeque& pairs, UIntDeque& mainChain) const;
		void insertPending(const UIntPairDeque& pairs, UIntDeque& mainChain) const;
		void insertStraggler(const UIntDeque& seq, UIntDeque& mainChain) const;
		void fordJohnson(UIntDeque& seq) const;

		// Ford-Johnson for std::list
		void createPairs(UIntList& seq, UIntPairList& pairs) const;
		void sortPairs(UIntPairList& pairs) const;
		void buildMainChain(const UIntPairList& pairs, UIntList& mainChain) const;
		void insertPending(const UIntPairList& pairs, UIntList& mainChain) const;
		void insertStraggler(const UIntList& seq, UIntList& mainChain) const;
		void fordJohnson(UIntList& seq) const;

	public:

		// Default constructor
		PmergeMe(void);

		// Parameterized constructors
		explicit PmergeMe(const UIntDeque& deque);
		explicit PmergeMe(const UIntList& list);

		// Copy constructor
		PmergeMe(const PmergeMe& other);

		// Copy assignment operator
		PmergeMe& operator=(const PmergeMe& other);

		// Destructor
		~PmergeMe(void);

		// Accessors
		const UIntDeque& getDeque(void) const;
		const UIntList& getList(void) const;

};

#endif
