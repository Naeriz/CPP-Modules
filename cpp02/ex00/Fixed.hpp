#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>

class Fixed {
	private:
		int	_value;
		static const int _Bits = 8;
	public:
		Fixed();
		Fixed(const Fixed& cpyfrom);
		Fixed& operator=(const Fixed& cpyfrom);
		~Fixed();
		int		getRawBits( void ) const;
		void	setRawBits( int const raw);
};

#endif