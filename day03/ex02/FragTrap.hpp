#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

    class FragTrap : public ClapTrap
    {
    private:
        /* data */
    public:
        FragTrap(std::string name);
        ~FragTrap();
        void highFivesGuys(void);
    };

#endif