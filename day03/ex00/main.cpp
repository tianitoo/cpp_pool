#include "ClapTrap.hpp"

int main()
{
    ClapTrap clapTrap("ClapTrap");
    clapTrap.attack("target");
    clapTrap.takeDamage(10);
    std::cout << clapTrap.getHitPoints() << std::endl;
    clapTrap.beRepaired(8);
    std::cout << clapTrap.getHitPoints() << std::endl;
    
    return 0;
}