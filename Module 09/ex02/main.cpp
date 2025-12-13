/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdosch <gdosch@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:36:47 by gdosch            #+#    #+#             */
/*   Updated: 2025/12/13 22:56:32 by gdosch           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>

double getTime(void) {
	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
	return ts.tv_sec * 1000000.0 + ts.tv_nsec / 1000.0;
}

void flushCache(void) {
	const size_t cacheSize = 20 * 1024 * 1024;
	char* dummy = new char[cacheSize];
	for (size_t i = 0; i < cacheSize; i++)
		dummy[i] = i & 0xFF;
	delete[] dummy;
}

int main(int argc, char** argv) {
	try {
		PmergeMe pmerge;
		pmerge.parseInput(argc, argv);
		pmerge.displayBefore();
		const int RUNS = 10;
		double totalTimeVec = 0;
		double totalTimeDeq = 0;
		for (int i = 0; i < RUNS; i++) {
			flushCache();
			PmergeMe testDeq = pmerge;
			double startDeq = getTime();
			testDeq.sortDeque();
			double endDeq = getTime();
			totalTimeDeq += (endDeq - startDeq);
		}
		for (int i = 0; i < RUNS; i++) {
			flushCache();
			PmergeMe testVec = pmerge;
			double startVec = getTime();
			testVec.sortVector();
			double endVec = getTime();
			totalTimeVec += (endVec - startVec);
		}
		double avgTimeVec = totalTimeVec / RUNS;
		double avgTimeDeq = totalTimeDeq / RUNS;
		pmerge.sortVector();
		pmerge.sortDeque();
		pmerge.displayAfter();
		pmerge.verifySort();
		std::cout << std::fixed << std::setprecision(5);
		std::cout << "Time to process a range of " << pmerge.size()
				  << " elements with std::vector : " << avgTimeVec << " us" << std::endl;
		std::cout << "Time to process a range of " << pmerge.size()
				  << " elements with std::deque  : " << avgTimeDeq << " us" << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
}
