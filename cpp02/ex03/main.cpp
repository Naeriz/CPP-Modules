#include "Point.hpp"

// Can use geogebra to display the test
int    main(void)
{
    const Point    a(1, 2);
    const Point    b(4, 6);
    const Point    c(4, 3);
    const Point    point(2, 2.4);

    if (bsp(a, b, c, point) == true)
        std::cout << "The point is inside the triangle." << std::endl;
    else
        std::cout << "The point is outside the triangle." << std::endl;
    return (0);
}