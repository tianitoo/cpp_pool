#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

    class Cat : public Animal
    {
    private:
        /* data */
    public:
        Cat();
        Cat(Cat const & src);
        ~Cat();
        Cat & operator=(Cat const & rhs);
        void makeSound() const;
    };

#endif