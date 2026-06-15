#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const float one, const float two) : x(one), y(two) {}

Point::Point(const Point& cpyfrom) : x(cpyfrom.x), y(cpyfrom.y){} //can mod const cuz its a constructor

Point	&Point::operator=(const Point& cpyfrom)
{
	(void) cpyfrom;
	return (*this);
}

Point::~Point() {}

Fixed Point::get_x() const
{
	return (x);
}

Fixed Point::get_y() const
{
	return (y);
}