/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:36:36 by gdosch            #+#    #+#             */
/*   Updated: 2025/12/15 15:46:55 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <cstddef>
# include <deque>
# include <limits>
# include <list>
# include <stdexcept>
# include <vector>

typedef std::deque<unsigned int> UIntDeque;
typedef std::deque<std::pair<unsigned int, unsigned int> > UIntPairDeque;
typedef std::list<unsigned int> UIntList;
typedef std::list<std::pair<unsigned int, unsigned int> > UIntPairList;

template <typename Container>
class PmergeMe {

	private:

		// Attribute(s)
		Container _container;

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

		// Fallback for unsupported containers
		template <typename OtherContainer>
		void fordJohnson(OtherContainer&) const;

	public:

		// Default constructor
		PmergeMe(void);

		// Parameterized constructor
		explicit PmergeMe(const Container& container);

		// Copy constructor
		PmergeMe(const PmergeMe& other);

		// Copy assignment operator
		PmergeMe& operator=(const PmergeMe& other);

		// Destructor
		~PmergeMe(void);

		// Core method(s)
		void sort(void);

		// Accessor(s)
		size_t size(void) const;
		const Container& getContainer(void) const;

};

// Free function(s)
void generateInsertionOrder(size_t n, std::vector<size_t>& order);

// Fallback for unsupported containers
template <typename Container>
template <typename OtherContainer>
void PmergeMe<Container>::fordJohnson(OtherContainer&) const {
    throw std::runtime_error("Error: Unsupported container type, must be std::deque or std::list");
}

// Ford-Johnson for std::deque
template <typename Container>
void PmergeMe<Container>::createPairs(UIntDeque& seq, UIntPairDeque& pairs) const {
	size_t n = seq.size();
	for (size_t i = 0; i < n / 2; i++) {
		unsigned int a = seq[2 * i];
		unsigned int b = seq[2 * i + 1];
		pairs.push_back((a > b) ? std::make_pair(a, b) : std::make_pair(b, a));
	}
}

template <typename Container>
void PmergeMe<Container>::sortPairs(UIntPairDeque& pairs) const {
	if (pairs.size() <= 1)
		return;
	UIntDeque largerOnly;
	for (size_t i = 0; i < pairs.size(); i++)
		largerOnly.push_back(pairs[i].first);
	fordJohnson(largerOnly);
	UIntPairDeque sortedPairs;
	for (size_t i = 0; i < largerOnly.size(); i++) {
		for (size_t j = 0; j < pairs.size(); j++) {
			if (pairs[j].first == largerOnly[i]) {
				sortedPairs.push_back(pairs[j]);
				break;
			}
		}
	}
	pairs = sortedPairs;
}

template <typename Container>
void PmergeMe<Container>::buildMainChain(const UIntPairDeque& pairs, UIntDeque& mainChain) const {
	if (!pairs.empty())
		mainChain.push_back(pairs[0].second);
	for (size_t i = 0; i < pairs.size(); i++)
		mainChain.push_back(pairs[i].first);
}

template <typename Container>
void PmergeMe<Container>::insertPending(const UIntPairDeque& pairs, UIntDeque& mainChain) const {
	std::vector<size_t> insertOrder;
	generateInsertionOrder(pairs.size() - 1, insertOrder);
	for (size_t i = 0; i < insertOrder.size(); i++) {
		size_t idx = insertOrder[i];
		if (idx && idx < pairs.size()) {
			size_t searchLimit = 0;
			for (size_t j = 0; j < mainChain.size(); j++) {
				if (mainChain[j] == pairs[idx].first) {
					searchLimit = j + 1;
					break;
				}
			}
			size_t left = 0, right = searchLimit;
			while (left < right) {
				size_t mid = left + (right - left) / 2;
				if (mainChain[mid] < pairs[idx].second)
					left = mid + 1;
				else
					right = mid;
			}
			mainChain.insert(mainChain.begin() + left, pairs[idx].second);
		}
	}
}

template <typename Container>
void PmergeMe<Container>::insertStraggler(const UIntDeque& seq, UIntDeque& mainChain) const {
	size_t n = seq.size();
	if (n % 2) {
		unsigned int straggler = seq[n - 1];
		size_t left = 0, right = mainChain.size();
		while (left < right) {
			size_t mid = left + (right - left) / 2;
			if (mainChain[mid] < straggler)
				left = mid + 1;
			else
				right = mid;
		}
		mainChain.insert(mainChain.begin() + left, straggler);
	}
}

template <typename Container>
void PmergeMe<Container>::fordJohnson(UIntDeque& seq) const {
	if (seq.size() <= 1)
		return;
	UIntPairDeque pairs;
	createPairs(seq, pairs);
	sortPairs(pairs);
	UIntDeque mainChain;
	buildMainChain(pairs, mainChain);
	insertPending(pairs, mainChain);
	insertStraggler(seq, mainChain);
	seq = mainChain;
}

// Ford-Johnson for std::list
template <typename Container>
void PmergeMe<Container>::createPairs(UIntList& seq, UIntPairList& pairs) const {
	size_t n = seq.size();
	UIntList::iterator it = seq.begin();
	for (size_t i = 0; i < n / 2; i++) {
		unsigned int a = *it++;
		unsigned int b = *it++;
		pairs.push_back((a > b) ? std::make_pair(a, b) : std::make_pair(b, a));
	}
}

template <typename Container>
void PmergeMe<Container>::sortPairs(UIntPairList& pairs) const {
	if (pairs.size() <= 1)
		return;
	UIntList largerOnly;
	for (UIntPairList::iterator pit = pairs.begin();
		 pit != pairs.end(); ++pit)
		largerOnly.push_back(pit->first);
	fordJohnson(largerOnly);
	UIntPairList sortedPairs;
	for (UIntList::iterator lit = largerOnly.begin();
		 lit != largerOnly.end(); ++lit) {
		for (UIntPairList::iterator pit = pairs.begin();
			 pit != pairs.end(); ++pit) {
			if (pit->first == *lit) {
				sortedPairs.push_back(*pit);
				break;
			}
		}
	}
	pairs = sortedPairs;
}

template <typename Container>
void PmergeMe<Container>::buildMainChain(const UIntPairList& pairs, UIntList& mainChain) const {
	if (!pairs.empty())
		mainChain.push_back(pairs.begin()->second);
	for (UIntPairList::const_iterator pit = pairs.begin();
		 pit != pairs.end(); ++pit)
		mainChain.push_back(pit->first);
}

template <typename Container>
void PmergeMe<Container>::insertPending(const UIntPairList& pairs, UIntList& mainChain) const {
	std::vector<size_t> insertOrder;
	generateInsertionOrder(pairs.size() - 1, insertOrder);
	for (size_t i = 0; i < insertOrder.size(); i++) {
		size_t idx = insertOrder[i];
		if (idx && idx < pairs.size()) {
			UIntPairList::const_iterator pit = pairs.begin();
			std::advance(pit, idx);
			UIntList::iterator searchEnd = mainChain.begin();
			while (searchEnd != mainChain.end() && *searchEnd != pit->first)
				++searchEnd;
			if (searchEnd != mainChain.end())
				++searchEnd;
			UIntList::iterator insertPos = mainChain.begin();
			while (insertPos != searchEnd && *insertPos < pit->second)
				++insertPos;
			mainChain.insert(insertPos, pit->second);
		}
	}
}

template <typename Container>
void PmergeMe<Container>::insertStraggler(const UIntList& seq, UIntList& mainChain) const {
	size_t n = seq.size();
	if (n % 2) {
		UIntList::const_iterator lastIt = seq.begin();
		std::advance(lastIt, n - 1);
		unsigned int straggler = *lastIt;
		UIntList::iterator insertPos = mainChain.begin();
		while (insertPos != mainChain.end() && *insertPos < straggler)
			++insertPos;
		mainChain.insert(insertPos, straggler);
	}
}

template <typename Container>
void PmergeMe<Container>::fordJohnson(UIntList& seq) const {
	if (seq.size() <= 1)
		return;
	UIntPairList pairs;
	createPairs(seq, pairs);
	sortPairs(pairs);
	UIntList mainChain;
	buildMainChain(pairs, mainChain);
	insertPending(pairs, mainChain);
	insertStraggler(seq, mainChain);
	seq = mainChain;
}

// Default constructor
template <typename Container>
PmergeMe<Container>::PmergeMe(void) : _container() {}

// Parameterized constructor
template <typename Container>
PmergeMe<Container>::PmergeMe(const Container& container) : _container(container) {}

// Copy constructor
template <typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe& other) : _container(other._container) {}

// Copy assignment operator
template <typename Container>
PmergeMe<Container>& PmergeMe<Container>::operator=(const PmergeMe& other) {
	if (this != &other)
		_container = other._container;
	return *this;
}

// Destructor
template <typename Container>
PmergeMe<Container>::~PmergeMe(void) {}

// Core method(s)
template <typename Container>
void PmergeMe<Container>::sort(void) {
	fordJohnson(_container);
}

// Accessor(s)
template <typename Container>
size_t PmergeMe<Container>::size(void) const {
	return _container.size();
}

template <typename Container>
const Container& PmergeMe<Container>::getContainer(void) const {
	return _container;
}

#endif
