#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const &other)
{
    *this = other;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(Intern const &other)
{
    (void)other;
    return (*this);
}

    // create form of type formName without using if/else or switch
AForm *Intern::makeForm(std::string const &formName, std::string const &target) const
{
    AForm *form = NULL;
    std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm *(Intern::*formFunctions[3])(std::string const &target) const = {&Intern::makeShrubberyCreationForm, &Intern::makeRobotomyRequestForm, &Intern::makePresidentialPardonForm};

    for (int i = 0; i < 3; i++)
    {
        if (formName == formNames[i])
        {
            form = (this->*formFunctions[i])(target);
            std::cout << "Intern creates " << *form << std::endl;
            return (form);
        }
    }
    throw Intern::FormNotFoundException();
    return (NULL);
}

AForm *Intern::makeShrubberyCreationForm(std::string const &target) const
{
    return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeRobotomyRequestForm(std::string const &target) const
{
    return (new RobotomyRequestForm(target));
}

AForm *Intern::makePresidentialPardonForm(std::string const &target) const
{
    return (new PresidentialPardonForm(target));
}

const char *Intern::FormNotFoundException::what() const throw()
{
    return ("Form not found");
}