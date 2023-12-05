#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string			name;
		bool				isSigned;
		int const			gradeToSign;
		int const			gradeToExecute;
	public:
		AForm();
		AForm(std::string const &name, int gradeToSign, int gradeToExecute);
		AForm(AForm const &rhs);
		~AForm();

		AForm &operator=(AForm const &rhs);

		std::string			getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;

		virtual void				beSigned(Bureaucrat const &bureaucrat);
		virtual void				execute(Bureaucrat const &executor) const = 0;

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
		
		class AlreadySignedException: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

		class FormNotSignedException: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
	void requirements(Bureaucrat const &Bureaucrat) const;
};

	std::ostream &operator<<(std::ostream &o, AForm const &rhs);
	std::ostream &operator<<(std::ostream &o, AForm const *rhs);
#endif