#include "FragTrap.hpp"

int main()
{
    FragTrap fragTrap("fragTrap");
    fragTrap.attack("target");
    fragTrap.takeDamage(10);
    fragTrap.beRepaired(10);
    fragTrap.highFivesGuys();
    return 0;
}