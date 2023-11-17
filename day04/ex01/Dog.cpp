#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog constructor called" << std::endl;
    this->type = "Dog";
    brain = new Brain();
}

Dog::Dog(Dog & rhs)
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->brain = new Brain();
    *this->brain = *rhs.brain;
    *this = rhs;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete brain;
}

void Dog::makeSound() const
{
    std::cout << "Woof" << std::endl;
}

Dog & Dog::operator=(Dog & rhs)
{
    std::cout << "Dog assignment operator called" << std::endl;
    this->type = rhs.type;
    this->brain = new Brain();
    *this->brain = *rhs.brain;
    return *this;
}

Brain & Dog::getBrain() const
{
    return *brain;
}

void Dog::setBrain(Brain & src)
{
    *brain = src;
}