#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

    class WrongAnimal
    {
    private:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(std::string type);
        ~WrongAnimal();
        std::string getType() const;
        void setType(std::string type);
        void makeSound() const;
        WrongAnimal & operator=(WrongAnimal const & rhs);
    };

#endif