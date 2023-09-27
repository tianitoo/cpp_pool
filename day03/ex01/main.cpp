#include "ScavTrap.hpp"

int main()
{
    ScavTrap skavTrap("SkavTrap");
    skavTrap.attack("target");
    skavTrap.takeDamage(10);
    skavTrap.beRepaired(10);
    skavTrap.guardGate();
    return 0;
}