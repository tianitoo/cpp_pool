#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# ifndef BRAIN_HPP
#  define BRAIN_HPP
#  include "Brain.hpp"
# endif

    class Cat : public Animal
    {
    private:
        Brain *brain;
    public:
        Cat();
        Cat(Cat const & src);
        ~Cat();

        Cat & operator=(Cat const & rhs);

        void makeSound() const;

        Brain & getBrain() const;
        void setBrain(Brain & src);
    };

#endif