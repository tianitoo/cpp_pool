#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main()
{
    // // test Bureaucrat can't sign form with grade too low
    // try
    // {
    //     Bureaucrat bureaucrat("bureaucrat", 150);
    //     ShrubberyCreationForm form("form");

    //     std::cout << bureaucrat << std::endl;
    //     std::cout << form << std::endl;

    //     form.beSigned(bureaucrat);
    //     std::cout << form << std::endl;
    //     bureaucrat.executeForm(form.getName());
    // }
    // catch (std::exception &e)
    // {
    //     std::cout << e.what() << std::endl;
    // }
    // try
    // {
    //     Bureaucrat bureaucrat("bureaucrat", 150);
    //     RobotomyRequestForm form("form");

    //     std::cout << bureaucrat << std::endl;
    //     std::cout << form << std::endl;

    //     form.beSigned(bureaucrat);
    //     std::cout << form << std::endl;
    //     bureaucrat.executeForm(form.getName());
    // }
    // catch (std::exception &e)
    // {
    //     std::cout << e.what() << std::endl;
    // }
    // try
    // {
    //     Bureaucrat bureaucrat("bureaucrat", 150);
    //     PresidentialPardonForm form("form");

    //     std::cout << bureaucrat << std::endl;
    //     std::cout << form << std::endl;

    //     form.beSigned(bureaucrat);
    //     std::cout << form << std::endl;
    //     bureaucrat.executeForm(form.getName());
    // }
    // catch (std::exception &e)
    // {
    //     std::cout << e.what() << std::endl;
    // }
    // // test Bureaucrat can sign form with grade high enough
    // try
    // {
    //     Bureaucrat bureaucrat("bureaucrat", 140);
    //     ShrubberyCreationForm form("form");

    //     std::cout << bureaucrat << std::endl;
    //     std::cout << form << std::endl;

    //     form.beSigned(bureaucrat);
    //     std::cout << form << std::endl;
    //     bureaucrat.executeForm(form.getName());
    // }
    // catch (std::exception &e)
    // {
    //     std::cout << e.what() << std::endl;
    // }
    // try
    // {
    //     Bureaucrat bureaucrat("bureaucrat", 50);
    //     RobotomyRequestForm form("form");

    //     std::cout << bureaucrat << std::endl;
    //     std::cout << form << std::endl;

    //     form.beSigned(bureaucrat);
    //     std::cout << form << std::endl;
    //     bureaucrat.executeForm(form.getName());
    // }
    // catch (std::exception &e)
    // {
    //     std::cout << e.what() << std::endl;
    // }
    // try
    // {
    //     Bureaucrat bureaucrat("bureaucrat", 15);
    //     PresidentialPardonForm form("form");

    //     std::cout << bureaucrat << std::endl;
    //     std::cout << form << std::endl;

    //     form.beSigned(bureaucrat);
    //     std::cout << form << std::endl;
    //     bureaucrat.executeForm(form.getName());
    // }
    // catch (std::exception &e)
    // {
    //     std::cout << e.what() << std::endl;
    // }
    // test Form can't be signed twice
    try
    {
        Bureaucrat bureaucrat("bureaucrat", 130);
        ShrubberyCreationForm form("house");

        std::cout << bureaucrat << std::endl;
        std::cout << form << std::endl;

        // form.beSigned(bureaucrat);
        // form.beSigned(bureaucrat);
        // std::cout << form << std::endl;
        bureaucrat.executeForm(form);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}