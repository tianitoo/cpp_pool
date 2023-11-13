#include "Fixed.hpp"

Fixed::Fixed( void ) : fixedPointValue( 0 ) {
}

Fixed::Fixed( Fixed const & src ) : fixedPointValue( src.getRawBits() ) {
}

Fixed::Fixed( int const n ) : fixedPointValue( n * 256 ) {
}

Fixed::Fixed( float const f ) : fixedPointValue( (int) ( f * 256 + 0.5 ) ) {
}

Fixed::~Fixed( void ) {
}

Fixed & Fixed::operator =( Fixed const & rhs ) {
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
    return this->fixedPointValue  / 256;
}

float Fixed::toFloat( void ) const {
    return (float)this->fixedPointValue / 256;
}

std::ostream & operator<<( std::ostream & o, Fixed const & rhs ) {
    o << rhs.toFloat();
    return o;
}

int operator<( Fixed const & lhs, Fixed const & rhs ) {
    return lhs.getRawBits() < rhs.getRawBits();
}

int operator>( Fixed const & lhs, Fixed const & rhs ) {
    return lhs.getRawBits() > rhs.getRawBits();
}

int operator<=( Fixed const & lhs, Fixed const & rhs ) {
    return lhs.getRawBits() <= rhs.getRawBits();
}

int operator>=( Fixed const & lhs, Fixed const & rhs ) {
    return lhs.getRawBits() >= rhs.getRawBits();
}

int operator==( Fixed const & lhs, Fixed const & rhs ) {
    return lhs.getRawBits() == rhs.getRawBits();
}

int operator!=( Fixed const & lhs, Fixed const & rhs ) {
    return lhs.getRawBits() != rhs.getRawBits();
}

Fixed operator+( Fixed const & lhs, Fixed const & rhs ) {
    return Fixed( lhs.toFloat() + rhs.toFloat() );
}

Fixed operator-( Fixed const & lhs, Fixed const & rhs ) {
    return Fixed( lhs.toFloat() - rhs.toFloat() );
}

Fixed operator*( Fixed const & lhs, Fixed const & rhs ) {
    return Fixed( lhs.toFloat() * rhs.toFloat() );
}

Fixed operator/( Fixed const & lhs, Fixed const & rhs ) {
    return Fixed( lhs.toFloat() / rhs.toFloat() );
}

Fixed & operator++( Fixed & rhs ) {
    rhs.setRawBits( rhs.getRawBits() + 1 );
    return rhs;
}

Fixed operator++( Fixed & rhs, int ) {
    Fixed tmp( rhs );
    rhs.setRawBits( rhs.getRawBits() + 1 );
    return tmp;
}

Fixed & operator--( Fixed & rhs ) {
    rhs.setRawBits( rhs.getRawBits() - 1 );
    return rhs;
}

Fixed operator--( Fixed & rhs, int ) {
    Fixed tmp( rhs );
    rhs.setRawBits( rhs.getRawBits() - 1 );
    return tmp;
}

Fixed & Fixed::min( Fixed & a, Fixed & b ) {
    return a < b ? a : b;
}

Fixed & Fixed::max( Fixed & a, Fixed & b ) {
    return a > b ? a : b;
}

Fixed const & Fixed::min( Fixed const & a, Fixed const & b ) {
    return a < b ? a : b;
}

Fixed const & Fixed::max( Fixed const & a, Fixed const & b ) {
    return a > b ? a : b;
}

