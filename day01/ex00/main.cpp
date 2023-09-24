#include "Zombie.hpp"

int main(void)
{
    Zombie* Zombie1;
    Zombie1 = newZombie("Zombie1");
    Zombie1->announce();
    randomChump("Zombie2");
    randomChump("Zombie3");
    randomChump("Zombie4");
    delete Zombie1;
    return (0);
}