#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src), target(src.target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
    if (this != &rhs)
        this->target = rhs.target;
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    this->requirements(executor);
    std::cout << "* drilling noises *" << std::endl;
    if (rand() % 2)
        std::cout << this->target << " has been robotomized successfully" << std::endl;
    else
        std::cout << this->target << " has failed to be robotomized" << std::endl;
}

const char *RobotomyRequestForm::FormNotSignedException::what() const throw()
{
    return ("Error: form not signed");
}

std::string RobotomyRequestForm::getTarget() const
{
    return (this->target);
}

void RobotomyRequestForm::setTarget(std::string const &target)
{
    this->target = target;
}

std::ostream &operator<<(std::ostream &o, RobotomyRequestForm const &rhs)
{
    o << rhs.getName() << " form, grade required to sign: " << rhs.getGradeToSign() << ", grade required to execute: " << rhs.getGradeToExecute() << ", is signed: " << rhs.getIsSigned() << ", target: " << rhs.getTarget();
    return (o);
}

std::ostream &operator<<(std::ostream &o, RobotomyRequestForm const *rhs)
{
    o << rhs->getName() << " form, grade required to sign: " << rhs->getGradeToSign() << ", grade required to execute: " << rhs->getGradeToExecute() << ", is signed: " << rhs->getIsSigned() << ", target: " << rhs->getTarget();
    return (o);
}
