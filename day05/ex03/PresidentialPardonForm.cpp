#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("default")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm(src), target(src.target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
    if (this != &rhs)
        this->target = rhs.target;
    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    this->requirements(executor);
    executor.executeForm(*this);
    std::cout << this->target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

std::string PresidentialPardonForm::getTarget() const
{
    return (this->target);
}

void PresidentialPardonForm::setTarget(std::string const &target)
{
    this->target = target;
}

const char *PresidentialPardonForm::FormNotSignedException::what() const throw()
{
    return ("Error: form not signed");
}

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm const &rhs)
{
    o << rhs.getName() << " form, grade required to sign: " << rhs.getGradeToSign() << ", grade required to execute: " << rhs.getGradeToExecute() << ", is signed: " << rhs.getIsSigned() << ", target: " << rhs.getTarget();
    return (o);
}

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm const *rhs)
{
    o << rhs->getName() << " form, grade required to sign: " << rhs->getGradeToSign() << ", grade required to execute: " << rhs->getGradeToExecute() << ", is signed: " << rhs->getIsSigned() << ", target: " << rhs->getTarget();
    return (o);
}