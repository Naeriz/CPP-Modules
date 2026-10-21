#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &)
{
	return *this;
}

PmergeMe::~PmergeMe() {}


/*get enough of jacobsthal order based on number of losers*/
std::vector<size_t> PmergeMe::jacobOrder(size_t n)
{
	std::vector<size_t> order;

	if (n == 0)
		return order;

	order.push_back(1);
	size_t last = 1;
	size_t jac = 3;
	size_t before = 1; //those 3 are setup for first round that ends 3

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
		size_t next = jac + 2 * before; //jacob math to get every number in j order
		before = jac;
		jac = next;
	}
	return order;
}

/*binary search + insert*/
void	PmergeMe::insertIntoSorted(std::vector<int> &vec, int insert_val, size_t high)
{
	size_t low = 0;

	while(low < high)
	{
		size_t middle = low + (high - low) / 2; //rounds down always. remember div before +

		if (insert_val < vec[middle]) //if before mid, else after mid insert
			high = middle;
		else
			low = middle + 1; //if middle too small skip over it to start new lowest above it not on it
	}
	vec.insert(vec.begin() + low, insert_val);

					//print
	// for (size_t i = 0; i < vec.size(); i++)
	// 		std::cout << " " << vec[i];
}

std::vector<int>	PmergeMe::rec_sort_vec(const std::vector<int> &input)
{

	if (input.size() <= 1)
		return input;

	//those 2 r for pairing they never change after
	std::vector<int> big;
	std::vector<int> smol; 

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

					//print
	// for (size_t i = 0; i < big.size(); i++)
	// 		std::cout << " " << big[i];
	// std::cout << std::endl;
	// for (size_t i = 0; i < smol.size(); i++)
	// 		std::cout << " " << smol[i];

	std::vector<int> win = rec_sort_vec(big);

	std::vector<size_t> order = jacobOrder(smol.size()); //order = jacob seq for n amount of losers

	for (size_t j = 0; j < order.size(); j++)
	{
		size_t real_index = order[j] - 1; //jacob start at 1, so we skip [0] and one too much at end. -1 moves it back correctly

		size_t stop;
		if (real_index < big.size()) //same index as pair unless odd, remember leftover last
		{
			stop = 0;
			while (win[stop] != big[real_index]) //inflates diff gap
				stop++;
		}
		else
			stop = win.size();

		insertIntoSorted(win, smol[real_index], stop);
	}
	return win;
}