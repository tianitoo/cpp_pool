#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

    class ScavTrap : public ClapTrap
    {
    private:
        /* data */
    public:
        ScavTrap(std::string name);
        ~ScavTrap();
        void guardGate();
    };

#endif