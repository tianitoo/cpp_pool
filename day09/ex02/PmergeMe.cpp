// #pragma once

// #include <iostream>
// #include <vector>
// #include <deque>


// class PmergeMe
// {
//     public:
//         PmergeMe();
//         PmergeMe(const PmergeMe &copy);
//         ~PmergeMe();
//         PmergeMe &operator=(const PmergeMe &copy);

//         static void mergeSort(std::vector<int> &v);
//         static void printVector(std::vector<int> &v);

//         class InvalidToken : public std::exception
//         {
//         public:
//             virtual const char *what() const throw()
//             {
//                 return "Error: invalid token";
//             }
//         };

//         class BadSyntax : public std::exception
//         {
//         public:
//             virtual const char *what() const throw()
//             {
//                 return "Error: bad syntax";
//             }
//         };

//     private:
//         static void merge(std::vector<int> &v, std::vector<int> &left, std::vector<int> &right);
//         static void mergeSort(std::vector<int> &v, int l, int r);
//         static void printVector(std::vector<int> &v, int l, int r);

//         static std::deque<int> _operators;

// };

#include "PmergeMe.hpp"

std::vector<std::vector<int>> PmergeMe::_vv;
std::vector<int> PmergeMe::_sortedVector;

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
    *this = copy;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
    (void)copy;
    return *this;
}


// vector functions

void PmergeMe::doubleVector(std::vector<int> &v)
{
    for (int i = 0; i < (int) v.size(); i += 2) {
        if (i + 1 >=  (int) v.size())
            break;
        if (v[i] > v[i + 1])
            _vv.push_back({v[i + 1], v[i]});
        else
            _vv.push_back({v[i], v[i + 1]});
    }

}

void PmergeMe::sortDoubleVector()
{
    for (int i = 0; i < (int) _vv.size(); i++)
    {
        for (int j = i + 1; j < (int) _vv.size(); j++)
        {
            if (_vv[i][0] > _vv[j][0])
            {
                std::swap(_vv[i], _vv[j]);
                // std::swap(_vv[i], _vv[j]);
            }
        }
    }
}

void PmergeMe::insertSort()
{
    for (int i = 0; i < (int) _vv.size(); i++)
    {
        _sortedVector.push_back(_vv[i][0]);
    }

    for (int i = 0; i < (int) _vv.size(); i++)
    {
        for (int j = 0; j < (int) _sortedVector.size(); j++)
        {
            if (_vv[i][1] < _sortedVector[j])
            {
                _sortedVector.insert(_sortedVector.begin() + j, _vv[i][1]);
                break;
            } else if (j + 1 == (int) _sortedVector.size())
            {
                _sortedVector.push_back(_vv[i][1]);
                break;
            }
        }
    }
}

void PmergeMe::printVector(std::vector<int> &v)
{
    for (int i = 0; i < (int) v.size(); i++)
    {
        std::cout << v[i];
        if (i + 1 < (int) v.size())
            std::cout << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::mergeVector(std::vector<int> &v)
{
    std::cout << "Before: ";
    printVector(v);
    std::clock_t start = std::clock();
    doubleVector(v);
    sortDoubleVector();
    insertSort();
    std::clock_t end = std::clock();
    std::cout << "After: ";
    printVector(_sortedVector);
    std::cout << "Time to process a range of " << v.size() << " elements with std::vector : " << (end - start) << " us" << std::endl;
}

// deque functions

std::deque<std::deque<int>> PmergeMe::_dd;
std::deque<int> PmergeMe::_sortedDeque;

void PmergeMe::mergeDeque(std::deque<int> &d)
{
    std::clock_t start = std::clock();
    doubleDeque(d);
    sortDoubleDeque();
    insertSortDeque();
    std::clock_t end = std::clock();
    std::cout << "Time to process a range of " << d.size() << " elements with std::deque : " << (end - start) << " us" << std::endl;
}

void PmergeMe::doubleDeque(std::deque<int> &d)
{
    for (int i = 0; i < (int) d.size(); i += 2) {
        if (i + 1 >=  (int) d.size())
            break;
        if (d[i] > d[i + 1])
            _dd.push_back({d[i + 1], d[i]});
        else
            _dd.push_back({d[i], d[i + 1]});
    }
}

void PmergeMe::sortDoubleDeque()
{
    for (int i = 0; i < (int) _dd.size(); i++)
    {
        for (int j = i + 1; j < (int) _dd.size(); j++)
        {
            if (_dd[i][0] > _dd[j][0])
            {
                std::swap(_dd[i], _dd[j]);
                // std::swap(_dd[i], _dd[j]);
            }
        }
    }
}

void PmergeMe::insertSortDeque()
{
    for (int i = 0; i < (int) _dd.size(); i++)
    {
        for (int j = 0; j < (int) _dd[i].size(); j++)
        {
            _sortedDeque.push_back(_dd[i][j]);
        }
    }
}

void PmergeMe::printDeque(std::deque<int> &d)
{
    for (int i = 0; i < (int) d.size(); i++)
    {
        std::cout << d[i];
        if (i + 1 < (int) d.size())
            std::cout << " ";
    }
    std::cout << std::endl;
}


void PmergeMe::mergeSort(char **av)
{
    std::vector<int> v;
    std::deque<int> d;

    for (int i = 1; av[i]; i++)
    {
        try
        {
            v.push_back(std::stoi(av[i]));
            d.push_back(std::stoi(av[i]));
        }
        catch(const std::exception &e)
        {
            throw InvalidToken();
        }
    }

    mergeVector(v);
    mergeDeque(d);
}


int main(int ac, char **av)
{
    if (ac == 1)
    {
        std::cout << "Usage: ./PmergeMe [int1 int2 int3 ...]" << std::endl;
        return 1;
    }

    try
    {
        PmergeMe::mergeSort(av);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}
