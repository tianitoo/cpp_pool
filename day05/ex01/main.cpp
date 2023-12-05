#include "Form.hpp"

int main()
{
    try
    {
        Bureaucrat bureaucrat("bureaucrat", 150);
        Form form("form", 150, 150);

        std::cout << bureaucrat << std::endl;
        std::cout << form << std::endl;

        form.beSigned(bureaucrat);
        std::cout << form << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        Bureaucrat bureaucrat("bureaucrat", 150);
        Form form("form", 50, 50);

        std::cout << bureaucrat << std::endl;
        std::cout << form << std::endl;

        form.beSigned(bureaucrat);
        std::cout << form << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}