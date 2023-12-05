#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Form
{
	private:
		std::string			name;
		bool				isSigned;
		int const			gradeToSign;
		int const			gradeToExecute;
	public:
		Form();
		Form(std::string const &name, int gradeToSign, int gradeToExecute);
		Form(Form const &rhs);
		~Form();

		Form &operator=(Form const &rhs);

		std::string			getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;

		void				beSigned(Bureaucrat const &bureaucrat);

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

	std::ostream &operator<<(std::ostream &o, Form const &rhs);
	std::ostream &operator<<(std::ostream &o, Form const *rhs);
#endif