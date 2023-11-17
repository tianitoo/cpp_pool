#include "ScavTrap.hpp"

int main()
{
    ScavTrap scavTrap("scavTrap");
    ScavTrap scavTrap2(scavTrap);
    ScavTrap scavTrap3 = scavTrap;
    scavTrap.attack("target");
    scavTrap.takeDamage(10);
    std::cout << "hit points: " << scavTrap.getHitPoints() << std::endl;
    scavTrap.beRepaired(8);
    std::cout << "hit points: " << scavTrap.getHitPoints() << std::endl;
    std::cout << "energy points: " << scavTrap.getEnergyPoints() << std::endl;
    scavTrap.attack("target2");
    scavTrap.beRepaired(-5);
    scavTrap.attack("target3");
    scavTrap.attack("target4");
    scavTrap.attack("target5");
    scavTrap.attack("target6");
    scavTrap.attack("target7");
    scavTrap.attack("target8");
    std::cout << "energy points: " << scavTrap.getEnergyPoints() << std::endl;
    scavTrap.attack("target9");
    std::cout << "energy points: " << scavTrap.getEnergyPoints() << std::endl;
    scavTrap.attack("target10");
    scavTrap.beRepaired(100);
    std::cout << "energy points: " << scavTrap.getEnergyPoints() << std::endl;
    return 0;
}