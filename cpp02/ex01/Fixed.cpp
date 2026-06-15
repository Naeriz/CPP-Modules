#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int i) : _value(0)
{
	_value = (i << _Bits);
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float f)
{
	_value = roundf(f * 256); //rounds decimal
	std::cout << "Float constructor called\n";
}

Fixed::Fixed(const Fixed& cpyfrom)
{
	std::cout << "Copy constructor called\n";
	_value = cpyfrom.getRawBits();
}

Fixed	&Fixed::operator=(const Fixed& cpyfrom)
{
	std::cout << "Copy assignment operator called\n";
	_value = cpyfrom.getRawBits(); 
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int	Fixed::getRawBits( void ) const
{
	return (_value);
}

void	Fixed::setRawBits( int const raw)
{
	std::cout << "setRawBits member function called\n";
	_value = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return (os);
}

float	Fixed::toFloat( void ) const
{
	return ((float)_value / 256); //256 same as 1 << Bits
}

int		Fixed::toInt( void ) const
{
	return(_value >> _Bits);
}