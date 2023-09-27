#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout << "WrongCat constructor called" << std::endl;
    this->setType("WrongCat");
}

WrongCat::WrongCat(WrongCat const & rhs)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = rhs;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "Meow" << std::endl;
}

WrongCat & WrongCat::operator=(WrongCat const & rhs)
{
    this->setType(rhs.getType());
    return *this;
}

