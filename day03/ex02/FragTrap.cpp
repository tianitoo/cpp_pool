#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "FragTrap default constructor called" << std::endl;
    this->setHitPoints(100);
    this->setEnergyPoints(100);
    this->setAttackDamage(30);
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
    std::cout << "FragTrap constructor called" << std::endl;
    this->setHitPoints(100);
    this->setEnergyPoints(100);
    this->setAttackDamage(30);
}

FragTrap::FragTrap(FragTrap& fragTrap)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
    *this = fragTrap;
}

FragTrap& FragTrap::operator=(FragTrap& fragTrap)
{
    std::cout << "FragTrap assignation operator called" << std::endl;
    if (this != &fragTrap)
    {
        this->setName(fragTrap.getName());
        this->setHitPoints(fragTrap.getHitPoints());
        this->setEnergyPoints(fragTrap.getEnergyPoints());
        this->setAttackDamage(fragTrap.getAttackDamage());
    }
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "Frag Trap " << this->getName() << " has requested a high five" << std::endl;
}