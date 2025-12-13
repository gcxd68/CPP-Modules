/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:36:36 by gdosch            #+#    #+#             */
/*   Updated: 2025/12/13 22:28:38 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>

class PmergeMe {

	private:

		// Attribute(s)
		std::vector<unsigned int>	_vec;
		std::deque<unsigned int>	_deq;
	
		// Core method(s)
		unsigned int jacobsthal(size_t n) const;

		// Ford-Johnson Algorithm
		template <typename SeqContainer>
		void generateInsertionOrder(size_t n, SeqContainer& order) const;
		template <typename SeqContainer>
		void binaryInsert(SeqContainer& arr, unsigned int value, size_t end);
		template <typename SeqContainer, typename PairContainer>
		void fordJohnson(SeqContainer& arr);

	public:

		// Default constructor
		PmergeMe(void);

		// Copy constructor
		PmergeMe(const PmergeMe& other);

		// Copy assignment operator
		PmergeMe& operator=(const PmergeMe& other);

		// Destructor
		~PmergeMe(void);

		// Core method(s)
		void parseInput(int argc, char** argv);
		void sortDeque(void);
		void sortVector(void);
		void displayBefore(void) const;
		void displayAfter(void) const;
		void verifySort(void) const;
	
		// Getter(s)
		size_t size(void) const;

};

// Ford-Johnson Algorithm
template <typename SeqContainer>
void PmergeMe::generateInsertionOrder(size_t n, SeqContainer& order) const {
	order.clear();
	if (n <= 0)
		return;
	SeqContainer jacob;
	unsigned int jac;
	for (size_t i = 1; (jac = jacobsthal(i)) <= n; i++)
		jacob.push_back(jac);
	unsigned int prev = 0;
	for (size_t i = 0; i < jacob.size(); i++) {
		for (unsigned int j = jacob[i]; j > prev; j--)
			if (j <= n)
				order.push_back(j);
		prev = jacob[i];
	}
	for (unsigned int j = n; j > prev; j--)
		order.push_back(j);
}

template <typename SeqContainer>
void PmergeMe::binaryInsert(SeqContainer& arr, unsigned int value, size_t end) {
	size_t left = 0;
	size_t right = end;
	while (left < right) {
		size_t mid = left + (right - left) / 2;
		if (arr[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}
	arr.insert(arr.begin() + left, value);
}

template <typename SeqContainer, typename PairContainer>
void PmergeMe::fordJohnson(SeqContainer& arr) {
	size_t n = arr.size();
	if (n <= 1)
		return;
	PairContainer pairs;
	for (size_t i = 0; i < n / 2; i++) {
		unsigned int a = arr[2 * i];
		unsigned int b = arr[2 * i + 1];
		if (a > b)
			pairs.push_back(std::make_pair(a, b));
		else
			pairs.push_back(std::make_pair(b, a));
	}
	if (pairs.size() > 1) {
		SeqContainer largerOnly;
		for (size_t i = 0; i < pairs.size(); i++)
			largerOnly.push_back(pairs[i].first);
		fordJohnson<SeqContainer, PairContainer>(largerOnly);
		PairContainer sortedPairs;
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
	SeqContainer mainChain;
	if (!pairs.empty())
		mainChain.push_back(pairs[0].second);
	for (size_t i = 0; i < pairs.size(); i++)
		mainChain.push_back(pairs[i].first);
	std::vector<int> insertOrder;
	generateInsertionOrder(pairs.size() - 1, insertOrder);
	for (size_t i = 0; i < insertOrder.size(); i++) {
		int idx = insertOrder[i];
		if (idx > 0 && idx < static_cast<int>(pairs.size())) {
			size_t searchLimit = 0;
			for (size_t j = 0; j < mainChain.size(); j++) {
				if (mainChain[j] == pairs[idx].first) {
					searchLimit = j + 1;
					break;
				}
			}
			binaryInsert(mainChain, pairs[idx].second, searchLimit);
		}
	}
	if (n % 2)
		binaryInsert(mainChain, arr[n - 1], mainChain.size());
	arr = mainChain;
}

#endif
