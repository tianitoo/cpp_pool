#include "Harl.hpp"

Harl::Harl()
{
    return;
}

Harl::~Harl()
{
    return;
}

void    Harl::complain(std::string level)
{
    void (Harl::*f)(void) = NULL;
    std::string levels[4] = {"debug", "info", "warning", "error"};
    void (Harl::*functions[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
        {
            f = functions[i];
            break;
        }
    }
    (this->*f)();
}

void    Harl::debug(void)
{
    std::cout << "DEBUG" << std::endl;
}

void    Harl::info(void)
{
    std::cout << "INFO" << std::endl;
}

void    Harl::warning(void)
{
    std::cout << "WARNING" << std::endl;
}

void    Harl::error(void)
{
    std::cout << "ERROR" << std::endl;
}