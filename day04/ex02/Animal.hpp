#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include "Brain.hpp"

    class Animal
    {
    private:
        std::string type;
        Brain *brain;
    public:
        Animal();
        Animal(std::string type);
        virtual ~Animal();
        std::string getType() const;
        void setType(std::string type);
        virtual void makeSound() const = 0;
        Animal & operator=(Animal const & rhs);
    };

#endif