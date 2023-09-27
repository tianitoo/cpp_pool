#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(std::string const & target)
{
    this->energyPoints -= 1;
    std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    this->hitPoints -= amount;
    std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    this->hitPoints += amount;
    std::cout << "ClapTrap " << this->name << " is repaired for " << amount << " points of damage!" << std::endl;
}

std::string ClapTrap::getName()
{
    return this->name;
}

int ClapTrap::getHitPoints()
{
    return this->hitPoints;
}

int ClapTrap::getEnergyPoints()
{
    return this->energyPoints;
}

int ClapTrap::getAttackDamage()
{
    return this->attackDamage;
}

void ClapTrap::setHitPoints(int hitPoints)
{
    this->hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(int energyPoints)
{
    this->energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(int attackDamage)
{
    this->attackDamage = attackDamage;
}

