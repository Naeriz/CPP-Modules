#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const int i) : _value(0)
{
	_value = (i << _Bits);
}

Fixed::Fixed(const float f)
{
	_value = roundf(f * 256); //rounds decimal
}

Fixed::Fixed(const Fixed& cpyfrom)
{
	_value = cpyfrom.getRawBits();
}

Fixed	&Fixed::operator=(const Fixed& cpyfrom)
{
	_value = cpyfrom.getRawBits(); 
	return (*this);
}

Fixed::~Fixed() {}

int	Fixed::getRawBits( void ) const
{
	return (_value);
}

void	Fixed::setRawBits( int const raw)
{
	_value = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return (os);
}

float	Fixed::toFloat( void ) const
{
	return ((float)_value / 256);
}

int		Fixed::toInt( void ) const
{
	return(_value >> _Bits);
}

bool	Fixed::operator>(const	Fixed& two) const//cuz one is the one calling this so automatically included
{
	if (_value > two._value)
		return (true);
	else
		return (false);
}

bool	Fixed::operator<(const	Fixed& two) const
{
	return (_value < two._value);
}

bool	Fixed::operator>=(const	Fixed& two)
{
	if (_value >= two._value)
		return (true);
	else
		return (false);
}

bool	Fixed::operator<=(const	Fixed& two)
{
	return (_value <= two._value);
}

bool	Fixed::operator==(const Fixed& dif)
{
	if (_value == dif._value)
		return (true);
	else
		return (false);
}

bool	Fixed::operator!=(const Fixed& dif)
{
	return (_value != dif._value);
}

Fixed	Fixed::operator+(const Fixed& victim)
{
	return (Fixed(toFloat() + victim.toFloat()));
}

Fixed	Fixed::operator-(const Fixed& victim)
{
	return (Fixed(toFloat() - victim.toFloat()));
}

Fixed	Fixed::operator*(const Fixed& victim)
{
	return (Fixed(toFloat() * victim.toFloat()));
}

Fixed	Fixed::operator/(const Fixed& victim)
{
	return (Fixed(toFloat() / victim.toFloat()));
}

Fixed&	Fixed::operator++()
{
	_value++;
	return(*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed temp(*this);

	_value++;
	return (temp);
}

Fixed&	Fixed::operator--()
{
	_value--;
	return(*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed temp(*this);

	_value--;
	return (temp);
}

Fixed& Fixed::min(Fixed& one, Fixed& two)
{
	if (one > two)
		return (two);
	else
		return (one);
}

const Fixed& Fixed::min(const Fixed& one, const Fixed& two)
{
	if (one > two)
		return (two);
	else
		return (one);
}

Fixed& Fixed::max(Fixed& one, Fixed& two)
{
	if (one < two)
		return (two);
	else
		return (one);
}

const Fixed& Fixed::max(const Fixed& one, const Fixed& two)
{
	if (one < two)
		return (two);
	else
		return (one);
}