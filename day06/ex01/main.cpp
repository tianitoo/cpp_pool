#include "Serializer.hpp"

int main(void)
{
    Data		*data;
    uintptr_t	*raw;

    data = new Data();
    data->s1 = "Hello";
    data->n = rand();
    data->s2 = "World";
    raw = Serializer::serialize(data);
    std::cout << "s1: " << data->s1 << std::endl;
    std::cout << "n: " << data->n << std::endl;
    std::cout << "s2: " << data->s2 << std::endl;
    std::cout << "raw: " << raw << std::endl;
    data = Serializer::deserialize(raw);
    std::cout << "s1: " << data->s1 << std::endl;
    std::cout << "n: " << data->n << std::endl;
    std::cout << "s2: " << data->s2 << std::endl;
    std::cout << "raw: " << raw << std::endl;
    delete data;
    return (0);
}