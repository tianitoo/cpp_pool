#include "Span.hpp"

int main()
{
    srand(time(NULL));
    std::vector<int> v;
    for (int i = 0; i < 10000; i++)
        v.push_back(rand());
    Span sp(10000);
    try {
        sp.addNumbers(v.begin(), v.end());
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try {
        sp.addNumber(42);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    
    try {
        std::cout << sp.shortestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try {
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}