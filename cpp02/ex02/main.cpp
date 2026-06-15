#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;

	std::cout << "\noperator '!='\n";
	if (a != b)
		std::cout << "a different from b\n\n";
	else
		std::cout << "a = b\n\n";

	std::cout << "\noperator '=='\n";
	if (a == b)
		std::cout << "a = b\n\n";
	else
		std::cout << "a and b are not equal\n\n";

	std::cout << "\noperator '>='\n";
	if (a >= b)
		std::cout << "a >= b\n\n";
	else
		std::cout << "a < b\n\n";

	
	std::cout << a + b << "\n";
	std::cout << a - b << "\n";
	std::cout << b * a << std::endl;
	std::cout << a / b << "\n";	
	std::cout << Fixed::max( a, b ) << std::endl;
}