#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <string>
# include <ctime>

class Base
{
    public:
        Base *generate(void);
        void identify(Base* p);
        void identify(Base& p);

        virtual ~Base();
};

#endif