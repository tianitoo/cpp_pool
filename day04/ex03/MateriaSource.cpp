#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        materia[i] = NULL;
    return ;
}

MateriaSource::MateriaSource(MateriaSource const & src)
{
    *this = src;
    return ;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (materia[i] != NULL)
            delete materia[i];
    }
    return ;
}

MateriaSource & MateriaSource::operator=(MateriaSource const & rhs)
{
    for (int i = 0; i < 4; i++)
    {
        if (materia[i] != NULL)
            delete materia[i];
        materia[i] = rhs.materia[i]->clone();
    }
    return (*this);
}

void MateriaSource::learnMateria(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (materia[i] == NULL)
        {
            materia[i] = m;
            break ;
        }
    }
    return ;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (materia[i] != NULL && materia[i]->getType() == type)
            return (materia[i]->clone());
    }
    return (NULL);
}
