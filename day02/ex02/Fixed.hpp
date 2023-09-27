#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

    class Fixed {
        public:
            Fixed( void );
            Fixed( Fixed const & src );
            Fixed( int const n );
            Fixed( float const f );
            ~Fixed( void );

            static Fixed & min( Fixed & a, Fixed & b );
            static Fixed & max( Fixed & a, Fixed & b );
            static Fixed const & min( Fixed const & a, Fixed const & b );
            static Fixed const & max( Fixed const & a, Fixed const & b );

            Fixed & operator =( Fixed const & rhs );

            int getRawBits( void ) const;
            void setRawBits( int const raw );

            int toInt( void ) const;
            float toFloat( void ) const;


        private:
            int fixedPointValue;
            static const int fractionalBits = 8;
    };
    std::ostream & operator<<( std::ostream & o , Fixed const & rhs );
    int operator<( Fixed const & lhs, Fixed const & rhs );
    int operator>( Fixed const & lhs, Fixed const & rhs );
    int operator<=( Fixed const & lhs, Fixed const & rhs );
    int operator>=( Fixed const & lhs, Fixed const & rhs );
    int operator==( Fixed const & lhs, Fixed const & rhs );
    int operator!=( Fixed const & lhs, Fixed const & rhs );
    Fixed operator+( Fixed const & lhs, Fixed const & rhs );
    Fixed operator-( Fixed const & lhs, Fixed const & rhs );
    Fixed operator*( Fixed const & lhs, Fixed const & rhs );
    Fixed operator/( Fixed const & lhs, Fixed const & rhs );
    Fixed & operator++( Fixed & rhs );
    Fixed operator++( Fixed & rhs, int );
    Fixed & operator--( Fixed & rhs );
    Fixed operator--( Fixed & rhs, int );

    Fixed & min( Fixed & a, Fixed & b );
    Fixed & max( Fixed & a, Fixed & b );
    Fixed const & min( Fixed const & a, Fixed const & b );
    Fixed const & max( Fixed const & a, Fixed const & b );

#endif