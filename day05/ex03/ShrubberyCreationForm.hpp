#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string const &target);
        ShrubberyCreationForm(ShrubberyCreationForm const &src);
        virtual ~ShrubberyCreationForm();
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);

        virtual void execute(Bureaucrat const &executor) const;

        std::string getTarget() const;
        void setTarget(std::string const &target);

        class FormNotSignedException: public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class FileNotOpenedException: public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

    private:
        std::string target;
};

std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm const &rhs);
std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm const *rhs);

#endif
