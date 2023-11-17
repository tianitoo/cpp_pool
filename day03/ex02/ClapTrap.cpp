#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = clapTrap;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& clapTrap)
{
    std::cout << "ClapTrap assignation operator called" << std::endl;
    if (this != &clapTrap)
    {
        this->name = clapTrap.name;
        this->hitPoints = clapTrap.hitPoints;
        this->energyPoints = clapTrap.energyPoints;
        this->attackDamage = clapTrap.attackDamage;
    }
    return *this;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->energyPoints > 0 && this->hitPoints > 0)
    {
        this->energyPoints--;
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
    }
    else if (this->hitPoints == 0)
        std::cout << "ClapTrap " << this->name << " has no energy points left!" << std::endl;
    else
        std::cout << "ClapTrap " << this->name << " is already dead!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hitPoints > 0)
    {
        if (amount > this->hitPoints)
            this->hitPoints = 0;
        else
            this->hitPoints -= amount;
        std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
    }
    else if (this->hitPoints == 0)
        std::cout << "ClapTrap " << this->name << " is already dead!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->hitPoints > 0 && this->energyPoints > 0 && amount < UINT_MAX - this->hitPoints)
    {
        this->hitPoints += amount;
        this->energyPoints--;
        std::cout << "ClapTrap " << this->name << " is repaired for " << amount << " points of health!" << std::endl;
    }
    else if (this->hitPoints == 0)
        std::cout << "ClapTrap " << this->name << " is already dead!" << std::endl;
    else if (this->energyPoints == 0)
        std::cout << "ClapTrap " << this->name << " has no energy points left!" << std::endl;
    else
    {
        this->hitPoints = UINT_MAX;
        std::cout << "ClapTrap " << this->name << " is already at full health!" << std::endl;
    }
}

std::string ClapTrap::getName()
{
    return this->name;
}
void ClapTrap::setName(std::string name)
{
    this->name = name;
}

unsigned int ClapTrap::getHitPoints()
{
    return this->hitPoints;
}

unsigned int ClapTrap::getEnergyPoints()
{
    return this->energyPoints;
}

unsigned int ClapTrap::getAttackDamage()
{
    return this->attackDamage;
}

void ClapTrap::setHitPoints(unsigned int hitPoints)
{
    this->hitPoints = hitPoints;
}

void ClapTrap::setEnergyPoints(unsigned int energyPoints)
{
    this->energyPoints = energyPoints;
}

void ClapTrap::setAttackDamage(unsigned int attackDamage)
{
    this->attackDamage = attackDamage;
}


