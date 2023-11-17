#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    return ;
}

Cure::Cure(Cure const & src)
{
    *this = src;
    return ;
}

Cure::~Cure()
{
    return ;
}

Cure & Cure::operator=(Cure const & rhs)
{
    this->type = rhs.getType();
    return (*this);
}

AMateria* Cure::clone() const
{
    return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
    return ;
}