#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat b("Bureaucrat", 1);
    std::cout << b << std::endl;
    try
    {
        b.incrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << b << std::endl;
    try
    {
        b.decrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << b << std::endl;
    try
    {
        while (1)
        {
            b.decrementGrade();
            std::cout << b << std::endl;
        }
        
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << b << std::endl;
    try
    {
        b.incrementGrade();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << b << std::endl;
    return (0);
}