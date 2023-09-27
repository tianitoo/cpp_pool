#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

    class ClapTrap
    {
    private:
        std::string name;
        int hitPoints;
        int energyPoints;
        int attackDamage;

    public:
        ClapTrap(std::string name);
        ~ClapTrap();
        void attack(std::string const & target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        int getHitPoints();
        int getEnergyPoints();
        int getAttackDamage();
        void setEnergyPoints(int energyPoints);
        void setAttackDamage(int attackDamage);
    };
    
    
    

#endif