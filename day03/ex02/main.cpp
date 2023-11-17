#include "FragTrap.hpp"

int main()
{
    FragTrap fragTrap("fragTrap");
    FragTrap fragTrap2(fragTrap);
    FragTrap fragTrap3 = fragTrap;
    fragTrap.attack("target");
    fragTrap.takeDamage(10);
    std::cout << "hit points: " << fragTrap.getHitPoints() << std::endl;
    fragTrap.beRepaired(8);
    std::cout << "hit points: " << fragTrap.getHitPoints() << std::endl;
    std::cout << "energy points: " << fragTrap.getEnergyPoints() << std::endl;
    fragTrap.beRepaired(100);
    std::cout << "hit points: " << fragTrap.getHitPoints() << std::endl;
    fragTrap.beRepaired(-200);
    std::cout << "hit points: " << fragTrap.getHitPoints() << std::endl;
    std::cout << "energy points: " << fragTrap.getEnergyPoints() << std::endl;
    fragTrap.beRepaired(10);
    std::cout << "energy points: " << fragTrap.getEnergyPoints() << std::endl;
    return 0;
}