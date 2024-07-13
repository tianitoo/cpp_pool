#include "A.hpp"
#include "C.hpp"
#include "B.hpp"
#include "Base.hpp"

Base *generate(void)
{
    int random = std::rand() % 3;

    if (random == 0)
        return (new A());
    else if (random == 1)
        return (new B());
    return (new C());
}

void identify(Base *p)
{
    try
    {
        A *a = dynamic_cast<A *>(p);
        if (a)
            std::cout << "A" << std::endl;
    }
    catch (std::exception &e)
    {
    }
    try
    {
        B *b = dynamic_cast<B *>(p);
        if (b)
            std::cout << "B" << std::endl;
    }
    catch (std::exception &e)
    {
    }
    try
    {
        C *c = dynamic_cast<C *>(p);
        if (c)
            std::cout << "C" << std::endl;
    }
    catch (std::exception &e)
    {
    }
}

void identify(Base &p)
{
    try
    {
        A &a = dynamic_cast<A &>(p);
        (void)a;
        std::cout << "A" << std::endl;
    }
    catch (std::exception &e)
    {
    }
    try
    {
        B &b = dynamic_cast<B &>(p);
        (void)b;
        std::cout << "B" << std::endl;
    }
    catch (std::exception &e)
    {
    }
    try
    {
        C &c = dynamic_cast<C &>(p);
        (void)c;
        std::cout << "C" << std::endl;
    }
    catch (std::exception &e)
    {
    }
}

int main()
{
    std::srand(std::time(NULL));
    Base *a = generate();
    Base *b = generate();
    Base *c = generate();
    Base *d = generate();

    identify(a);
    identify(*b);
    identify(c);
    identify(*d);

    delete a;
    delete b;
    delete c;
    return (EXIT_SUCCESS);
}