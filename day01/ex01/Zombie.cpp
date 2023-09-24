#include "Zombie.hpp"

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
    std::cout << this->Name << " is dead" << std::endl;
}

Zombie* newZombie(std::string name)
{
    Zombie* newZombie = new Zombie();
    newZombie->setName(name);
    return (newZombie);
}

void    randomChump(std::string name)
{
    Zombie newZombie;
    newZombie.setName(name);
    newZombie.announce();
}

void    Zombie::announce(void)
{
    std::cout << this->Name << ": Braiiiiiiinnnssss..." << std::endl;
}

void    Zombie::setName(std::string name)
{
    this->Name = name;
}