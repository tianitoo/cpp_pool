#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat constructor called" << std::endl;
    this->type = "Cat";
    brain = new Brain();
}

Cat::Cat(Cat const & rhs)
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->brain = new Brain();
    *this->brain = *rhs.brain;
    *this = rhs;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete brain;
}

void Cat::makeSound() const
{
    std::cout << "Meow" << std::endl;
}

Cat & Cat::operator=(Cat const & rhs)
{
    std::cout << "Cat assignment operator called" << std::endl;
    this->type = rhs.type;
    this->brain = new Brain();
    *this->brain = *rhs.brain;
    return *this;
}

Brain & Cat::getBrain() const
{
    return *brain;
}

void Cat::setBrain(Brain & src)
{
    *brain = src;
}
