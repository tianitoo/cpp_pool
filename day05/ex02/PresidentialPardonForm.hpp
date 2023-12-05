#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <fstream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string const &target);
        PresidentialPardonForm(PresidentialPardonForm const &src);
        virtual ~PresidentialPardonForm();
        PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);

        virtual void execute(Bureaucrat const &executor) const;

        std::string getTarget() const;
        void setTarget(std::string const &target);

        class FormNotSignedException: public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

    private:
        std::string target;
};

#endif