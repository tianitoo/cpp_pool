#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    // const Animal* meta = new Animal();
    // const Animal* cat = new Cat();
    // const Animal* dog = new Dog();
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    // const WrongCat* wrongCat2 = new WrongCat();

    // std::cout << "meta->getType(): " << meta->getType() << " meta->makeSound(): ";
    // meta->makeSound();
    // std::cout << "cat->getType(): " << cat->getType() << " cat->makeSound(): ";
    // cat->makeSound();
    // std::cout << "dog->getType(): " << dog->getType() << " dog->makeSound(): ";
    // dog->makeSound();
    // std::cout << "wrongMeta->getType(): " << wrongMeta->getType() << " wrongMeta->makeSound(): ";
    // wrongMeta->makeSound();
    // std::cout << "wrongCat->getType(): " << wrongCat->getType() << " wrongCat->makeSound(): ";
    // wrongCat->makeSound();
    // std::cout << "wrongDog->getType(): " << wrongDog->getType() << " wrongDog->makeSound(): ";
    // wrongDog->makeSound();
    // std::cout << "wrongCat2->getType(): " << wrongCat2->getType() << " wrongCat2->makeSound(): ";
    // wrongCat2->makeSound();
    // delete meta;
    // delete cat;
    // delete dog;
    delete wrongMeta;
    delete wrongCat;
    return 0;
}