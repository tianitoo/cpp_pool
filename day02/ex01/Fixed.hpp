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

            Fixed & operator=( Fixed const & rhs );
            Fixed & operator<<( int const n );

            int getRawBits( void ) const;
            void setRawBits( int const raw );

            int toInt( void ) const;
            float toFloat( void ) const;

        private:
            int fixedPointValue;
            static const int fractionalBits = 8;
    };
    std::ostream & operator<<( std::ostream & o , Fixed const & rhs );

#endif