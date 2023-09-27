#include "ClapTrap.hpp"

int main()
{
    ClapTrap clapTrap("ClapTrap");
    clapTrap.attack("target");
    clapTrap.takeDamage(10);
    clapTrap.beRepaired(10);
    return 0;
}