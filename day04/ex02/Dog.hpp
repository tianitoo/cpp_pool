#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

    class Dog : public Animal
    {
    private:
        /* data */
    public:
        Dog();
        Dog(Dog const & src);
        ~Dog();
        Dog & operator=(Dog const & rhs);
        void makeSound() const;
    };

#endif