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
        FragTrap();
        FragTrap(std::string name);
        FragTrap( FragTrap& fragTrap);
        ~FragTrap();

        FragTrap& operator=(FragTrap& fragTrap);

        void highFivesGuys(void);
    };

#endif
