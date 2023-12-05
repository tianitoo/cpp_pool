#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src), target(src.target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
    if (this != &rhs)
        this->target = rhs.target;
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    this->requirements(executor);
    std::ofstream ofs(this->target + "_shrubbery");
    if (ofs.is_open())
    {
        ofs << "      /\\\n";
        ofs << "     /\\*\\\n";
        ofs << "    /\\O\\*\\\n";
        ofs << "   /*/\\/\\/\\\n";
        ofs << "  /\\O\\/\\*\\/\\\n";
        ofs << " /\\*\\/\\*\\/\\/\\\n";
        ofs << "/\\O\\/\\/*/\\/O/\\\n";
        ofs << "      ||\n";
        ofs << "      ||\n";
        ofs << "      ||\n";
        ofs << "    \\====/\n";
        ofs << "     \\__/\n";
        ofs.close();
    }
    else
        throw FileNotOpenedException();
}

std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm const &rhs)
{
    o << rhs.getName() << " is ";
    if (!rhs.getIsSigned())
        o << "not ";
    o << "signed, requires grade " << rhs.getGradeToSign() << " to sign, requires grade " << rhs.getGradeToExecute() << " to execute, and has target " << rhs.getTarget();
    return (o);
}

std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm const *rhs)
{
    o << rhs->getName() << " is ";
    if (!rhs->getIsSigned())
        o << "not ";
    o << "signed, requires grade " << rhs->getGradeToSign() << " to sign, requires grade " << rhs->getGradeToExecute() << " to execute, and has target " << rhs->getTarget();
    return (o);
}

std::string ShrubberyCreationForm::getTarget() const
{
    return (this->target);
}

void ShrubberyCreationForm::setTarget(std::string const &target)
{
    this->target = target;
}

const char *ShrubberyCreationForm::FormNotSignedException::what() const throw()
{
    return ("Error: form not signed");
}

const char *ShrubberyCreationForm::FileNotOpenedException::what() const throw()
{
    return ("Error: could not open file");
}