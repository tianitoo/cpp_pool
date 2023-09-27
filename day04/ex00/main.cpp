#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const Animal* k = new Cat(*static_cast<Cat const *>(i));
    const Animal* l = new Dog(*static_cast<Dog const *>(j));
    const Animal* m = new Animal(*static_cast<Animal const *>(meta));
    std::cout << std::endl;
    std::cout << "meta->getType(): " << meta->getType() << std::endl;
    std::cout << "j->getType(): " << j->getType() << std::endl;
    std::cout << "i->getType(): " << i->getType() << std::endl;
    std::cout << "k->getType(): " << k->getType() << std::endl;
    std::cout << "l->getType(): " << l->getType() << std::endl;
    std::cout << "m->getType(): " << m->getType() << std::endl;
    std::cout << std::endl;
    std::cout << "meta->makeSound(): ";
    meta->makeSound();
    std::cout << "j->makeSound(): ";
    j->makeSound();
    std::cout << "i->makeSound(): ";
    i->makeSound();
    std::cout << "k->makeSound(): ";
    k->makeSound();
    std::cout << "l->makeSound(): ";
    l->makeSound();
    std::cout << "m->makeSound(): ";
    m->makeSound();
    std::cout << std::endl;
    delete meta;
    delete j;
    delete i;
    delete k;
    delete l;
    delete m;

    std::cout << std::endl << std::endl << std::endl;

    const WrongAnimal* meta2 = new WrongAnimal();
    const WrongAnimal* j2 = new WrongCat();

    std::cout << std::endl;

    std::cout << "meta2->getType(): " << meta2->getType() << std::endl;
    std::cout << "j2->getType(): " << j2->getType() << std::endl;

    std::cout << std::endl;

    std::cout << "meta2->makeSound(): ";
    meta2->makeSound();
    std::cout << "j2->makeSound(): ";
    j2->makeSound();

    std::cout << std::endl;
    delete meta2;
    delete j2;

    return 0;
}