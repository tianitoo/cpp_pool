#include "iter.hpp"


template<typename T>
void iter(T *array, size_t length, void (*f)(T const &))
{
    for (size_t i = 0; i < length; i++)
        f(array[i]);
}

template<typename T>
void print(T const &x)
{
    std::cout << x << " ";
}

int main(void)
{
    int int_array[] = {1, 2, 3, 4, 5};
    std::string string_array[] = {"Hello", "World", "!"};

    std::cout << "int_array: ";
    iter(int_array, 5, print);
    std::cout << std::endl;

    std::cout << "string_array: ";
    iter(string_array, 3, print);
    std::cout << std::endl;

    return 0;
}