#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# ifndef BRAIN_HPP
#  define BRAIN_HPP
#  include "Brain.hpp"
# endif

    class Dog : public Animal
    {
    private:
        Brain *brain;
    public:
        Dog();
        Dog(Dog & src);
        ~Dog();

        Dog & operator=(Dog & rhs);

        void makeSound() const;

        Brain & getBrain() const;
        void setBrain(Brain & src);
    };

#endif