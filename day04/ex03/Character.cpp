#include "Character.hpp"

Character::Character() : name("default")
{
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
    return ;
}

Character::Character(std::string const & name) : name(name)
{
    for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
    return ;
}

Character::Character(Character const & src)
{
    *this = src;
    return ;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i] != NULL)
            delete this->inventory[i];
    }
    return ;
}

Character & Character::operator=(Character const & rhs)
{
    this->name = rhs.getName();
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i] != NULL)
            delete this->inventory[i];
        this->inventory[i] = rhs.inventory[i]->clone();
    }
    return (*this);
}

std::string const & Character::getName() const
{
    return (this->name);
}

void Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i] == NULL)
        {
            this->inventory[i] = m;
            break ;
        }
    }
    return ;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx > 3)
        return ;
    this->inventory[idx] = NULL;
    return ;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx > 3 || this->inventory[idx] == NULL)
        return ;
    this->inventory[idx]->use(target);
    return ;
}
