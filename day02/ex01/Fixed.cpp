#include "Fixed.hpp"

Fixed::Fixed( void ) : fixedPointValue( 0 ) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( Fixed const & src ) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::Fixed( int const n ) {
    std::cout << "Int constructor called" << std::endl;
    this->fixedPointValue = n << this->fractionalBits;
}

Fixed::Fixed( float const f ) {
    std::cout << "Float constructor called" << std::endl;
    this->fixedPointValue = roundf( f * ( 1 << this->fractionalBits ) );
}


Fixed::~Fixed( void ) {
    std::cout << "Destructor called" << std::endl;
}

Fixed & Fixed::operator =( Fixed const & rhs ) {
    std::cout << "Copy assignment operator called" << std::endl;
    this->fixedPointValue = rhs.getRawBits();
    return *this;
}

int Fixed::getRawBits( void ) const {
    return this->fixedPointValue;
}

void Fixed::setRawBits( int const raw ) {
    this->fixedPointValue = raw;
}

int Fixed::toInt( void ) const {
    return this->fixedPointValue >> this->fractionalBits;
}

float Fixed::toFloat( void ) const {
    return (float)this->fixedPointValue / ( 1 << this->fractionalBits );
}

std::ostream & operator<<( std::ostream & o, Fixed const & rhs ) {
    o << rhs.toFloat();
    return o;
}