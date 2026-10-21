#pragma once

#include <climits>
#include <stdexcept>
#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <deque>
#include <ctime>
#include <iomanip>


class PmergeMe 
{
	private:
		std::vector<size_t>	jacobOrder(size_t n);
		void				insertIntoSorted(std::vector<int> &vec, int insert_val, size_t high);

		std::deque<size_t>	jacobOrderDeq(size_t n);
		void				insertIntoSortedDeq(std::deque<int> &deq, int insert_val, size_t high);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &cpyfrom);
		PmergeMe& operator=(const PmergeMe &cpyfrom);
		~PmergeMe();

		std::vector<int>	rec_sort_vec(const std::vector<int> &input);
		std::deque<int>		rec_sort_deq(const std::deque<int> &input);
} ;