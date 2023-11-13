#include "Fixed.hpp"

int main( void ) {
Fixed a(10);
Fixed const b( Fixed( 4 ) * Fixed( 2 ) );
std::cout << a + b << std::endl;
std::cout << a - b << std::endl;
std::cout << a * b << std::endl;
std::cout << a / b << std::endl;
std::cout << (a < b) << std::endl;
std::cout << (a > b) << std::endl;
std::cout << (a <= b) << std::endl;
std::cout << (a >= b) << std::endl;
std::cout << (a == b) << std::endl;
std::cout << (a != b) << std::endl;
std::cout << a << std::endl;
std::cout << ++a << std::endl;
std::cout << a.toInt() << std::endl;
std::cout << --a << std::endl;
std::cout << a << std::endl;
std::cout << a++ << std::endl;
std::cout << a++ << std::endl;
std::cout << a-- << std::endl;
std::cout << a << std::endl;
std::cout << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
std::cout << Fixed::min( a, b ) << std::endl;

return 0;
}