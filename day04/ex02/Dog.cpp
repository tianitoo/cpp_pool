#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog constructor called" << std::endl;
    this->setType("Dog");
}

Dog::Dog(Dog const & rhs)
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = rhs;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Woof" << std::endl;
}

Dog & Dog::operator=(Dog const & rhs)
{
    this->setType(rhs.getType());
    return *this;
}
