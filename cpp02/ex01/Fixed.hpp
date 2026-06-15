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
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj); //overload

#endif