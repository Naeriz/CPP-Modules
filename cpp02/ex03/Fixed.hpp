#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>
#include <cmath> //roundf

class Fixed {
	private:
		int	_value;
		static const int _Bits = 8;
	public:
		Fixed();
		Fixed(const int i);
		Fixed(const float f);
		Fixed(const Fixed& cpyfrom);
		Fixed& operator=(const Fixed& cpyfrom);
		~Fixed();
		int		getRawBits( void ) const;
		void	setRawBits( int const raw);
		float	toFloat( void ) const;
		int		toInt( void ) const;
		bool	operator>(const	Fixed& two) const;
		bool	operator<(const	Fixed& two) const;
		bool	operator>=(const	Fixed& two);
		bool	operator<=(const	Fixed& two);
		bool	operator==(const Fixed& dif);
		bool	operator!=(const Fixed& dif);
		Fixed	operator+(const Fixed& victim);
		Fixed	operator-(const Fixed& victim);
		Fixed	operator*(const Fixed& victim);
		Fixed	operator/(const Fixed& victim);
		Fixed&	operator++();
		Fixed	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);
		static	Fixed& min(Fixed& one, Fixed& two);
		static	const Fixed& min(const Fixed& one, const Fixed& two);
		static	Fixed& max(Fixed& one, Fixed& two);
		static	const Fixed& max(const Fixed& one, const Fixed& two);
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj); //overload

#endif