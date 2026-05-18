#include "Array.hpp"

int main() {
    try {
        Array<int> arr(5);

        for (unsigned int i = 0; i < arr.getSize(); i++) {
            arr[i] = i * 10;
        }

        std::cout << "Array values: ";
        for (unsigned int i = 0; i < arr.getSize(); i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;

        Array<int> copyArr(arr);
        std::cout << "Copy values: ";
        for (unsigned int i = 0; i < copyArr.getSize(); i++) {
            std::cout << copyArr[i] << " ";
        }
        std::cout << std::endl;

        Array<int> assignedArr;
        assignedArr = arr;

        std::cout << "Assign op values: ";
        for (unsigned int i = 0; i < assignedArr.getSize(); i++) {
            std::cout << assignedArr[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "Trying out of range..." << std::endl;
        std::cout << arr[1000] << std::endl;

    } catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}

// int main(void)
// {
//     try
//     {
//         Array<int> a(5);
// 		unsigned int i = 0;

// 		while (i < a.getSize())
// 		{
//         	a[i] = i * 10;
// 			i++;
// 		}
// 		i = 0;
// 		while (i < a.getSize())
// 		{
//             std::cout << a[i] << " ";
// 			i++;
// 		}
// 		std::cout << std::endl;
// 		std::cout << a[2] << std::endl;
// 		std::cout << a[0] << std::endl;
// 		std::cout << a[5] << std::endl;
//     }
//     catch (std::exception &e)
//     {
//         std::cerr << "Exception: " << e.what() << std::endl;
//     }

//     return 0;
// }