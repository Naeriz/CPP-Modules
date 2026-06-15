#pragma once
#include "Fixed.hpp"

class Point {
	private:
		const Fixed x;
		const Fixed y;
	public:
		Point();
		Point(const float one, const float two);
		Point(const Point& cpyfrom);
		Point& operator=(const Point& cpyfrom);
		~Point();
		Fixed get_x() const;
		Fixed get_y() const;
};

bool bsp(const Point a, const Point b, const Point c, const Point point);