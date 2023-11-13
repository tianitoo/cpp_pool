#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    a.setRawBits( 42 );
    Fixed b( a );
    Fixed c;
    a.setRawBits( 21 );
    c = b;
    b.setRawBits( 84 );
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    return 0;
}   