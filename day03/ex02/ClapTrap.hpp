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
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& clapTrap);
        ~ClapTrap();
        ClapTrap& operator=(const ClapTrap& clapTrap);

        void attack(std::string const & target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        std::string getName();
        void setName(std::string name);
        int getHitPoints();
        int getEnergyPoints();
        int getAttackDamage();
        void setHitPoints(int hitPoints);
        void setEnergyPoints(int energyPoints);
        void setAttackDamage(int attackDamage);
    };
    
    
    

#endif