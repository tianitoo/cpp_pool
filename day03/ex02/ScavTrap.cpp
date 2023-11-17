#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "ScavTrap default constructor called" << std::endl;
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name)
{
    std::cout << "ScavTrap constructor called" << std::endl;
    this->setHitPoints(100);
    this->setEnergyPoints(50);
    this->setAttackDamage(20);
}

ScavTrap::ScavTrap(ScavTrap& scavTrap)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
    *this = scavTrap;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap& scavTrap)
{
    std::cout << "ScavTrap assignation operator called" << std::endl;
    if (this != &scavTrap)
    {
        this->setName(scavTrap.getName());
        this->setHitPoints(scavTrap.getHitPoints());
        this->setEnergyPoints(scavTrap.getEnergyPoints());
        this->setAttackDamage(scavTrap.getAttackDamage());
    }
    return *this;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->getEnergyPoints() > 0)
    {
        this->setEnergyPoints(this->getEnergyPoints() - 1);
        std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
    }
    else
        std::cout << "ScavTrap " << this->getName() << " has no energy points left!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->getName() << " has entered in Gate keeper mode" << std::endl;
}