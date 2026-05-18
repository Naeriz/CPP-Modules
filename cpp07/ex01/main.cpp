#include "Iter.hpp"

int main()
{
    const int arr[] = {1, 2, 3, 4, 5, 6, 7};
    iter(arr, 7, print);

	std::cout << std::endl;
    std::string strs[] = {"a", "b", "c", "d", "e"};
    iter(strs, 5, print);

    return 0;
}