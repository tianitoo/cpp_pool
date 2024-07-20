#pragma once

#include <iostream>
#include <stdexcept>

template<typename T>
class Array
{
    private:
        T *_array;
        size_t _size;

    public:
        Array(void);
        Array(unsigned int n);
        Array(Array const &src);
        ~Array(void);

        Array<T> &operator=(Array<T> const &rhs);
    
        T &operator[](size_t i);

        size_t size(void) const;

        class OutOfLimitsException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

};

template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array(Array const &src) : _array(NULL), _size(0) {
    *this = src;
}

template <typename T>
Array<T>::~Array() {
    if (_array)
        delete[] _array;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &rhs) {
    if (this == &rhs)
        return *this;
    if (_array)
        delete[] _array;
    _size = rhs._size;
    _array = new T[_size];
    for (size_t i = 0; i < _size; i++)
        _array[i] = rhs._array[i];
    return *this;
}

template <typename T>
T &Array<T>::operator[](size_t i) {
    if (i >= _size)
        throw OutOfLimitsException();
    else if (i < 0)
        throw OutOfLimitsException();
    return _array[i];
}

template <typename T>
const char *Array<T>::OutOfLimitsException::what() const throw() {
    return "Out of limits";
}

template <typename T>
size_t Array<T>::size() const {
    return _size;
}

