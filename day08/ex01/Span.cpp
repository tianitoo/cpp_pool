#include "Span.hpp"

Span::Span() : _n(0), _size(0), _arr(std::vector<int>())
{
}

Span::Span(unsigned int n) : _n(n), _size(0), _arr(std::vector<int>())
{
}

Span::Span(Span const &other) : _n(other._n), _size(other._size), _arr(other._arr)
{
}

Span &Span::operator=(Span const &other)
{
    _n = other._n;
    _size = other._size;
    _arr = other._arr;
    return *this;
}

Span::~Span()
{
}

void Span::addNumber(int n)
{
    if (_size >= _n)
        throw Span::FullSpanException();
    std::vector<int>::iterator it = std::find(_arr.begin(), _arr.end(), n);
    if (it != _arr.end())
        throw Span::AlreadyStoredException();
    std::vector<int>::iterator it2 = std::lower_bound(_arr.begin(), _arr.end(), n);
    _size++;
    _arr.insert(it2, n);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    if (_size + std::distance(begin, end) > _n)
        throw Span::NotEnoughSpaceException();
    for (std::vector<int>::iterator it = begin; it != end; it++)
    {
        std::vector<int>::iterator it2 = std::find(_arr.begin(), _arr.end(), *it);
        if (it2 != _arr.end())
            throw Span::AlreadyStoredException();
        std::vector<int>::iterator it3 = std::lower_bound(_arr.begin(), _arr.end(), *it);
        _arr.insert(it3, *it);
    }
    _size += std::distance(begin, end);
}

int Span::shortestSpan()
{
    if (_size <= 1)
        throw Span::NoSpanException();
    int min = INT_MAX;
    for (unsigned int i = 1; i < _size; i++)
    {
        if (_arr[i] - _arr[i - 1] < min)
            min = _arr[i] - _arr[i - 1];
    }
    return min;
}

int Span::longestSpan()
{
    if (_size <= 1)
        throw Span::NoSpanException();
    return _arr[_size - 1] - _arr[0];
}

const char *Span::NotEnoughSpaceException::what() const throw()
{
    return "Not enough space";
}

const char *Span::FullSpanException::what() const throw()
{
    return "Span is full";
}

const char *Span::NoSpanException::what() const throw()
{
    return "No span to find";
}

const char *Span::AlreadyStoredException::what() const throw()
{
    return "Number already stored";
}

std::vector<int> Span::getArr() const
{
    return _arr;
}