#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal constructor called" << std::endl;
    this->brain = new Brain();
}

Animal::Animal(std::string type) : type(type)
{
    std::cout << "Animal constructor called" << std::endl;
    this->brain = new Brain();
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
    delete this->brain;
}

std::string Animal::getType() const
{
    return this->type;
}

void Animal::setType(std::string type)
{
    this->type = type;
}

Animal & Animal::operator=(Animal const & rhs)
{
    this->type = rhs.getType();
    return *this;
}
