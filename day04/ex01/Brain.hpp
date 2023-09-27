#include <iostream>
#include <string>

class Brain
{
    public:
        Brain();
        Brain(Brain const & src);
        ~Brain();
        Brain & operator=(Brain const & rhs);
        std::string getIdea(int index) const;
        void setIdea(int index, std::string idea);
    private:
        std::string ideas[100];
};