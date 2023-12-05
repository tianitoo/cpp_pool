#include "AForm.hpp"

AForm::AForm() : name("default"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
}

AForm::AForm(std::string const &name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const &rhs) : name(rhs.name), isSigned(rhs.isSigned), gradeToSign(rhs.gradeToSign), gradeToExecute(rhs.gradeToExecute)
{
}

AForm::~AForm()
{
}

AForm &AForm::operator=(AForm const &rhs)
{
    if (this != &rhs)
        this->isSigned = rhs.isSigned;
    return (*this);
}

std::string AForm::getName() const
{
    return (this->name);
}

bool AForm::getIsSigned() const
{
    return (this->isSigned);
}

int AForm::getGradeToSign() const
{
    return (this->gradeToSign);
}

int AForm::getGradeToExecute() const
{
    return (this->gradeToExecute);
}

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
    try
    {
        if (this->isSigned)
            throw AForm::AlreadySignedException();
        if (bureaucrat.getGrade() <= this->gradeToSign)
            this->isSigned = true;
        bureaucrat.signForm(this->isSigned, this->name);
        if (!this->isSigned)
            throw AForm::GradeTooLowException();
    }
    catch (std::exception &e)
    {
        std::cout << bureaucrat.getName() << " cannot sign " << this->name << " because " << e.what() << std::endl;
    }
}



const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}

const char *AForm::AlreadySignedException::what() const throw()
{
    return ("Form already signed");
}

const char *AForm::FormNotSignedException::what() const throw()
{
    return ("Form not signed");
}

std::ostream &operator<<(std::ostream &o, AForm const &rhs)
{
    o << rhs.getName() << ", form is ";
    if (rhs.getIsSigned())
        o << "signed";
    else
        o << "not signed";
    o << ", grade to sign is " << rhs.getGradeToSign() << ", grade to execute is " << rhs.getGradeToExecute();
    return (o);
}

std::ostream &operator<<(std::ostream &o, AForm const *rhs)
{
    o << rhs->getName() << ", form is ";
    if (rhs->getIsSigned())
        o << "signed";
    else
        o << "not signed";
    o << ", grade to sign is " << rhs->getGradeToSign() << ", grade to execute is " << rhs->getGradeToExecute();
    return (o);
}

void AForm::requirements(Bureaucrat const &Bureaucrat) const
{
    if (Bureaucrat.getGrade() > this->getGradeToSign())
        throw AForm::GradeTooLowException();
    if (Bureaucrat.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    if (this->getIsSigned() == false)
        throw AForm::FormNotSignedException();
}