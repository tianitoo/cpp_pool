#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Usage: ./RPN \"[RPN expression]\"" << std::endl;
        return 1;
    }
    try{
        if (av[1][0] == '\0')
            throw RPN::BadSyntax();
        RPN::fillStack(av[1]);
        // RPN::printStack();
        // RPN::calculate();
        // std::cout << "res " << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}