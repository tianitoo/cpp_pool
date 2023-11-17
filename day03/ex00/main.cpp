#include "ClapTrap.hpp"

int main()
{
    ClapTrap clapTrap("ClapTrap");
    ClapTrap clapTrap2(clapTrap);
    ClapTrap clapTrap3 = clapTrap;
    clapTrap.attack("target");
    clapTrap.takeDamage(10);
    std::cout << "hit points: " << clapTrap.getHitPoints() << std::endl;
    clapTrap.beRepaired(8);
    std::cout << "hit points: " << clapTrap.getHitPoints() << std::endl;
    std::cout << "energy points: " << clapTrap.getEnergyPoints() << std::endl;
    clapTrap.attack("target2");
    clapTrap.beRepaired(-0);
    clapTrap.attack("target3");
    clapTrap.attack("target4");
    clapTrap.attack("target5");
    clapTrap.attack("target6");
    clapTrap.attack("target7");
    clapTrap.attack("target8");
    std::cout << "energy points: " << clapTrap.getEnergyPoints() << std::endl;
    clapTrap.attack("target9");
    std::cout << "energy points: " << clapTrap.getEnergyPoints() << std::endl;
    clapTrap.attack("target10");
    clapTrap.beRepaired(100);
    std::cout << "energy points: " << clapTrap.getEnergyPoints() << std::endl;
    return 0;
}