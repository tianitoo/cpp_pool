#include "Form.hpp"

Form::Form() : name("default"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
}

Form::Form(std::string const &name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form::Form(Form const &rhs) : name(rhs.name), isSigned(rhs.isSigned), gradeToSign(rhs.gradeToSign), gradeToExecute(rhs.gradeToExecute)
{
}

Form::~Form()
{
}

Form &Form::operator=(Form const &rhs)
{
    if (this != &rhs)
        this->isSigned = rhs.isSigned;
    return (*this);
}

std::string Form::getName() const
{
    return (this->name);
}

bool Form::getIsSigned() const
{
    return (this->isSigned);
}

int Form::getGradeToSign() const
{
    return (this->gradeToSign);
}

int Form::getGradeToExecute() const
{
    return (this->gradeToExecute);
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
    if (bureaucrat.getGrade() <= this->gradeToSign)
        this->isSigned = true;
    bureaucrat.signForm(this->isSigned, this->name);
    if (!this->isSigned)
        throw Form::GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}

std::ostream &operator<<(std::ostream &o, Form const &rhs)
{
    o << rhs.getName() << ", form is ";
    if (rhs.getIsSigned())
        o << "signed";
    else
        o << "not signed";
    o << ", grade to sign is " << rhs.getGradeToSign() << ", grade to execute is " << rhs.getGradeToExecute();
    return (o);
}

std::ostream &operator<<(std::ostream &o, Form const *rhs)
{
    o << rhs->getName() << ", form is ";
    if (rhs->getIsSigned())
        o << "signed";
    else
        o << "not signed";
    o << ", grade to sign is " << rhs->getGradeToSign() << ", grade to execute is " << rhs->getGradeToExecute();
    return (o);
}