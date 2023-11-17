#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(Brain &src)
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = src;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = src.ideas[i];
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}

Brain & Brain::operator=(Brain & rhs)
{
    std::cout << "Brain assignment operator called" << std::endl;
    if (this != &rhs)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = rhs.ideas[i];
    }
        return *this;
}
