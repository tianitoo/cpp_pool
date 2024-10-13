#include "PmergeMe.hpp"

std::vector<std::vector<int> > PmergeMe::_vv;
std::vector<int> PmergeMe::_sortedVector;
std::deque<std::deque<int> > PmergeMe::_dd;
std::deque<int> PmergeMe::_sortedDeque;
int leftover = -1;
int K = 5;

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
    if (v.size() % 2 != 0)
    {
        leftover = v[v.size() - 1];
        v.pop_back();
    }
    for (int i = 0; i < (int) v.size(); i += 2) {
        if (i + 1 >=  (int) v.size())
            break;
        std::vector<int> tmp;
        if (v[i] < v[i + 1]){
            tmp.push_back(v[i + 1]);
            tmp.push_back(v[i]);
        }
        else {
            tmp.push_back(v[i]);
            tmp.push_back(v[i + 1]);
        }
        _vv.push_back(tmp);
    }

}

void PmergeMe::merge(std::vector<std::vector<int> > &v, int start, int mid, int end)
{
    std::vector<std::vector<int> > tmp;
    int i = start;
    int j = mid + 1;

    while (i <= mid && j <= end)
    {
        if (v[i][0] < v[j][0])
        {
            tmp.push_back(v[i]);
            i++;
        } else {
            tmp.push_back(v[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        tmp.push_back(v[i]);
        i++;
    }

    while (j <= end)
    {
        tmp.push_back(v[j]);
        j++;
    }

    for (int i = start; i <= end; i++)
    {
        v[i] = tmp[i - start];
    }
}

void PmergeMe::insertionSort(std::vector<std::vector<int> > &v, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        for (int j = i; j > start && v[j][0] < v[j - 1][0]; j--)
        {
            std::swap(v[j], v[j - 1]);
        }
    }
}

void PmergeMe::sortVector(std::vector<std::vector<int> > &v, int start, int end)
{
    if (end - start > K)
    {
        int mid = (start + end) / 2;
        sortVector(v, start, mid);
        sortVector(v, mid + 1, end);
        merge(v, start, mid, end);
    } else {
        insertionSort(v, start, end);
    }
}

void PmergeMe::sortDoubleVector()
{
    int start = 0;
    int end = (int) _vv.size() - 1;

    sortVector(_vv, start, end);
}

std::vector<size_t> PmergeMe::genJacob(size_t n){
    std::vector<size_t> jakobsthal;

    jakobsthal.push_back(0);
    if (n > 1)
        jakobsthal.push_back(1);
    for (size_t i = 2; i < n; i++)
        jakobsthal.push_back(jakobsthal[i - 1] + 2 * jakobsthal[i - 2] + 1);
    return jakobsthal;
}

void PmergeMe::jakobSortVector()
{
    size_t last = 0;
    size_t jakobIndex = 0;
    _sortedVector.push_back(_vv[0][1]);
    for (size_t i = 0; i < _vv.size(); i++)
    {
        _sortedVector.push_back(_vv[i][0]);
    }
    std::vector<size_t> jakob = genJacob(_vv.size());
    while (jakob[last] < _vv.size())
    {
        for (size_t i = jakob[jakobIndex]; i > jakob[last] && jakobIndex < jakob.size(); i--)
        {
            if (i >= _vv.size()) {
                continue;
            }
            _sortedVector.insert(std::lower_bound(_sortedVector.begin(), _sortedVector.end(), _vv[i][1]), _vv[i][1]);
        }
        last = jakobIndex;
        jakobIndex++;
    }
    if (leftover != -1){
        _sortedVector.insert(std::lower_bound(_sortedVector.begin(), _sortedVector.end(), leftover), leftover);
        leftover = -1;
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
    if (v.size() == 1) {
        _sortedVector.push_back(v[0]);
    } else {

        doubleVector(v);
        sortDoubleVector();
        jakobSortVector();
    }
    std::clock_t end = std::clock();
    std::cout << "After: ";
    printVector(_sortedVector);
    std::cout << "Time to process a range of " << v.size() << " elements with std::vector : " << (end - start) << " us" << std::endl;
}

// deque functions

void PmergeMe::doubleDeque(std::deque<int> &d)
{
    if (d.size() % 2 != 0)
    {
        leftover = d[d.size() - 1];
        d.pop_back();
    }
    for (int i = 0; i < (int) d.size(); i += 2) {
        if (i + 1 >=  (int) d.size())
            break;
        std::deque<int> tmp;
        if (d[i] < d[i + 1]){
            tmp.push_back(d[i + 1]);
            tmp.push_back(d[i]);
        }
        else {
            tmp.push_back(d[i]);
            tmp.push_back(d[i + 1]);
        }
        _dd.push_back(tmp);
    }

}

void PmergeMe::merge(std::deque<std::deque<int> > &d, int start, int mid, int end)
{
    std::deque<std::deque<int> > tmp;
    int i = start;
    int j = mid + 1;

    while (i <= mid && j <= end)
    {
        if (d[i][0] < d[j][0])
        {
            tmp.push_back(d[i]);
            i++;
        } else {
            tmp.push_back(d[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        tmp.push_back(d[i]);
        i++;
    }

    while (j <= end)
    {
        tmp.push_back(d[j]);
        j++;
    }

    for (int i = start; i <= end; i++)
    {
        d[i] = tmp[i - start];
    }
}

void PmergeMe::insertionSort(std::deque<std::deque<int> > &d, int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        for (int j = i; j > start && d[j][0] < d[j - 1][0]; j--)
        {
            std::swap(d[j], d[j - 1]);
        }
    }
}

void PmergeMe::sortDeque(std::deque<std::deque<int> > &d, int start, int end)
{
    if (end - start > K)
    {
        int mid = (start + end) / 2;
        sortDeque(d, start, mid);
        sortDeque(d, mid + 1, end);
        merge(d, start, mid, end);
    } else {
        insertionSort(d, start, end);
    }
}

void PmergeMe::sortDoubleDeque()
{
    int start = 0;
    int end = (int) _dd.size() - 1;

    sortDeque(_dd, start, end);
}

void PmergeMe::jakobSortDeque()
{
    size_t last = 0;
    size_t jakobIndex = 0;
    _sortedDeque.push_back(_dd[0][1]);
    for (size_t i = 0; i < _dd.size(); i++)
    {
        _sortedDeque.push_back(_dd[i][0]);
    }
    std::vector<size_t> jakob = genJacob(_dd.size());
    while (jakob[last] < _dd.size())
    {
        for (size_t i = jakob[jakobIndex]; i > jakob[last] && jakobIndex < jakob.size(); i--)
        {
            if (i >= _dd.size()) {
                continue;
            }
            _sortedDeque.insert(std::lower_bound(_sortedDeque.begin(), _sortedDeque.end(), _dd[i][1]), _dd[i][1]);
        }
        last = jakobIndex;
        jakobIndex++;
    }
    if (leftover != -1){
        _sortedDeque.insert(std::lower_bound(_sortedDeque.begin(), _sortedDeque.end(), leftover), leftover);
        leftover = -1;
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

void PmergeMe::mergeDeque(std::deque<int> &d)
{
    std::clock_t start = std::clock();
    if (d.size() == 1) {
        _sortedDeque.push_back(d[0]);
    } else {

        doubleDeque(d);
        sortDoubleDeque();
        jakobSortDeque();
    }
    std::clock_t end = std::clock();
    std::cout << "Time to process a range of " << d.size() << " elements with std::deque : " << (end - start) << " us" << std::endl;
}

void PmergeMe::mergeSort(char **av)
{
    std::vector<int> v;
    std::deque<int> d;

    for (int i = 1; av[i]; i++)
    {
        try
        {
            std::string str = av[i];
            if (str.find_first_not_of("0123456789") != std::string::npos)
                throw InvalidToken();
            int number = std::stoi(av[i]);
            if (number < 0)
                throw InvalidToken();
            v.push_back(number);
            d.push_back(number);
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
