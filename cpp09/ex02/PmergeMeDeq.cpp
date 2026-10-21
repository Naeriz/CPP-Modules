#include "PmergeMe.hpp"

std::deque<size_t> PmergeMe::jacobOrderDeq(size_t n)
{
	std::deque<size_t> order;

	if (n == 0)
		return order;

	order.push_back(1);
	size_t last = 1;
	size_t jac = 3;
	size_t before = 1;

	while (last < n)
	{
		size_t top;
		if (jac < n)
			top = jac;
		else
			top = n;

		for (size_t i = top; i > last; i--)
			order.push_back(i);

		last = jac;
		size_t next = jac + 2 * before;
		before = jac;
		jac = next;
	}
	return order;
}

void	PmergeMe::insertIntoSortedDeq(std::deque<int> &deq, int insert_val, size_t high)
{
	size_t low = 0;

	while(low < high)
	{
		size_t middle = low + (high - low) / 2;

		if (insert_val < deq[middle])
			high = middle;
		else
			low = middle + 1;
	}
	deq.insert(deq.begin() + low, insert_val);
}

std::deque<int>	PmergeMe::rec_sort_deq(const std::deque<int> &input)
{

	if (input.size() <= 1)
		return input;

	std::deque<int> big;
	std::deque<int> smol; 
	/////////////////////////pairing loop
	for (size_t i = 0; i + 1 < input.size(); i += 2)
	{
		if (input[i] > input[i + 1])
		{
			big.push_back(input[i]);
			smol.push_back(input[i + 1]);
		}
		else // if == in smol
		{
			big.push_back(input[i + 1]);
			smol.push_back(input[i]);
		}
	}
	if (input.size() % 2 != 0)
		smol.push_back(input[input.size() - 1]);

	std::deque<int> win = rec_sort_deq(big);

	std::deque<size_t> order = jacobOrderDeq(smol.size());

	for (size_t j = 0; j < order.size(); j++)
	{
		size_t real_index = order[j] - 1;

		size_t stop;
		if (real_index < big.size())
		{
			stop = 0;
			while (win[stop] != big[real_index])
				stop++;
		}
		else
			stop = win.size();

		insertIntoSortedDeq(win, smol[real_index], stop);
	}
	return win;
}