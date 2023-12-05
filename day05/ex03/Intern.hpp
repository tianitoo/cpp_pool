#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
public:
    Intern();
    Intern(Intern const &other);
    ~Intern();
    Intern &operator=(Intern const &other);

    AForm *makeForm(std::string const &formName, std::string const &target) const;

    class FormNotFoundException : public std::exception
    {
    public:
        virtual const char *what() const throw() ;
    };

private:
    AForm *makeShrubberyCreationForm(std::string const &target) const;
    AForm *makeRobotomyRequestForm(std::string const &target) const;
    AForm *makePresidentialPardonForm(std::string const &target) const;
};

#endif