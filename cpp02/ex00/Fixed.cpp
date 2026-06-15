#include "Fixed.hpp"

Fixed::Fixed() : _value(0) //static only declared once outside of funcs
{
	std::cout << "Default constructor called\n";
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
	//_value the thief, cpyfrom victim, 
	// cp hid value in locker, use getrawbits to get
	return (*this); //what we got as a param can be defined as this
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called\n";
	return (_value);
}

void	Fixed::setRawBits( int const raw)
{
	std::cout << "setRawBits member function called\n";
	_value = raw;
}