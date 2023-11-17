#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const int n = 10;
    Animal *animals[n];
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    for (int i = 0; i < n; i++)
    {
        animals[i]->makeSound();
    }

    for (int i = 0; i < n; i++)
    {
        delete animals[i];
    }
    // Dog basic;
    // {
    //     Dog tmp = basic;

    //     std::cout << "---------------------" << std::endl;
    //     std::cout << tmp.getBrain() << std::endl;
    //     std::cout << basic.getBrain() << std::endl;
    // }
    // std::cout << "---------------------" << std::endl;
    // std::cout << basic.getBrain() << std::endl;
    return 0;
}