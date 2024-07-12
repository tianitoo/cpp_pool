#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <ctime>
# include "Data.hpp"

class Serializer
{
    private:
        Serializer();
        Serializer(const Serializer &other);
        ~Serializer();
    
    public:
        static uintptr_t		*serialize(Data *data);
        static Data				*deserialize(uintptr_t *raw);
};

#endif