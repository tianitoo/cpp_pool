#pragma once

#include <iostream>
#include <vector>

class Span
{
    private:
        unsigned int _n;
        unsigned int _size;
        std::vector<int> _arr;
        Span();
    public:
        Span(unsigned int n);
        Span(Span const &other);
        Span &operator=(Span const &other);
        ~Span();
        void addNumber(int n);
        void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        int shortestSpan();
        int longestSpan();
        class NotEnoughSpaceException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        class FullSpanException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        class NoSpanException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        class AlreadyStoredException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        std::vector<int> getArr() const;
};
