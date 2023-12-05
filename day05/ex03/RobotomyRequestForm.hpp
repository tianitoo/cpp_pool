#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <fstream>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string const &target);
        RobotomyRequestForm(RobotomyRequestForm const &src);
        virtual ~RobotomyRequestForm();
        RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);

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

std::ostream &operator<<(std::ostream &o, RobotomyRequestForm const &rhs);
std::ostream &operator<<(std::ostream &o, RobotomyRequestForm const *rhs);

#endif