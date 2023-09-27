#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

    class Animal
    {
    private:
        std::string type;
    public:
        Animal();
        Animal(std::string type);
        virtual ~Animal();
        std::string getType() const;
        void setType(std::string type);
        virtual void makeSound() const;
        Animal & operator=(Animal const & rhs);
    };

#endif