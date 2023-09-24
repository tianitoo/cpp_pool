#include "Zombie.hpp"

int main(void)
{
    int N = 9;

    Zombie* ZombieHorde = zombieHorde(N, "Zombie");
    for (int i = 0; i < N; i++)
    {
        ZombieHorde[i].announce();
    }
    delete [] ZombieHorde;
    return (0);
}