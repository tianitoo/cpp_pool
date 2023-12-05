#ifndef BUROCRAT_HPP
# define BUROCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat
{
    private:
        std::string const	name;
        int					grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string const &name, int grade);
        Bureaucrat(Bureaucrat const &rhs);
        ~Bureaucrat();

        Bureaucrat &operator=(Bureaucrat const &rhs);

        std::string const	&getName() const;
        int					getGrade() const;

        void				incrementGrade();
        void				decrementGrade();

        class GradeTooHighException: public std::exception
        {
            public:
                virtual const char	*what() const throw();
        };

        class GradeTooLowException: public std::exception
        {
            public:
                virtual const char	*what() const throw();
        };
};

    std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs);
    std::ostream &operator<<(std::ostream &o, Bureaucrat const *rhs);
#endif
