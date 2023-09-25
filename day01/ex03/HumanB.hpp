#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include <iostream>
# include "Weapon.hpp"

class HumanB
{
    public:
        HumanB(std::string name);
        ~HumanB(void);

        void attack(void);
        void setWeapon(Weapon &weapon);

    private:
        std::string name;
        Weapon *weapon;
};

#endif
