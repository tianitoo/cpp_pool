#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template<typename T>
class Array
{
    private:
        T *_array;
        size_t _length;

    public:
        Array(void);
        Array(unsigned int n);
        Array(Array const &src);
        ~Array(void);

        Array &operator=(Array const &rhs);

        T &operator[](size_t i);

        size_t size(void) const;
};

#endif