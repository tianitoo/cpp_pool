#include "Fixed.hpp"

Fixed::Fixed( void ) : fixedPointValue( 0 ) {
}

Fixed::Fixed( Fixed const & src ) {
    *this = src;
}

Fixed::Fixed( int const n ) {
    this->fixedPointValue = n << this->fractionalBits;
}

Fixed::Fixed( float const f ) {
    this->fixedPointValue = roundf( f * ( 1 << this->fractionalBits ) );
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
    return this->fixedPointValue >> this->fractionalBits;
}

float Fixed::toFloat( void ) const {
    return (float)this->fixedPointValue / ( 1 << this->fractionalBits );
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

