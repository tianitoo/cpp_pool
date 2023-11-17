#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>
# include <string>

class Brain
{
    public:
        Brain();
        Brain(Brain & src);
        ~Brain();
        
        Brain & operator=(Brain & rhs);

    private:
        std::string ideas[100];
};

#endif