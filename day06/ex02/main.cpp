#include "A.hpp"
#include "C.hpp"
#include "B.hpp"
#include "Base.hpp"

int main()
{
    Base ptr;
    Base *a = ptr.generate();
    Base *b = ptr.generate();

    ptr.identify(a);
    ptr.identify(*b);

    delete a;
    delete b;
    return (EXIT_SUCCESS);
}