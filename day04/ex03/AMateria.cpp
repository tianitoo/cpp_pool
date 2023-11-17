#include "AMateria.hpp"

AMateria::AMateria() : type("default")
{
    return ;
}

AMateria::AMateria(std::string const & type) : type(type)
{
    return ;
}

AMateria::AMateria(AMateria const & src)
{
    *this = src;
    return ;
}

AMateria::~AMateria()
{
    return ;
}

AMateria & AMateria::operator=(AMateria const & rhs)
{
    this->type = rhs.getType();
    return (*this);
}

void AMateria::use(ICharacter& target)
{
    (void)target;
    return ;
}

std::string const & AMateria::getType() const
{
    return (this->type);
}