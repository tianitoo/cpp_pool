#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>


#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(const PmergeMe &copy);
        ~PmergeMe();
        PmergeMe &operator=(const PmergeMe &copy);


        class InvalidToken : public std::exception
        {
        public:
            virtual const char *what() const throw()
            {
                return "Error: invalid token";
            }
        };

        class BadSyntax : public std::exception
        {
        public:
            virtual const char *what() const throw()
            {
                return "Error: bad syntax";
            }
        };

        static std::vector<size_t> genJacob(size_t n);
        // vector functions
        static void sortVector(std::vector<std::vector<int> > &v, int start, int end);
        static void merge(std::vector<std::vector<int> > &v, int start, int mid, int end);
        static void insertionSort(std::vector<std::vector<int> > &v, int start, int end);
        static void mergeVector(std::vector<int> &v);
        static void doubleVector(std::vector<int> &v);
        static void sortDoubleVector();
        static void jakobSortVector();
        static void printVector(std::vector<int> &v);
    
        // deque functions
        static void sortDeque(std::deque<std::deque<int> > &d, int start, int end);
        static void merge(std::deque<std::deque<int> > &d, int start, int mid, int end);
        static void insertionSort(std::deque<std::deque<int> > &d, int start, int end);
        static void mergeDeque(std::deque<int> &d);
        static void doubleDeque(std::deque<int> &d);
        static void sortDoubleDeque();
        static void jakobSortDeque();
        static void printDeque(std::deque<int> &d);

        static void mergeSort(char **av);

    private:
        // vector parameters
        static std::vector<std::vector<int> > _vv;
        static std::vector<int> _sortedVector;

        // deque parameters
        static std::deque<std::deque<int> > _dd;
        static std::deque<int> _sortedDeque;




};