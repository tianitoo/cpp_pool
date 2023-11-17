#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    return ;
}

Ice::Ice(Ice const & src)
{
    *this = src;
    return ;
}

Ice::~Ice()
{
    return ;
}

Ice & Ice::operator=(Ice const & rhs)
{
    this->type = rhs.getType();
    return (*this);
}

AMateria* Ice::clone() const
{
    return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
    return ;
}