/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:36:39 by gdosch            #+#    #+#             */
/*   Updated: 2025/12/16 14:16:48 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <limits>
#include <vector>

static size_t jacobsthal(size_t n) {
	size_t prev2 = 0;
	size_t prev1 = 1;
	size_t curr = n;
	for (size_t i = 2; i <= n; i++) {
		if (prev1 > std::numeric_limits<size_t>::max() - 2 * prev2)
			return std::numeric_limits<size_t>::max();
		curr = prev1 + 2 * prev2;
		prev2 = prev1;
		prev1 = curr;
	}
	return curr;
}

// PLUS EFFICACE
// static size_t jacobsthal(size_t n) {
// 	if (n >= 64)
// 		return std::numeric_limits<size_t>::max();
// 	unsigned long long power = 1ULL << n;
// 	unsigned long long ret = (n % 2) ? (power + 1) / 3 : (power - 1) / 3;
// 	return ret > std::numeric_limits<size_t>::max() 
// 		? std::numeric_limits<size_t>::max() 
// 		: static_cast<size_t>(ret);
// }

static void generateInsertionOrder(size_t n, std::vector<size_t>& order) {
	order.clear();
	if (!n)
		return;
	std::vector<size_t> jacob;
	for (size_t i = 2, jac; (jac = jacobsthal(i)) <= n; i++)
		jacob.push_back(jac);
	size_t prev = 0;
	for (size_t i = 0; i < jacob.size(); prev = jacob[i++])
		for (size_t j = jacob[i]; j > prev; j--)
			if (j <= n)
				order.push_back(j);
	for (size_t j = n; j > prev; j--)
		order.push_back(j);
}

// Ford-Johnson for std::deque
void PmergeMe::createPairs(UIntDeque& seq, UIntPairDeque& pairs) const {
	for (size_t i = 0; i < seq.size() / 2; i++) {
		unsigned int a = seq[2 * i];
		unsigned int b = seq[2 * i + 1];
		pairs.push_back((a > b) ? std::make_pair(a, b) : std::make_pair(b, a));
	}
}

void PmergeMe::sortPairs(UIntPairDeque& pairs) const {
	if (pairs.size() <= 1)
		return;
	UIntDeque largerOnly;
	for (size_t i = 0; i < pairs.size(); i++)
		largerOnly.push_back(pairs[i].first);
	fordJohnson(largerOnly);
	UIntPairDeque sortedPairs;
	for (size_t i = 0; i < largerOnly.size(); i++)
		for (size_t j = 0; j < pairs.size(); j++)
			if (pairs[j].first == largerOnly[i]) {
				sortedPairs.push_back(pairs[j]);
				break;
			}
	pairs.swap(sortedPairs);
}

void PmergeMe::buildMainChain(const UIntPairDeque& pairs, UIntDeque& mainChain) const {
	mainChain.push_back(pairs[0].second);
	for (size_t i = 0; i < pairs.size(); i++)
		mainChain.push_back(pairs[i].first);
}

void PmergeMe::insertPending(const UIntPairDeque& pairs, UIntDeque& mainChain) const {
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

void PmergeMe::insertStraggler(const UIntDeque& seq, UIntDeque& mainChain) const {
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

void PmergeMe::fordJohnson(UIntDeque& seq) const {
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
void PmergeMe::createPairs(UIntList& seq, UIntPairList& pairs) const {
	UIntList::iterator it = seq.begin();
	for (size_t i = 0; i < seq.size() / 2; i++) {
		unsigned int a = *it++;
		unsigned int b = *it++;
		pairs.push_back((a > b) ? std::make_pair(a, b) : std::make_pair(b, a));
	}
}

void PmergeMe::sortPairs(UIntPairList& pairs) const {
	if (pairs.size() <= 1)
		return;
	UIntList largerOnly;
	for (UIntPairList::iterator pit = pairs.begin(); pit != pairs.end(); ++pit)
		largerOnly.push_back(pit->first);
	fordJohnson(largerOnly);
	UIntPairList sortedPairs;
	for (UIntList::iterator lit = largerOnly.begin(); lit != largerOnly.end(); ++lit)
		for (UIntPairList::iterator pit = pairs.begin(); pit != pairs.end(); ++pit)
			if (pit->first == *lit) {
				sortedPairs.push_back(*pit);
				break;
			}
	pairs.swap(sortedPairs);
}

void PmergeMe::buildMainChain(const UIntPairList& pairs, UIntList& mainChain) const {
	mainChain.push_back(pairs.begin()->second);
	for (UIntPairList::const_iterator pit = pairs.begin(); pit != pairs.end(); ++pit)
		mainChain.push_back(pit->first);
}

void PmergeMe::insertPending(const UIntPairList& pairs, UIntList& mainChain) const {
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

void PmergeMe::insertStraggler(const UIntList& seq, UIntList& mainChain) const {
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

void PmergeMe::fordJohnson(UIntList& seq) const {
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
PmergeMe::PmergeMe(void) : _deque(), _list() {}

// Parameterized constructor for deque
PmergeMe::PmergeMe(const UIntDeque& deque) : _deque(deque), _list() {
	fordJohnson(_deque);
}

// Parameterized constructor for list
PmergeMe::PmergeMe(const UIntList& list) : _deque(), _list(list) {
	fordJohnson(_list);
}

// Copy constructor
PmergeMe::PmergeMe(const PmergeMe& other) : _deque(other._deque), _list(other._list) {}

// Copy assignment operator
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		_deque = other._deque;
		_list = other._list;
	}
	return *this;
}

// Destructor
PmergeMe::~PmergeMe(void) {}

// Accessors
const UIntDeque& PmergeMe::getDeque(void) const {
	return _deque;
}

const UIntList& PmergeMe::getList(void) const {
	return _list;
}
